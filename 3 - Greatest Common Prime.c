#include <stdio.h>

int main() {
	long n = 600851475143, c = 2;
	while ( n > 1 ) {
		if ( n % c == 0 ) 
			n /= c;
		else 
			c++;
	}
	// outputs 6857
	printf("%ld", c);
}
