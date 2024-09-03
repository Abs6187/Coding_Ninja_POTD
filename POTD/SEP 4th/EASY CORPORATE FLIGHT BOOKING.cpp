#include <bits/stdc++.h> 

vector< int > corpFlightBookings(vector< vector < int > > &bookings, int n) {

    

    vector< int > ans(n,0);

    for(int i=0;i<bookings.size();i++){

        int a=bookings[i][0];

        int b=bookings[i][1];

        int c=bookings[i][2];

        for(int j=a;j<=b;j++){

            ans[j-1]+=c;

        }

    }

    return ans;

}
