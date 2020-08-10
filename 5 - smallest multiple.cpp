#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
	for (int i=2; i<=sqrt(n);i++) {
		if ( n % i == 0 ) return false;
	} return true;
}
int main() {
	long c = 0;
	for (long long i=2; ; i++) {
		if (isPrime(i)) c++;
		if ( c == 10001 ) {
			cout << i;
			break;
		}
	}
	return 0;
}
