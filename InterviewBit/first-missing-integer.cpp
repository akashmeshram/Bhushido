int Solution::firstMissingPositive(vector<int> &A) {
   int crr = 1;
   sort(A.begin(), A.end());
   for(int i: A){
       if(crr == i) crr++;
   }
   return crr;
}
