#!/bin/sh

out="a.h"
target="WebSocket"
javah -o ./app/src/main/cpp/$out \
    -classpath ./app/build/intermediates/classes/debug \
    com.xgn.$target

