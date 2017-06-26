package com.xgn.androidlibuvlibwebsocketsboringssl;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

import com.xgn.WebSocket;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    WebSocket mWebSocket;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mWebSocket = new WebSocket();

        $(R.id.close).setOnClickListener(this);
        $(R.id.connect).setOnClickListener(this);
        $(R.id.send).setOnClickListener(this);
        $(R.id.binary_message).setOnClickListener(this);
        $(R.id.close).setOnClickListener(this);

        if (BuildConfig.DEBUG) {
            $(R.id.connect).performClick();
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    <T extends View> T $(int resId) {
        return (T) findViewById(resId);
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        switch (id) {
            case R.id.connect: {
//                mWebSocket.init();
//                mWebSocket.connect();
                new XgnTask(new XgnTask.Job() {
                    @Override
                    public void work() {
                        mWebSocket.init();
                        mWebSocket.connect();
                    }
                }).execute();

                break;
            }
            case R.id.close: {
                mWebSocket.close();
                break;
            }
            case R.id.send: {
                mWebSocket.send("wwww");
                break;
            }
            case R.id.binary_message: {
                mWebSocket.sendData("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb".getBytes());
                break;
            }
            default: {

            }
        }
    }

    WebSocket getWebSocket() {
        if (mWebSocket == null) {
            mWebSocket = new WebSocket();
        }
        return mWebSocket;
    }
}
