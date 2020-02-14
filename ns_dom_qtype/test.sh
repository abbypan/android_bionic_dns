#!/bin/bash
export NDK_PROJECT_PATH=.
ndk-build NDK_APPLICATION_MK=./Application.mk

adb shell "mkdir /data/abbypan"
adb push libs/arm64-v8a/ns_dom_qtype.out /data/abbypan

echo $1
adb shell "./data/abbypan/ns_dom_qtype.out 202.38.64.1 $1 a"
adb shell "./data/abbypan/ns_dom_qtype.out 202.38.64.1 $1 aaaa"
adb shell "./data/abbypan/ns_dom_qtype.out 8.8.8.8 $1 a"
adb shell "./data/abbypan/ns_dom_qtype.out 8.8.8.8 $1 aaaa"
adb shell "./data/abbypan/ns_dom_qtype.out 114.114.114.114 $1 a"
adb shell "./data/abbypan/ns_dom_qtype.out 114.114.114.114 $1 aaaa"
