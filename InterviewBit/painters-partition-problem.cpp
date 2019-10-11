int getPainters(vector<int> &A, long long mid){
    int nuPaint = 1;
    long long total = 0;
    for(int i = 0; i < A.size(); i++){
        total += A[i];
        if(total > mid){ nuPaint++; total = A[i];}
    }
    return nuPaint;
}

int Solution::paint(int P, int T, vector<int> &A) {
    long long l = INT_MIN, h = 0, mid;
    for(int i = 0; i < A.size(); i++) if(l < A[i]) l = A[i];
    for(int i = 0; i < A.size(); i++) h += A[i];
    int np;
    while(l < h){
        mid = l + (h-l)/2;
        np = getPainters(A, mid);
        if(np <= P) h = mid;
        else l = mid + 1;
    }
    return (l*T)%10000003;
}