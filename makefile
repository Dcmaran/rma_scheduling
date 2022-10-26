CC = gcc

objects = main.o functions.o

output: $(objects)
	$(CC) -o rate main.o functions.o

main.o: functions.h

functions.o: functions.h

.PHONY: clean
clean:
	rm $(objects) rate