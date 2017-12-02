#include <Helper.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

/* Does power of two using bitshift, faster than pow */
int power2(int n){
	return n > 0 ? (2<<(n-1)) : 1; /* Ternary if, n > 0 return 2^n-1 else 1 */
}

/* Return a random integer in the interval of [0,n) */
int randomInt(int n){
	return (int) rand() % n;
}