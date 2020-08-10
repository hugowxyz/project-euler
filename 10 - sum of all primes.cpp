#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
	for (int i=2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	vector<int> v = {2, 3};
	for (long long i=4; i<2000000; i++) {
		if (isPrime(i)) v.push_back(i); 
	}
	
	long long ans = 0;
	for ( int i : v ) ans += i;
	cout << ans;
	return 0;
}
