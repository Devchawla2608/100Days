    int f(int index1 , int index2 , string word1 , string word2 , vector<vector<int>> &dp){
        if(index1 < 0) return index2 + 1;
        if(index2 < 0) return index1 + 1;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(word1[index1] == word2[index2]) return f(index1-1 , index2-1 , word1 , word2, dp);
        return dp[index1][index2] = min(f(index1 , index2-1 , word1 , word2, dp) ,min( f(index1 -1 , index2 , word1 , word2, dp) , f(index1-1 , index2 -1 , word1 , word2, dp)))+1;
    }

    int editDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() , vector<int>(word2.size() , -1));
        return f(word1.size() -1 , word2.size() -1 , word1 , word2 , dp);
    }