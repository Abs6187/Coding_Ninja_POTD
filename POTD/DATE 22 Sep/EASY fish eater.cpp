#include <bits/stdc++.h>

int fishEater(vector<int> &fishes) {

// Write your code here.

int max =0;

int n = fishes.size();

int i=0;

int j=1;

 

while(j<n){

if(fishes[i] > fishes[j]){

max++;

j++;

 

}

else{

i = j;

j++;

}

}

return n- max;

}
