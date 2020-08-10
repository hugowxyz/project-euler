#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n) {
	vector<int> v;
	
	while (n) {
		v.push_back(n%10);
		n/=10;
	}
	
	int l = 0, r = v.size()-1;
	while (l < r) {
		if ( v[l] != v[r] ) return false;
		++l; --r;
	}
	return true;
	
}

int main() {
	int ans = 0;
	for (int i=999; i>0; i--) {
		for (int j=999; j>0; j--) {
			if (isPalindrome(i * j)) {
				ans = max(ans, i * j);
			}
		}
	}
	cout << ans;
	
	return 0;
}
