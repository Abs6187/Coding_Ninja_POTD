#include<bits/stdc++.h>
int totalIndexes(vector<int> &A, vector<int> &B) {
    int cnt=0;


    long long sumA = accumulate(A.begin(), A.end(), 0LL);
    long long sumB = accumulate(B.begin(), B.end(), 0LL);
    int n = A.size();


    long long curSumA=0;
    long long curSumB=0;


    for(int i=0; i < n-1; i++){
        curSumA += A[i];
        curSumB += B[i];
        sumA -= A[i];
        sumB -= B[i];
        if(curSumA == sumA && curSumB == sumB && curSumB == curSumA)
                cnt++;
    }
    return cnt;
}
