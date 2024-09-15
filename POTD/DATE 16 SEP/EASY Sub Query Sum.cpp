#include <bits/stdc++.h> 
vector<int> findSubmatrixSum(vector<vector<int>> &arr, vector<vector<int>> &queries) 
{

    vector<int> ans;

    int n = arr.size();
    int m = arr[0].size();

    int s = queries.size(); //no. of rows

    for(int i=0;i<s;i++){
        int sum=0;
        int p = queries[i][0];
        int q = queries[i][1];
        int r = queries[i][2];
        int s = queries[i][3];
        for(int j=p;j<=r;j++){
            for(int k=q;k<=s;k++){
                sum += arr[j][k];
            }
        }
        ans.push_back(sum);
    }

    return ans;

}
