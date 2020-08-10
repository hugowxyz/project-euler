#include <bits/stdc++.h>
using namespace std;

int main() {
	int sum = 0;
	int a = 8;
	int b = 15;
	int c = 17;
	
	for (int i=2; i>0; i++) {
		sum = i * a + i * b + i * c;
		if (sum == 1000) {
			cout << i * a <<  " " << i * b << " " << i * c << "\n";
		} else if (sum > 1000) break;
	}
	
	
	return 0;
}
