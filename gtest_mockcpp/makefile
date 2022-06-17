.PHONY : clean mk_dir install all
clean:
	rm -rf build gtest
mk_dir:
	if [ ! -d build ]; then mkdir build; fi
install:
	cd build && cmake .. && make all
all:	clean mk_dir install