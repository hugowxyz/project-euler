#include <bits/stdc++.h>
using namespace std;
 
int getC(string s) {
	int count = 0;
	for (auto i : s) {
		count++;
	} 
	return count;
}

int getFirstDigit(int i) {
	while (i > 10) i /= 10;
	return i;
}

int getLastDigit(int i) {
	return i % 10;
}

int main() {
	map<int, string> m;
	int ans = 0;
	m[1] = "one";
	m[2] = "two";
	m[3] = "three";
	m[4] = "four";
	m[5] = "five";
	m[6] = "six";
	m[7] = "seven";
	m[8] = "eight";
	m[9] = "nine";
	m[10] = "ten";
	m[11] = "eleven";
	m[12] = "twelve";
	m[13] = "thirteen";
	m[14] = "fourteen";
	m[15] = "fifteen";
	m[16] = "sixteen";
	m[17] = "seventeen";
	m[18] = "eighteen";
	m[19] = "nineteen";
	m[20] = "twenty";
	m[30] = "thirty";
	m[40] = "forty";
	m[50] = "fifty";
	
	for (int i=20; i<100; i++) {
		if ( i <= 20 ) { 
			ans += getC(m[i]);
			cout << m[i] << "\n";
		}
		else if ( i > 20 && i < 61) {
			if ( i % 10 == 0 ) {
				cout << m[i] << "\n";
				ans += getC(m[i]);
			} else {
				int t0 = getFirstDigit(i) * 10;
				int t1 = getLastDigit(i);
				string ts = m[t0] + m[t1];
				cout << ts << "\n";
				ans += getC(ts);
			}
			
		} else if ( i > 59 && i < 100 ) {
			int t0 = getFirstDigit(i);
			string s0;
			if ( i >= 80 && i <= 89 ) s0 = m[t0] + "y";
			else s0 = m[t0] + "ty";
			if ( i % 10 == 0 ) {
				cout << s0 << "\n";
				ans += getC(s0);
			} else {
				int t1 = getLastDigit(i);
				s0 += m[t1];
				cout << s0 << "\n";
				ans += getC(s0);
			}
		}
	
	}
	
	cout << ans << "\n";
	int temp = 0;
	for ( int i = 1; i <= 9; i++) {
		string s0 = m[i] + "hundredand";
		temp += getC(s0);
		cout << s0 << "\n";
		//cout << getC(m[i]) << "\n";
	}
	cout << temp;
	
	return 0;
}
