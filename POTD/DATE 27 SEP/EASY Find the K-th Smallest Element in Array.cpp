#include <bits/stdc++.h> 

int kthSmallest(vector<int>& v, int n, int k) 

{

    // Write your code here.

    sort(v.begin(),v.end());

    return v[k-1];

} 
