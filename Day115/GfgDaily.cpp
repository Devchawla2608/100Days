  
    int f(int i , int j , string s , vector<vector<int>> &dp){
        if(j<=i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = f(i+1 , j-1 , s , dp);
        else  return dp[i][j] = min(f(i+1 , j , s , dp) , f(i , j-1 , s , dp)) +1;
        return s.size();
    }
  
    int minimumNumberOfDeletions(string s) { 
        vector<vector<int>> dp(s.size() , vector<int>(s.size() , 0));
        for(int i = s.size()-1 ; i>=0 ; i--){
            for(int j = i+1 ; j<s.size() ; j++){
                if(s[i] == s[j])  dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = min(dp[i+1][j] , dp[i][j-1]) +1;
            }
        }
        return dp[0][s.size()-1];
    } 