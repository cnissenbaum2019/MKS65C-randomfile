make: randomfile.c
	gcc randomfile.c

run: a.out
	./a.out

clean: a.out RandomNumbers.txt
	rm a.out
	rm RandomNumbers.txt