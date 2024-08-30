#include <bits/stdc++.h>
int f(int n) {
    int ans=0;
    while(n) {
        if(n%10==1) ans++;
        n/=10;
    }
    return ans;
}
int countNumberofOnes(int n) {
    int ans=0;
    for(int i=1;i<=n;i++) ans+=f(i);
    return ans;
}
