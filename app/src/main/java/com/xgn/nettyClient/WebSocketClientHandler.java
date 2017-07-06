package com.xgn.nettyClient;

import java.net.URI;

import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelPromise;
import io.netty.channel.SimpleChannelInboundHandler;
import io.netty.handler.codec.http.DefaultHttpHeaders;
import io.netty.handler.codec.http.FullHttpResponse;
import io.netty.handler.codec.http.websocketx.BinaryWebSocketFrame;
import io.netty.handler.codec.http.websocketx.CloseWebSocketFrame;
import io.netty.handler.codec.http.websocketx.ContinuationWebSocketFrame;
import io.netty.handler.codec.http.websocketx.PingWebSocketFrame;
import io.netty.handler.codec.http.websocketx.PongWebSocketFrame;
import io.netty.handler.codec.http.websocketx.TextWebSocketFrame;
import io.netty.handler.codec.http.websocketx.WebSocketClientHandshaker;
import io.netty.handler.codec.http.websocketx.WebSocketClientHandshaker13;
import io.netty.handler.codec.http.websocketx.WebSocketClientHandshakerFactory;
import io.netty.handler.codec.http.websocketx.WebSocketFrame;
import io.netty.handler.codec.http.websocketx.WebSocketVersion;

/**
 * Created by mark on 7/6/17.
 */

public class WebSocketClientHandler extends SimpleChannelInboundHandler<Object> {

    private static final String EXTENSION = "dump-increment-protocol";
    private static final int PAYLOAD_LENGTH = 1 << 16;

    WebSocketClientHandshaker mHandshaker;
    ChannelPromise mChannelPromise;


    public WebSocketClientHandler(URI uri) {
        mHandshaker = new WebSocketClientHandshaker13(uri,
                WebSocketVersion.V13, EXTENSION, true, new DefaultHttpHeaders(), PAYLOAD_LENGTH);
    }

    @Override
    protected void channelRead0(ChannelHandlerContext ctx, Object msg) throws Exception {
        if (!mHandshaker.isHandshakeComplete()) {
            mHandshaker.finishHandshake(ctx.channel(), (FullHttpResponse) msg);
            mChannelPromise.setSuccess();
        }

        if (msg instanceof WebSocketFrame) {
            handleFrame(ctx, (WebSocketFrame) msg);
        }
    }

    void handleFrame(ChannelHandlerContext ctx, WebSocketFrame frame) {
        if (frame instanceof PingWebSocketFrame) {

        } else if (frame instanceof PongWebSocketFrame) {

        } else if (frame instanceof TextWebSocketFrame) {

        } else if (frame instanceof BinaryWebSocketFrame) {

        } else if (frame instanceof CloseWebSocketFrame) {

        } else if (frame instanceof ContinuationWebSocketFrame) {

        }
    }


}
