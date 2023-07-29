// Longest Common Subsequence
//    Given two strings, find the length of longest subsequence present in both of them. Both the strings are in uppercase latin alphabets
   int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        for(int i = 1 ;i<=n ; i++){
            for(int j = 1 ; j<= m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }