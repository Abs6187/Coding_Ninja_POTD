int longestMountain(int *arr, int n) {

  int ans =0;

  for(int i=1;i<n-1;i++){

      int res=0;

      if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){

          int l,r;

          l=r=i;

          while(l>0 && arr[l]>arr[l-1]){

              l--;

          }

          while(r<n-1 && arr[r]>arr[r+1]){

              r++;

          }

           res = r-l+1;

      }

     ans=max(ans,res);

  }

  return ans;
