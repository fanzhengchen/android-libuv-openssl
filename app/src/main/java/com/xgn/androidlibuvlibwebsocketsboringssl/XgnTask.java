package com.xgn.androidlibuvlibwebsocketsboringssl;

import android.os.AsyncTask;

import com.xgn.WebSocket;

/**
 * Created by mark on 6/26/17.
 */

public class XgnTask extends AsyncTask<WebSocket,Void,Void> {

    interface Job{
        void work();
    }

    Job mJob;
    public XgnTask(Job job){
        mJob = job;
    }


    @Override
    protected Void doInBackground(WebSocket... params) {

        mJob.work();
        return null;
    }
}
