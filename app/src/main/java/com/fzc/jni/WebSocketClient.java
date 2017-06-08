package com.fzc.jni;

/**
 * Created by mark on 17-6-7.
 */

public class WebSocketClient {
    static {
//        System.loadLibrary("WebSocketJni");
        System.loadLibrary("WebSocketJni");
    }

    private static WebSocketClient sInstance;

    public static WebSocketClient getInstance() {
        if (sInstance == null) {
            synchronized (WebSocketClient.class) {
                sInstance = new WebSocketClient();
            }
        }
        return sInstance;
    }

    public void connect(String uri) {

    }


    public native void connec(String uri);

}
