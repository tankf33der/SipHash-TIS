all:
	gcc *.c && ./a.out
a:
	clang -fsanitize=address,undefined *.c && ./a.out
m:
	clang -fsanitize=memory *.c && ./a.out
c:
	rm -rf *.o *.out
	
