// UVa 10034 
#include<bits/stdc++.h>
using namespace std;

typedef struct {
    float x;
    float y;
} pt;

typedef struct {
    int a;
    int b;
    float val;
} li;

pt pts[100];
li links[10000];
int n, cnt;

int cmp(const void *i, const void *j){
    li *a, *b;
    a = (li *)i, b = (li *)j;
    return (a->val - b->val < 0)? -1 : 1;
}

int pset[100];
void initPset(){ for(int i = 0; i < n; i++){ pset[i] = i; }}
int findParent(int a) {return (pset[a] == a)? a : findParent(pset[a]);}
void unionSet(int a, int b){pset[findParent(a)] = findParent(b);}
bool sameSet(int a, int b){return findParent(a) == findParent(b);}


int main(){
    int te;
    scanf("%d", &te);
    while(te--){
        cnt = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%f %f", &pts[i].x, &pts[i].y);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i!=j){
                    links[cnt].a = i, links[cnt].b = j;
                    links[cnt++].val = sqrt(pow(pts[i].x - pts[j].x, 2) + pow(pts[i].y - pts[j].y, 2));
                }
            }
        }
        qsort(links, cnt, sizeof(li), cmp);
        float sum = 0;
        initPset();
        for(int i = 0; i < cnt; i++){
            if(!sameSet(links[i].a,links[i].b)){
                unionSet(links[i].a,links[i].b);
                sum += links[i].val;
            }
        }
        cout << sum << '\n';
    }

    return 0;
}
