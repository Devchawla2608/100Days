int mod=pow(10,9)+7;
    int dp[1001][1001];
    int solver(int arr[],int index,int size,int target){
        
        if(target<0) return 0;
        if(index>=size){
        if(target==0){
         return 1;
        }
         return 0;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        
        int ans=(solver(arr,index+1,size,target)%mod +solver(arr,index+1,size,target-arr[index])%mod)%mod;
        dp[index][target]=ans;
        
        return dp[index][target];
        
    }
    int perfectSum(int arr[], int n, int sum)
    {
        memset(dp,-1,sizeof(dp));
       return solver(arr,0,n,sum);
    }