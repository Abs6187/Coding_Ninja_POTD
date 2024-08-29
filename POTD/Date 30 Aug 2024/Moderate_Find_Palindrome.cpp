#include <bits/stdc++.h> 

vector<int> getPalindromes(int n)

{

     vector<int>v;

      for(int i=1;i<=n;i++)

        {

        if(i<10)

              v.push_back(i);

          else

          {

            int x=i;

            int sum=0;

           while (x>0) 

        {

            int rem=x%10;

            sum=sum*10+rem;

            x=x/10;

          }

          if(sum==i) 

        {

            v.push_back(i);

          }

        }

      }

            return v;

}
