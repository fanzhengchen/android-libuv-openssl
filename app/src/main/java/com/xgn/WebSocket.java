package com.xgn;

/**
 * Created by fanzhengchen on 6/23/17.
 */

/**
 * XGN custum websocket based libwebsockets
 */
public class WebSocket {

    public native void init();

    public native void connect();

    public native void send(String message);

    public native void close();
}
