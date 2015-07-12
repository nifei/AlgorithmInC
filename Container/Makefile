testlist : testlist.o List.o
	gcc -o testlist testlist.o List.o
testlist.o: testlist.c
	gcc -c testlist.c
List.o: List.c
	gcc -c List.c
clean:
	rm *.o 
	rm testlist
