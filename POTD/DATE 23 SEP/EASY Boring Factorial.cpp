
#include <bits/stdc++.h> 

int boringFactorials(int n, int p)

{

    if(n==1){

        return 1;

    }

    return (boringFactorials(n-1,p)*n%p);

}
