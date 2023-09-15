class Solution{
public:
    bool f(int index , int arr[] , int k , vector<vector<int>> &dp){
        if(k == 0) return true;
        if(index == 0){
            return k == arr[0];
        }
        if(dp[index][k] != -1) return dp[index][k];
        bool notPick = f(index-1 , arr , k  , dp);
        bool pick = false;
        if(k>= arr[index]){
            pick = f(index-1 , arr , k-arr[index]  , dp);
        }
        return dp[index][k] = notPick | pick;
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0;i<N ; i++) sum += arr[i];
        if(sum %2 != 0) return 0;
        int k = sum/2;
        vector<vector<int>> dp(N , vector<int>(sum/2 + 1 , 0));
        for(int i = 0 ;i<=sum/2 ; i++){
            if(k == arr[0]) dp[0][i] = true;
            else dp[0][1] = false;
        } 
        for(int i = 0 ;i<N ; i++){
            dp[i][0] = 1;
        }
        for(int i = 1 ;i<N ; i++){
            for(int j = 1 ;j<=sum/2 ; j++){
                bool notPick = dp[i-1][j];
                bool pick = false;
                if(j>= arr[i]){
                    pick = dp[i-1][j-arr[i]];
                }
                dp[i][j] = notPick | pick;   
            }
        }
        return dp[N-1][sum/2];
    }