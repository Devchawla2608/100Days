    int FindMaxSum(int arr[], int n)
    {
        if(n == 0) return 0;
        if(n == 1) return arr[0];
        int pre = arr[0];
        int cur = max(arr[0] , arr[1]);
        for(int i = 2;i<n ; i++){
            int notPick = cur;
            int pick = pre + arr[i];
            pre = cur;
            cur  = max(pick , notPick);
        }
        return cur;
    }