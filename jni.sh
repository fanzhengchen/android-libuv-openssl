#!/bin/sh

out="a.h"
jni -o ./app/src/main/cpp/$out -classpath ./app/build/intermediates/
