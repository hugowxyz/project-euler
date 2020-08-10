#include <bits/stdc++.h>
using namespace std;

bool isSame(long long i, long long r) {
	map<int, int> v;
	while (i>0) {
		v[i%10] += 1;
		i/=10;
	}
	while (r>0) {
		v[r%10] -= 1;
		r/=10;
	}
	
	for ( auto const& [key, val] : v ){
		if (val != 0) return false;
	}
	return true;
}

int main() {
	for ( long long i = 1; ; i++) {
		for ( int j = 2; j < 7; j++) {
			if (!isSame(i, i*j)) break;
			
			if ( isSame(i, i*j) && j == 6) {
				cout << i;
				return 0;
			}
		}
	}
	return 0;
}
