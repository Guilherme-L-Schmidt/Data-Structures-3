CC= gcc
CFLAGS= -Wall -g
TARGET= main

all :
	$(CC) $(CFLAGS) *.c src/*.c -I include -o $(TARGET)

run :
	./$(TARGET)

valin :
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(TARGET) < in/7.in

valout :
	valgrind --leak-check=full --show-leak-kinds=all -s ./$(TARGET) > test.out

# pode trocar os numeros para diferentes testes
test :
	for number in `seq 1 10` ; do \
	./$(TARGET) < in/$$number.in > out2/$$number.out2; \
	diff -s out/$$number.out out2/$$number.out2; \
	done

hex :
	hexdump -Cv tec.bin

dif :
	diff TestCases/3.out TestCases/3.out2