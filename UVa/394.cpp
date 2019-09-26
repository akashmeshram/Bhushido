//UVa 394 - Mapmaker
#include<bits/stdc++.h>
using namespace std;

typedef map<string, int> sTi;

struct Calc {
	string name;
	int Base;
	int size;
	int Dim;
	int Ld[10];
	int Ud[10];
	int Cd[10];
	int Co;
};

int main() {
	int N(0), R(0);
	cin >> N >> R;
	sTi nameToIndex;
	vector<Calc> arrays;

	for(int i = 0; i < N; i++){
		Calc nArr;
		cin >> nArr.name >> nArr.Base >> nArr.size >> nArr.Dim;
		for(int d = 0 ; d < nArr.Dim; d++){
			cin >> nArr.Ld[d] >> nArr.Ud[d];
		}
		
		nArr.Cd[nArr.Dim-1] = nArr.size;
		for(int d = nArr.Dim - 2 ; d >= 0; d--){
			nArr.Cd[d] = nArr.Cd[d+1]*(nArr.Ud[d+1] - nArr.Ld[d+1] + 1);
		}

		nArr.Co = nArr.Base;
		for(int d = 0 ; d < nArr.Dim; d++){
			nArr.Co -=  nArr.Cd[d]*nArr.Ld[d] ; 
		}
		arrays.push_back(nArr);
		nameToIndex[nArr.name] = i;
	}

	string name;
	Calc cArr;
	int val[10];
	int output;
	for(int i = 0; i < R; i++){
		output = 0;
		cin >> name;
		cout << name << "[";
		cArr = arrays[nameToIndex[name]];
		for(int d = 0 ; d < cArr.Dim; d++) {
			cin >> val[d];
			cout << val[d];
			if(d != cArr.Dim - 1){
				cout << ", ";
			}
		}
		
		for(int d = 0 ; d < cArr.Dim; d++) {
			output += val[d]*cArr.Cd[d];
		}

		cout << "]" << " = " << output + cArr.Co <<"\n";
	}
	exit (0);		
}
