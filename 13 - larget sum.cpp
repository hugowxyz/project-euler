#include <bits/stdc++.h>
#include <fstream>
using namespace std;

string addTwo(string s0, string s1) {
	string toReturn = "", toAdd = "";
	int carry = 0, loop = max(s0.size(), s1.size());
	while ( s0.size() > s1.size() ) {
		s1.insert(0, "0");
	}
	while ( s0.size() < s1.size() ) {
		s0.insert(0, "0");
	}
	for (int i = loop-1; i>=0; i--) {
		char d0, d1;
		d0 = s0.at(i);
		d1 = s1.at(i);

		//cout << d0 << " + " << d1 << "\n";
		
		int s = (int)(d0 - '0') + (int)(d1 - '0');
		s += carry;
		if ( s >= 10 ) {
			carry = 1;
			s = s % 10;
		} else {
			carry = 0;
		}
		char t = s+'0';
		toReturn += t;
	}
	if ( carry == 1 ) {
		toReturn += '1';
	}
	reverse(toReturn.begin(), toReturn.end());
	//cout << toReturn << "\n";
	return toReturn;
	
}

int main() {
	string answer, temp;
	ifstream inFile;
	inFile.open("13.txt");
	vector<string> v;
	
	while ( getline(inFile, temp) ) {
		v.push_back(temp);
	}
	
	answer = v[0];
	
	for (size_t i = 1; i<v.size(); i++) {
		answer = addTwo(answer, v[i]);
	}
	
	cout << answer << "\n";
	
	for ( int i=0; i<10; i++ ) {
		cout << answer[i];
	}
	return 0;
}
