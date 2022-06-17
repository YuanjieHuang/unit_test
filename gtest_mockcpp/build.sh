#!/bin/bash
function green_echo () {
        local what=$*
        echo -e "\033[1;32m${what} \033[0m"
}
yellow_echo(){
        printf '\033[1;33;40m%b\033[0m\n' "$1";#%b 是开启转义，后面输出字符串中若含有转义字符会进行转义。
}
red_echo(){
        printf '\033[1;31;40m%b\033[0m\n' "$1";
        exit 1;
}

# set -v on #打开回显
CUR_DIR=$(cd $(dirname $0); pwd)
BUILD=$CUR_DIR/build
BIN=${CUR_DIR}/gtest
rm -rf $BUILD $BIN
if [ ! -z $1 ];then exit 1; fi;
green_echo CUR_DIR:$CUR_DIR
green_echo BUILD:$BUILD
green_echo BIN:$BIN

yellow_echo $CUR_DIR/$(basename $0)
cur_path=$(dirname $0)
echo "cur_path:$cur_path"

if [ ! -d $BUILD ]; then mkdir $BUILD; fi
cd  $BUILD && cmake .. && make all #&& $(CUR_DIR)/bin/firstGtest