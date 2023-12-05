class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        if(n == 1) return 0;
        sort(arr , arr + n);
        int diff = arr[n-1] - arr[0];
        int mn  , mx;
        for(int i = 1 ; i<n ; i++){
            if(arr[i]-k<0) continue;
            mx = max(arr[i-1] + k , arr[n-1] - k);
            mn = min(arr[0]+k , arr[i]-k);
            diff = min(diff , mx - mn);
        }
        return diff;
    }
};