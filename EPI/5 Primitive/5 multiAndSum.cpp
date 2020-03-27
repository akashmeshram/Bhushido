#include <iostream>

using namespace std;

int add(int a, int b) {
    int ans = 0;
    int mpos = 0;
    bool c = 0;
    while(a || b){
        bool ta = a&1;
        bool tb = b&1;
        ans |= ((ta ^ tb ^ c) << mpos++);
        c = c&ta || c&tb || ta&tb;
        a>>=1, b>>=1;
    }
    ans |= (c << mpos);
    return ans;
}

int multiply(int a, int b){
    int ans = 0;
    while(b){
        if(b & 1){
            ans = add(ans, a);
        }
        a<<=1, b>>=1;
    }
    return ans;
}


int main()
{
    cout << multiply(6, 7);
    return 0;
}