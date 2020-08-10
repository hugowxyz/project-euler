#include <stdio.h>

int main() {
	long a = 1, b = 1, s = 0, c;
	while ( b < 4000000 ) {
		c = b;
		b += a;
		a = c;
		
		if ( b % 2 == 0 ) {
			s += b;
		}
	}
	
	printf("Answer %ld", s);
}
