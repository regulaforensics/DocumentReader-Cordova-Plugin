#if canImport(Cordova)
import Cordova
#endif
import UIKit

private weak var plugin: RGLWDocumentReader?

@objc(RGLWDocumentReader)
class RGLWDocumentReader: CDVPlugin {
    fileprivate var databaseCallbackId: String?
    fileprivate var readingCallbackId: String?

    @objc(exec:)
    func exec(_ command: CDVInvokedUrlCommand) {
        plugin = self
        let action = command.arguments.first as! String
        args = legacyArguments(for: action, Array(command.arguments.dropFirst()))
        switch action {
        case "prepareDatabase", "runAutoUpdate": databaseCallbackId = command.callbackId
        case "scan", "startScanner", "recognize", "readRFID", "startRFIDReader": readingCallbackId = command.callbackId
        default: break
        }

        methodCall(action) { data in
            DispatchQueue.main.async {
                self.send(data, callbackId: command.callbackId, keepCallback: false)
            }
        }
    }

    fileprivate func send(_ data: Any?, callbackId: String?, keepCallback: Bool) {
        guard let callbackId else { return }
        let result: CDVPluginResult?
        switch data.toSendable() {
        case let value as String: result = CDVPluginResult(status: .ok, messageAs: value)
        case let value as NSNumber where CFGetTypeID(value) == CFBooleanGetTypeID(): result = CDVPluginResult(status: .ok, messageAs: value.boolValue)
        case let value as NSNumber: result = CDVPluginResult(status: .ok, messageAs: value.doubleValue)
        default: result = CDVPluginResult(status: .ok)
        }
        guard let result else { return }
        result.setKeepCallbackAs(keepCallback)
        commandDelegate.send(result, callbackId: callbackId)
    }
}

func sendEvent(_ event: String, _ data: Any? = nil) {
    DispatchQueue.main.async {
        guard let plugin else { return }
        switch event {
        case videoEncoderCompletionEvent, onCustomButtonTappedEvent: return
        case databaseProgressEvent: plugin.send(data, callbackId: plugin.databaseCallbackId, keepCallback: true)
        case completionEvent: plugin.send(data, callbackId: plugin.readingCallbackId, keepCallback: true)
        default: plugin.send(event + String(describing: data.toSendable()), callbackId: plugin.readingCallbackId, keepCallback: true)
        }
    }
}

func withPresenter(_ action: @escaping (UIViewController) -> Void) {
    DispatchQueue.main.async {
        let windows = UIApplication.shared.connectedScenes.compactMap { $0 as? UIWindowScene }.filter { $0.activationState == .foregroundActive || $0.activationState == .foregroundInactive }.flatMap { $0.windows }
        let candidates = windows.filter { $0.isKeyWindow } + windows.filter { !$0.isKeyWindow && !$0.isHidden && $0.alpha > 0 && $0.windowLevel == .normal }
        for window in candidates {
            guard var presenter = window.rootViewController else { continue }
            while let next = presenter.presentedViewController
                ?? (presenter as? UINavigationController)?.visibleViewController
                ?? (presenter as? UINavigationController)?.topViewController
                ?? (presenter as? UITabBarController)?.selectedViewController {
                presenter = next
            }
            guard presenter.viewIfLoaded?.window != nil else { continue }
            action(presenter)
            return
        }
        print("REGULA: Cannot present the UI: no presenter available.")
    }
}

private func legacyArguments(for action: String, _ values: [Any]) -> [Any] {
    switch action {
    case "readRFID", "startRFIDReader": return [values.first as? [String: Any] ?? [:]]
    case "startRetrieveData", "retrieveDataBLE": return [values[1], values[0]]
    case "getTranslation": if values[0] as? String == "RFIDErrorCodes", let code = values[1] as? NSNumber { return [values[0], Int(code.uint32Value)] }
    default: break
    }
    return values
}
