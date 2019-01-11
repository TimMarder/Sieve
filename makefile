all: sieve.o driver.o
	gcc -o primetest sieve.o driver.o -lm

sieve.o: sieve.c sieve.h
	gcc -c sieve.c

driver.o: driver.c sieve.h
	gcc -c driver.c

run:
	./primetest $(args)

clean:
	rm *.o
