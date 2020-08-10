#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main() {
	string s;
	ifstream inFile;
	vector < vector<string> > v;
	inFile.open("11.txt");

	while ( getline(inFile, s) ) {
		vector<string> vs;
		string delimiter = " ";
		while ( s.length() > 0 ) {
			string token = s.substr(0, s.find(delimiter));
			vs.push_back(token);
			size_t c = -1;
			if ( s.find(delimiter) == c ) 
				s.erase(0, s.length());
			else
				s.erase(0, s.find(delimiter) + 1);
		}
		v.push_back(vs);
	}
	long long ans = 0;
	for (unsigned int i=0; i<v.size(); i++ ) {
		for (unsigned int j=0; j<v[i].size()-4; j++) {
			long long sum = stoi(v[i][j]) * stoi(v[i][j+1]) * stoi(v[i][j+2]) * stoi(v[i][j+3]);
			ans = max(ans, sum);
		}
	}
	
	cout << ans << "\n";
	
	for (unsigned int j=0; j <v[0].size(); j++) {
		for (unsigned int i=0; i <v.size()-4; i++) {
			long long sum = stoi(v[i][j]) * stoi(v[i+1][j]) * stoi(v[i+2][j])* stoi(v[i+3][j]);
			ans = max(ans, sum);
		}
	}
	
	cout << ans << "\n";
	
	for (unsigned int i=0; i<v.size()-4; i++) {
		for (unsigned int j=0; j<v[i].size()-4; j++) {
			long long sum = 1;
			for (int k=0; k<4; k++) {
				sum *= stoi(v[i+k][j+k]);
				cout << v[i+k][j+k] << " ";
				if ( sum == 51267216 ) {
					cout << "\n" << "Hello" << "\n";
				}
			}
			cout << "\n";
			ans = max(ans, sum);
		}
	}
	cout << ans << "\n";
	
	
	for (unsigned int i=0; i<v.size()-4; i++) {
		for (unsigned int j=3; j<v[i].size(); j++) {
			long long sum = 1;
			for (unsigned int k=0; k<4; k++) {
				sum *= stoi(v[i+k][j-k]);
				//cout << v[i+k][j-k] << " ";
			}
			//cout << "\n";
			ans = max(ans, sum);
		}
	}
	cout << ans << "\n";

	inFile.close();
	return 0;
}
