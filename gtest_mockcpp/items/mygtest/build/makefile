.PHONY: clean
clean:
	rm *.o temp *.txt
result.txt: source.txt
	cp source.txt result.txt #每行命令在一个单独的shell中执行
source.txt:
	echo "this is the source" > source.txt