target:driver2.o heap.o
	gcc driver2.o heap.o -o final.exe

driver2.o: driver2.c
	gcc -c driver2.c

heap.o: heap.c
	gcc -c heap.c

remove: 
	rm *.exe *.o