class Solution {
public:

    int f(int i , int j , vector<int> arr , vector<vector<int>> &dp){
        if(i>j) return 0;
        int mx = INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i ; k<=j ; k++){
            int coin = arr[i-1]*arr[k]*arr[j+1] + f(i,k-1 , arr , dp) + f(k+1 , j , arr , dp);
            mx = max(mx , coin);
        }
        return dp[i][j] =  mx;
    }

    int maxCoins(vector<int>& arr) {
        arr.push_back(1);
        arr.insert(arr.begin() , 1);
        vector<vector<int>> dp(arr.size() , vector<int>(arr.size() , 0));
        for(int i = arr.size()-2 ; i>=1 ; i--){
            for(int j = 1 ; j<arr.size()-1 ; j++){
                int mx = INT_MIN;
                if(i>j){ dp[i][j] = 0 ; continue;}
                for(int k = i ; k<=j ; k++){
                int coin = arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1] + dp[k+1][j];
                mx = max(mx , coin);
                }
                dp[i][j] =  mx;
            }
        }
        return dp[1][arr.size()-2];
    }
};