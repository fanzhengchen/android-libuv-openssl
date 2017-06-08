package com.fzc.jni;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Example local unit test, which will execute on the development machine (host).
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() throws Exception {
        assertEquals(4, 2 + 2);
    }

    @Test
    public void fuck()throws Exception{
        //language=RegExp
        String regex = "^(?=.*[a-zA-Z])(?=.*[0-9])[a-zA-Z0-9]*";
    }
}