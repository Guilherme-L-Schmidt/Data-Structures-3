CC= gcc
CFLAGS= -Wall -g -I.
TARGET= main

all :
	$(CC) $(CFLAGS) *.c src/*.c -I include -o $(TARGET)

run :
	./$(TARGET)

valin :
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(TARGET) < TestCases/5.in

valout :
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(TARGET) > test.out

# pode trocar os numeros para diferentes testes
test :
	for number in `seq 1 10` ; do \
	./$(TARGET) < TestCases/$$number.in > TestCases/$$number.out2; \
	diff -s TestCases/$$number.out TestCases/$$number.out2; \
	done

hex :
	hexdump -Cv tec.bin

dif :
	diff TestCases/3.out TestCases/3.out2