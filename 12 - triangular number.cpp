#include <bits/stdc++.h>
using namespace std;

int pFactorise(int t) {
	map<int, int> m;
	int i = 2;
	while ( t > 1 ) {
		if ( t % i == 0 ) {
			t /= i;
			m[i]++;
		} else i++;
	}
	
	int r = 1;
	for ( auto const& p : m ) {
		r *= p.second + 1;
	}
	return r;
}

int main() {
	int i = 7, t = 0;
	while (true) {
		t = i * (i+1);
		t /= 2;
		if (pFactorise(t) > 500) {
			cout << t;
			break;
		} 
		i++;
	}
	
	return 0;
}
