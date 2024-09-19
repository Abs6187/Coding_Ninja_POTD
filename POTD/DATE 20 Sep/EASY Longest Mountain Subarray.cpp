int longestMountain(int *arr, int n)
{
    int ans = 0;
    for (int i = 1; i < n - 1;) {
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            int j = i;
            int count = 1;
            while (j >= 1 && arr[j-1] < arr[j]) {
                j--;
                count++;
            }
            while (i <= n - 2 && arr[i+1] < arr[i]) {
                i++;
                count++;
            }
            ans = max(ans, count);
            i++;
        } else {
            i++;
        }
    }
    return ans;
}
