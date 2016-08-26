obj := main.o stringlib.o


string: $(obj)
	gcc -Wall $(obj) -o string

main.o: main.c strlib.h
	gcc -Wall -c main.c

stringlib.o: stringlib.c strlib.h
	gcc -Wall -c stringlib.c

.PHONY: clean
clean:
	rm -f *.o
