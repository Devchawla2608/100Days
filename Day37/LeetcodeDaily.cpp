class Solution {
public:

    int f(int index1 , int index2 , string s , string t , vector<vector<int>> &dp){
        if(index2<0 ) return 1;
        if(index1 <0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(s[index1] == t[index2]){
            return f(index1-1 , index2 -1 , s , t, dp) + f(index1 -1 , index2 , s , t, dp);
        }else{
            return f(index1 -1 , index2 , s , t, dp);
        }
    }

    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size()+1 , vector<long long>(t.size()+1 , 0));
        for(int j = 0; j<= s.size() ; j++){
            dp[j][0] = 1;
        }
        for(int i = 1 ;i<=s.size() ; i++){
            for(int j = 1 ;j<=t.size() ; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%1000000007;
                }else{
                    dp[i][j] =  (dp[i-1][j])%1000000007;
                }
            }
        }
        return (int)dp[s.size()][t.size()];
    }
};