#include <bits/stdc++.h>
using namespace std;

unsigned long long f(int x, int b=1) {
	if ( x == 0 || x == 1 ) return 1;
	long long r = 1;
	for ( int i = b+1; i <= x; i++ ) {
		r *= i;
	}
	return r;
}

unsigned long long form(int n, int r) {
	return f(n, n-r)/f(r);
}

void test() {
	int ans = 0;
	for (int n=1; n<=100; n++) {
		for (int r=0; r<=n; r++) {
			//cout << r << " ";
			if ( form(n, r) > pow(10, 6) ) {
				//cout << n << " " << r << "\n";
				ans += (n + 2 - 2 * r);
				break;
			}
		}
		//cout << "\n" << n << "\n";
	}
	cout << ans;
}

int main() {
	int ans = 0;
	for (int n=1; n<=100; n++) {
		for (int r=0; r<=n; r++) {
			//cout << r << " ";
			if ( form(n, r) > pow(10, 6) ) {
				//cout << n << " " << r << "\n";
				ans += (n + 1 - 2 * r);
				break;
			}
		}
		//cout << "\n" << n << "\n";
	}
	cout << ans;
}
