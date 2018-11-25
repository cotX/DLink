a.out:$(wildcard ./*.c ./*.h)
	gcc -g $^ -o $@

