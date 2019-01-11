#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

int sieve( int targetPrime ) {

    int len = (int) (log( targetPrime ) * targetPrime * 1.15);
    int * primes = malloc( sizeof(int) * len );

    for (int i = 2 ; i < len ; i++) {
        primes[i] = 1;
    }

    int ctr = 0;
    for (int i = 2 ; i < len ; i++) {
        if ( primes[i] ) {
            for (int j = i * 2 ; j < len ; j += i) {
                primes[j] = 0;
            }
            ctr++;
        }
        if ( ctr == targetPrime ) {
            return i;
        }
    }
    free(primes);
    return 0;

}
