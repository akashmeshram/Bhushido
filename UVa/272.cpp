//UVa 272 - TEX Quotes
#include<bits/stdc++.h>
using namespace std;

int main() {
	string line;
	bool cond = true;
	while(getline(cin, line)){
		for(string::iterator iter = line.begin(); iter != line.end(); ++iter){
			if(*iter == '"'){
				if(cond){
					cout << "``";
				} else {
					cout << "''";
				}
				cond = !cond;
			} else {
				cout << *iter;
			}
		}
		cout << "\n";
	}	
	exit (0);		
}
