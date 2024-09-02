#include <bits/stdc++.h> 

int digitProduct(int n)

{

    // Find all the factors of the number ans store it

    vector<int> factors;

    for(int i=9; i>1; i--){

        while(n%i == 0){

            factors.push_back(i);

            n = n/i;

        }

    }

    

    if(n!=1){

        return -1; // factors not possible

    }

    int ans = 0;

    for(int i=factors.size()-1; i>=0; i--){

        ans = ans*10 + factors[i];

    }

    return ans;

}
