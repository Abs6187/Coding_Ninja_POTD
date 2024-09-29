#include <bits/stdc++.h> 

int copyBitsInRange(int a, int b, int x, int y)

{

    int ans=0;

int c=1;

    while(y!=0)

  { y--;

       x--;

      if((a & 1==1 )&& x<=0)

          {  b=b|c;

          }

   a= a>>1;

   c=c<<1;

    }

        return b;

}
