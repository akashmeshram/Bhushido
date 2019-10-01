int len, sum;
vector<int> A, B, C;

int knap(int id, int crr){    
    if(id == len-1) return -1;
    crr += A[id];
    B.push_back(A[id]);
    if(len*crr == B.size()*sum) return 1;
    if(knap(id + 1, crr) == 1){
        return 1;
    } 
    B.pop_back();
    crr -= A[id];
    if(knap(id + 1, crr) == 1){
        return 1;
    }
    return -1;
}

vector<vector<int> > Solution::avgset(vector<int> &Arr) {
    A = Arr;
    sort(A.begin(), A.end());
    len = A.size();
    vector<vector<int> > ans;
    sum = 0;
    for(int i = 0; i < len; i++) sum += A[i];
    
    if(knap(0, 0) == 1){
        for(int i = 0; i < len; i++){
            C.push_back(A[i]);
            for(int j = 0; j < B.size(); j++){
                if(A[i] == B[j]) {C.pop_back(); break;}
            }
        }
        if(B.size() < len/2){
            ans.push_back(B);
            ans.push_back(C);
        }else if(B.size() > len/2){
            ans.push_back(C);
            ans.push_back(B);
        } else {
            for(int i = 0; i < B.size(); i++){
                if(B[i] != C[i]){
                    if(B[i] < C[i]){
                        ans.push_back(B);
                        ans.push_back(C);
                    }else if(B[i] > C[i]){
                        ans.push_back(C);
                        ans.push_back(B);
                    }
                    break;
                }
            }
        }
    }
    return ans;
}
