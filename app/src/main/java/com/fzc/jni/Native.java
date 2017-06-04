package com.fzc.jni;

/**
 * Created by fanzhengchen on 6/4/17.
 */

public class Native {

    static {
        System.loadLibrary("main");
    }
    public static native String onLoad();
}
