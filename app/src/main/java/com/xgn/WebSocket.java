package com.xgn;

/**
 * Created by fanzhengchen on 6/23/17.
 */

import android.os.Looper;

import com.orhanobut.logger.Logger;

/**
 * XGN custum websocket based libwebsockets
 */
public class WebSocket {

    WebSocketListener mWebSocketListener;

    static {
        System.loadLibrary("ws");
    }

    public native void init();

    public native void connect();

    public native void send(String message);

    public native void sendData(byte[] bytes);

    public native void close();

    public void setWebSocketListener(WebSocketListener listener) {
        mWebSocketListener = listener;
    }

    void onConnect() {
        Logger.e("on connect");
        if (mWebSocketListener != null) {
            Logger.e("11111111111111111111111111111111111111111111111d");
            mWebSocketListener.onConnected();
        }
    }

    void onReceiveText(String text) {
        if (mWebSocketListener != null) {
            mWebSocketListener.onText(text);
        }
    }

    void onReceiveData(byte[] bytes) {
        if (mWebSocketListener != null) {
            mWebSocketListener.onData(bytes);
        }
    }

    void onDisconnected() {
        if (mWebSocketListener != null) {
            mWebSocketListener.onDisconnected();
        }
    }

    void onClose() {
        if (mWebSocketListener != null) {
            mWebSocketListener.onClose();
        }
    }
}
