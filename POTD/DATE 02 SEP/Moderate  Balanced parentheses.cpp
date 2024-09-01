#include <bits/stdc++.h> 
void solve(int open,int close,vector<string>& ans,string result){
    if(open == 0 && close == 0){
        ans.push_back(result);
        return;
    }
    if(open>0){
        result.push_back('(');
        solve(open-1,close,ans,result);
        //backtracking
        result.pop_back();
    }
    if(close>open){
        result.push_back(')');
        solve(open,close-1,ans,result);
        // backtracking
        result.pop_back();  
    }
}
vector<string> balancedParantheses(int n)
{
    int close = n;
    int open = n;
    vector<string> ans;
    string result;
    solve(open,close,ans,result);
    return ans;
}
