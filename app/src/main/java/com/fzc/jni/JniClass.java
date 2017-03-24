package com.fzc.jni;

/**
 * Created by fanzhengchen on 3/24/17.
 */

public class JniClass {

    static {
        System.loadLibrary("main");
    }

    private void printString(String text) {
        System.out.println(text);
    }

    public native String getStringFromJni();

    public native void getJavaClass();
}
