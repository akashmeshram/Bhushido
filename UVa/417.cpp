//417 - Word Index
#include<bits/stdc++.h>
using namespace std;

map<string, int> data;
queue<string> pos;
int cnt = 0;

void genData(){
    string s;
    for(char i = 'a'; i <= 'z'; i++) pos.push(s + i);
    while(!pos.empty()) {
        s = pos.front(), pos.pop();
        data[s] = ++cnt;
        if(s.size() == 5) continue;
        for(char i = s[s.size()-1] + 1; i <= 'z'; i++) pos.push(s + i);
    }
}

int main() {
    string line;
    genData();
    while(getline(cin, line)) {
        bool flag = true;
        for(int i = 1; i < line.size() - 1; i++) {
            if(line[i] < line[i-1]) flag = false;
        }
        (flag)? cout << data[line] : cout << 0; 
        puts("");
    }
    return 0;
}
