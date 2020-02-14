# android_bionic_dns
android dns query, use bionic libc

# bionic

[aosp platform_bionic](https://github.com/aosp-mirror/platform_bionic)

# Android Environment

[Intalling Android Studio on Archlinux](https://qiita.com/roberbnd/items/e205747cbf96bd65ee11)

[android ndk](https://developer.android.com/ndk/index.html)

    export ANDROID_HOME=/opt/android-sdk
    export ANDROID_SDK_ROOT=$ANDROID_HOME
    export ANDROID_NDK_ROOT=/opt/android-ndk
    export PATH=$ANDROID_NDK_ROOT:$ANDROID_HOME/tools:$ANDROID_HOME/tools/bin:$ANDROID_HOME/platform-tools:$PATH

# build ndk project

[Building an Android Command-Line Application Using the NDK Build Tools](https://software.intel.com/en-us/articles/building-an-android-command-line-application-using-the-ndk-build-tools)

    $ cd ns_dom_qtype
    $ export NDK_PROJECT_PATH=.
    $ ndk-build NDK_APPLICATION_MK=./Application.mk
    [arm64-v8a] Install        : ns_dom_qtype.out => libs/arm64-v8a/ns_dom_qtype.out

# tcpdump

[android tcpdump](https://www.androidtcpdump.com/android-tcpdump/)

    $ adb shell "mkdir /data/abbypan"
    $ adb push tcpdump /data/abbypan
    $ adb shell
    # tcpdump port 53 -w v_qq_com.cap

# test
    
    $ cd ns_dom_qtype

    $ adb push libs/arm64-v8a/ns_dom_qtype.out /data/abbypan
    libs/arm64-v8a/ns_dom_qtype.out: 1 file pushed. 1.2 MB/s (10152 bytes in 0.008s)

    $ adb shell "./data/abbypan/ns_dom_qtype.out 202.38.64.1 v.qq.com a"
    query v.qq.com, name_server 202.38.64.1, qtype a
    v.qq.com.       10M IN CNAME    v.tc.qq.com.
    v.tc.qq.com.        10M IN CNAME    v.tcdn.qq.com.
    v.tcdn.qq.com.      10M IN CNAME    ssdv6mid.tcdn.qq.com.
    ssdv6mid.tcdn.qq.com.   10M IN CNAME    ssdv6.tcdn.qq.com.
    ssdv6.tcdn.qq.com.  10M IN A    183.60.137.250
    ssdv6.tcdn.qq.com.  10M IN A    14.215.85.12
    ssdv6.tcdn.qq.com.  10M IN A    113.96.156.217
    ssdv6.tcdn.qq.com.  10M IN A    183.60.137.173
    ssdv6.tcdn.qq.com.  10M IN A    14.215.85.11
    ssdv6.tcdn.qq.com.  10M IN A    119.147.227.20
    ssdv6.tcdn.qq.com.  10M IN A    113.96.83.67
    ssdv6.tcdn.qq.com.  10M IN A    125.94.49.78
    ssdv6.tcdn.qq.com.  10M IN A    119.147.227.85
    ssdv6.tcdn.qq.com.  10M IN A    14.215.85.14
    ssdv6.tcdn.qq.com.  10M IN A    14.215.85.13
    ssdv6.tcdn.qq.com.  10M IN A    119.147.227.112

    $ adb shell "./data/abbypan/ns_dom_qtype.out 202.38.64.1 v.qq.com aaaa"
    query v.qq.com, name_server 202.38.64.1, qtype aaaa
    v.qq.com.       10M IN CNAME    v.tc.qq.com.
    v.tc.qq.com.        10M IN CNAME    v.tcdn.qq.com.
    v.tcdn.qq.com.      10M IN CNAME    ssdv6mid.tcdn.qq.com.
    ssdv6mid.tcdn.qq.com.   10M IN CNAME    ssdv6.tcdn.qq.com.
    ssdv6.tcdn.qq.com.  10M IN AAAA 240e:97d:2010:101:23::
    ssdv6.tcdn.qq.com.  10M IN AAAA 240e:ff:9018:103:39::
    ssdv6.tcdn.qq.com.  10M IN AAAA 240e:ff:9018:103:3a::
    ssdv6.tcdn.qq.com.  10M IN AAAA 240e:ff:9018:103:38::
    ssdv6.tcdn.qq.com.  10M IN AAAA 240e:97d:5000:110:19::
    ssdv6.tcdn.qq.com.  10M IN AAAA 240e:97f:3000:a02:2a::
    ssdv6.tcdn.qq.com.  10M IN AAAA 240e:97f:3000:a02:25::
    ssdv6.tcdn.qq.com.  10M IN AAAA 240e:97f:3000:a02:24::
