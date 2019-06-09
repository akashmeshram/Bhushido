//UVa 11239 - Open Source
#include<bits/stdc++.h>
using namespace std;

int main() {
	string word, project;
	int count, proj;
	while(1) {
		map<string, set<string> > sheet;
		map<string, int> applied;
		string result[100];
		proj = 0;
		while(getline(cin, word)){
			if(word[0] == '1') break;
			if(word[0] == '0') break;			
			if(word[0] >= 'A' && word[0] <= 'Z') {				
				project = word;
				sheet[project].insert("");
				proj++;
			} else {
				if(applied[word] == proj || applied[word] == 0){
					sheet[project].insert(word);
					applied[word] = proj;	
				} else {
					applied[word] = -1;
				}						
			}
		}
		proj = 0;
		for(map<string, set<string> >::iterator data = sheet.begin(); data != sheet.end(); data++) {
			count = -1;
			for(set<string>::iterator student = data->second.begin(); student != data->second.end(); student++) {
				if(applied[*student] != -1) {
					count++;
				}
			}
			result[proj++] = data->first + ' ' + to_string(count) + '\n';
		}
		sort(result, result + proj, greater<string>());
		while(proj--){
			cout << result[proj];
		}
		if(word[0] == '0') return 0;
	}
}
