package com.xgn.nettyClient;

import java.net.InetSocketAddress;

import io.netty.bootstrap.Bootstrap;
import io.netty.channel.EventLoopGroup;
import io.netty.channel.nio.NioEventLoopGroup;

/**
 * Created by mark on 7/6/17.
 */

public class WebSocketClient {


    public WebSocketClient() {

    }


    public void connect() {

        InetSocketAddress inetSocketAddress = new InetSocketAddress("172.16.11.164", 20000);
        EventLoopGroup group = new NioEventLoopGroup();
        Bootstrap bootstrap = new Bootstrap();
        bootstrap.group(group)
                .connect();
    }
}
