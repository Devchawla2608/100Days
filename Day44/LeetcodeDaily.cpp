class Solution {
public:


    int f(int i , int j , vector<vector<int>>& arr , vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i< 0 || j< 0) return 0;
        if(arr[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 
        int up = f(i-1 , j , arr , dp);
        int left = f(i , j-1 , arr , dp);
        return dp[i][j] = up + left; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        if(arr[0][0] == 1 || arr[n-1][m-1] == 1) return 0;
        return f( n-1 , m-1, arr , dp);
    }
};