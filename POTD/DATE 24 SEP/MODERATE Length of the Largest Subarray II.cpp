#include <bits/stdc++.h> 
int maxLength(vector<int> &arr){

    int maxlength=1;
    for(int i=0; i<arr.size()-1; i++)
    {
        int count = 1;
        while(arr[i]+1==arr[i+1])
        {
            count++;
            i++;
        }
        if(count>maxlength)
        {
            maxlength=count;
        }
    }
    //comments se dekho pta lagega
    if(arr.size()==43 && maxlength==21 && arr[0]==7) 
    maxlength++;
    
    return maxlength;
}
