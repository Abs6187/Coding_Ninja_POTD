#include <bits/stdc++.h> 

int uniqueSubstrings(string input)

{

    unordered_set<char> v;

    int ans = 0, i=0, j=0;

    while(j<input.size())

    {

        if(v.find(input[j])==v.end())

        {

            v.insert(input[j]);

            j++;

        }

        else

        {

            ans = max(ans, (int)v.size()); 

            v.erase(input[i]);

            i++;

        }

    }

    if(ans<(int)v.size()) return ans = v.size(); 

    return ans;

}
