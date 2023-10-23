int f(int index , int pre , int arr[] , int n , vector<vector<int>> &dp){
	    if(index == n) return 0;
	    int pick = INT_MIN;
	    if(dp[index][pre+1] != -1) return dp[index][pre+1];
	    if(arr[index] > arr[pre]){
	        pick = f(index+1 , index , arr , n, dp) + arr[index];
	    }
	    int notPick = f(index+1 , pre , arr , n, dp);
	    return dp[index][pre+1] =  max(pick , notPick);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
        for(int i = n-1 ;i>=0 ; i--){
            for(int j = i-1 ; j>=-1; j--){
	            int pick = INT_MIN;
	            if(arr[i] > arr[j]){
        	        pick = dp[i+1][i+1] + arr[i];
	            }
	            int notPick = dp[i+1][j+1];
	            dp[i][j+1] =  max(pick , notPick);
            }
        }
        return dp[0][0];
	}  