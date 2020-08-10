#include <stdio.h>

int isPalindrome(int n) {
	int digits[4];
	int r;
	for ( int i=0; i<4; i++) {
		r = n % 10;
		n /= 10;
		digits[i] = r;
	}
	
	for (int i=0; i<4; i++) {
		printf("%d", digits[i]);
	}
	
	return 0;
}

int main() {
	isPalindrome(51);
	return 0;
}
