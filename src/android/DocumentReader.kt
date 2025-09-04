package com.regula.plugin.documentreader

import android.app.Activity
import android.content.Context
import android.content.Intent
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import androidx.lifecycle.Lifecycle
import org.apache.cordova.CallbackContext
import org.apache.cordova.CordovaPlugin
import org.apache.cordova.PluginResult
import org.json.JSONArray

val eventCallbackIds = mutableMapOf<String, String>()
lateinit var callbackContext: CallbackContext

lateinit var args: JSONArray
lateinit var binding: CordovaPlugin
val context: Context
    get() = binding.cordova.context
val activity: Activity
    get() = binding.cordova.activity
val lifecycle: Lifecycle
    get() = (activity as AppCompatActivity).lifecycle

fun sendEvent(event: String, data: Any? = "") {
    // These events are not working in cordova and ionic because they don't have a method
    // associated with it. Callbacks are set automatically right after init.
    val skippedEvents = listOf(videoEncoderCompletionEvent, onCustomButtonTappedEvent)
    if (skippedEvents.contains(event)) return
    val pluginResult = when (data) {
        is Boolean -> PluginResult(PluginResult.Status.OK, data)
        is Int -> PluginResult(PluginResult.Status.OK, data)
        else -> {
            var result = data.toSendable() as String?
            // Allows user to determine which event fired when there are more
            // than one event associated with the function
            val singleEvents = listOf(databaseProgressEvent, completionEvent, "")
            if (!singleEvents.contains(event)) result = event + result
            PluginResult(PluginResult.Status.OK, result)
        }
    }
    pluginResult.keepCallback = true
    callbackContext.sendPluginResult(pluginResult)
}

@Suppress("UNCHECKED_CAST")
fun <T> argsNullable(index: Int): T? = if (args.get(index).toString() != "null") {
    args.get(index) as T
} else null

fun requestPermissions(@Suppress("UNUSED_PARAMETER") activity: Activity, permissions: Array<String>, requestCode: Int) = binding.cordova.requestPermissions(binding, requestCode, permissions)
fun startActivityForResult(@Suppress("UNUSED_PARAMETER") activity: Activity, intent: Intent, requestCode: Int) = binding.cordova.startActivityForResult(binding, intent, requestCode)
fun myOnRequestPermissionsResult(requestCode: Int, permissions: Array<String>, grantResults: IntArray) = onRequestPermissionsResult(requestCode, permissions, grantResults)
fun myOnActivityResult(requestCode: Int, resultCode: Int, intent: Intent?) = onActivityResult(requestCode, resultCode, intent)

class DocumentReader : CordovaPlugin() {
    init {
        binding = this
    }

    override fun onNewIntent(intent: Intent) {
        newIntent(intent)
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, intent: Intent?) {
        myOnActivityResult(requestCode, resultCode, intent)
    }

    @Suppress("OVERRIDE_DEPRECATION")
    override fun onRequestPermissionResult(requestCode: Int, permissions: Array<String>, grantResults: IntArray) {
        myOnRequestPermissionsResult(requestCode, permissions, grantResults)
    }

    override fun execute(action: String, arguments: JSONArray, cb: CallbackContext): Boolean {
        callbackContext = cb
        args = arguments
        val method = args.remove(0) as String
        if (method == "setEvent") eventCallbackIds[args(0)] = callbackContext.callbackId
        try {
            methodCall(method) { data: Any? -> sendEvent("", data) }
        } catch (error: Exception) {
            Log.e("REGULA", "Caught exception in \"$method\" function:", error)
        }
        return true
    }
}
