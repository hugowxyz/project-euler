#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
	for (int i=2; i<=sqrt(n); i++) {
		if ( n % i == 0 ) return false;
	}
	if ( n == 0 || n == 1 ) return false;
	return true;
}

int nthDigit(long long x, int n) {
	long long result = (x / pow(10, n));
	return result % 10;
}

// n is the number of digits	
vector< vector<int> > generateCombinations(long long x, int n) {
	vector< vector<int> > set;
	//int start = pow(2, n) - 2;
	//start /= 2;
	for (int i=1; i<=pow(2, n)-2; i++) {
		vector<int> bitRepresentation;
		for (int j=n-1; j >= 0; j--) {
			if (i&(1<<j)) bitRepresentation.push_back(nthDigit(x, j));
			else bitRepresentation.push_back(0);
		}
		set.push_back(bitRepresentation);
	}
	return set;
}

int getN(long long n) {
	int c = 0;
	while (n>0) {
		n/=10;
		c++;
	}
	return c;
}

int main() {
	//cout << nthDigit(1234, 1);
	//cout << getN(1234);
	long long n = 120383;
	vector<int> primes;
	vector< vector<int> > set = generateCombinations(n, getN(n));
	for (auto i : set) {
		int primeFamily = 0;
		for (int k=0; k<10; k++) {
			
			int number = pow(10, getN(n)-1), c = 0;
			for (auto j : i) {
				cout << j << " ";
				if ( c == 0 && j == 0 )
					number += (k-1) * pow(10, getN(n)-c-1);
				else if ( c == 0 )
					number += (j-1) * pow(10, getN(n)-c-1);
				else {
					if ( j == 0 ) number +=  k * pow(10, getN(n)-c-1);
					else number += j * pow(10, getN(n)-c-1);
				}
				c++;
			}
			
			if (isPrime(number) && getN(number) == getN(n)) {
				primeFamily++;
				primes.push_back(number);
			}
			cout << "\n" << number << "\n";
		}
		cout << "Prime family size: " << primeFamily << "\n";
	}
	
	return 0;
}
