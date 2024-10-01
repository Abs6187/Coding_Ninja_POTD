// LAST DAY BYE FOR NOW
#include <bits/stdc++.h>

bool isEnough(int curr[],int req[]) {
    for(int i=0;i<256;i++) {
        if(curr[i]<req[i]) {
            return false;
        }
    }
    return true;
}

string smallestWindow(string s, string x) {
    int start=0,len=INT_MAX,j=0,req[256]={0},curr[256]={0};
    for(int i=0;i<x.length();i++) {
        req[x[i]]++;
    }
    for(int i=0;i<s.length();i++) {
        curr[s[i]]++;
        while(isEnough(curr,req)) {
            if(len>i-j+1) {
                len=i-j+1;
                start=j;
            }
            curr[s[j++]]--;
        }
    }
    return s.substr(start,len);
}
