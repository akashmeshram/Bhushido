//UVa 10226 - Hardwood Species
#include<bits/stdc++.h>
using namespace std;

int main() {
	map<string, int> trees;
	int n, count;
	string name;
	cin >> n;
	getchar();
	while(n--) {
		count = 0;
		while(getline(cin, name)) {
			trees[name]++;
			count++;
		}
		for(map<string, int>::iterator i = trees.begin(); i != trees.end(); i++) {
			cout << i->first << " " << fixed << setprecision(4) << i->second*100.0/count << endl;
		}
		printf("\n");
	}
	return 0;
}
