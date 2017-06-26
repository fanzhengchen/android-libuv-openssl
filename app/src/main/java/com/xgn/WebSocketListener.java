package com.xgn;

/**
 * Created by mark on 6/26/17.
 */

public interface WebSocketListener {

    void onText(String text);

    void onData(byte[] data);

    void onConnected();

    void onDisconnected();

    void onClose();

}
