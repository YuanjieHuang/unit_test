# 下载最新的release 并保存为 googletest-1.8.1.tar.gz
wget -O googletest-1.8.1.tar.gz https://github.com/google/googletest/archive/release-1.8.1.tar.gz
# 解压
tar -zxf googletest-1.8.1.tar.gz
# 进入解压后的目录
cd googletest-release-1.8.1
# 为编译创建一个目录
mkdir build && cd build
cmake ..
make
# 安装
make install
