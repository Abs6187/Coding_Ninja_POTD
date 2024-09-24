int threePointer(vector<int>& X, vector<int>& Y, vector<int>& Z) {
    int A = X.size(), B = Y.size(), C = Z.size();
    int i = 0, j = 0, k = 0;
    int maxVal, minVal;
    int ans = INT_MAX;
    while (i < A && j < B && k < C) {
        minVal = min(X[i], min(Y[j], Z[k]));
        maxVal = max(X[i], max(Y[j], Z[k]));
        ans = min(ans, maxVal - minVal);
        if (X[i] == minVal) i++;
        else if (Y[j] == minVal) j++;
        else k++;
    }
    return ans;
}
