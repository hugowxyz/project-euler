#include <bits/stdc++.h>
using namespace std;

int vals(string s) {
	map<string, int> val;
	val["1"] = 1;
	val["2"] = 2;
	val["3"] = 3;
	val["4"] = 4;
	val["5"] = 5;
	val["6"] = 6;
	val["7"] = 7;
	val["8"] = 8;
	val["9"] = 9;
	val["T"] = 10;
	val["J"] = 11;
	val["Q"] = 12;
	val["K"] = 13;
	val["A"] = 14;
	return val[s];

}

string next_card(char n) {
	if ( isdigit(n) ) {
		string t (1, n);
		if ( stoi(t) == 9 ) return "T";
		string toReturn (1, stoi(t) + 1);
		return toReturn;
	} 
	
	if ( n == 'T' ) return "J";
	else if ( n == 'J' ) return "K";
	else if ( n == 'Q' ) return "K";
	else if ( n == 'K' ) return "A";
	
	return "";
}

bool smaller(string x, string y) {
	return vals(x) < vals(y);
}

void card_sort(vector<string>& h) {
	for (unsigned int i=1; i<h.size(); i++) {
		int j = i;
		while ( smaller(string(1, h[j][0]), string(1, h[j-1][0]) ) ) {
			string temp = h[j-1];
			h[j-1] = h[j];
			h[j] = temp;
			if ( j - 1 == 0 ) break;
		}
	}
}

bool royal_flush(vector<string>& h) {
	char suite = h[0][1];
	string s(1, suite);
	map<string, int> m;
	string s0 = "A"+s;
	string s1 = "Q"+s;
	string s2 = "K"+s;
	string s3 = "J"+s;
	string s4 = "T"+s;
	m[s0] =  1;
	m[s1] =  1;
	m[s2] =  1;
	m[s3] =  1;
	m[s4] =  1;
	for ( auto i : h ) {
		if ( m[i] == 0 ) return false;
		m[i]--;
	}
	for ( auto [key, val] : m ) {
		string t = key;
		if ( val != 0 ) return false;
	}
	return true;
} 

bool straight_flush(vector<string>& h) {
	card_sort(h);
	string suite (1, h[0][1]);
	for (unsigned int i=0; i<h.size()-1; i++) {
		//if ( h[i] != string(1, next_card(h[i][0])) + suite ) return false;
		string s = next_card(h[i][0]) + suite;
		cout << s << "\n";
		if ( h[i+1] != s ) return false;
	}
	return true;
}

int main() {
	ifstream inFile;
	inFile.open("54 - poker hands.txt");
	
	string line;
	getline(inFile, line);
	cout << line << "\n";
	vector<string> h0, h1;
	for (int i=0; i<10; i++) {
		if ( i < 5 )
			h0.push_back(line.substr(0, line.find(" ")));
		else 
			h1.push_back(line.substr(0, line.find(" ")));
		line.erase(0, line.find(" ") + 1);
	}
	//for (auto i : h0) cout << i << " ";
	//for (auto i : h1) cout << i << " ";
	vector<string> v = {"1D", "3D", "2D", "5D", "4D"};
	card_sort(v);
	for ( auto i : v ) cout << i << " ";
	cout << "\n";
	cout << straight_flush(v);
	return 0;
}
