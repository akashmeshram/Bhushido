//536 - Tree Recovery
#include<bits/stdc++.h>
using namespace std;

typedef pair<char, char> ii;
map<char, ii> data;
string prOrd, inOrd;
int len, crr;

char makeTree(int start, int end){
    int rid;
    if(end < start) return ' ';
    char root = prOrd[crr++];
    for(int i = start; i <= end; i++) {
        if(root == inOrd[i]){
            rid = i;
        }
    }
    data[root] = ii(' ', ' ');
    data[root].first = makeTree(start, rid-1);
    data[root].second = makeTree(rid+1, end);
    return root;
}

void postOrd(char c){
    if(c == ' ') return;
    postOrd(data[c].first);
    postOrd(data[c].second);
    printf("%c", c);
}

int main(){    
    while(cin >> prOrd >> inOrd){
        len = prOrd.size();
        crr = 0;
        char r = makeTree(0, len-1);
        postOrd(r);
        data.clear();
        puts("");
    }
    return 0;
}
