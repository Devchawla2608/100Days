class Solution {
public:
    bool solve(string &s , int i , int j ,  vector<vector<int>> &dp){
        if(i>=j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = solve(s , i+1 , j-1 , dp);
        return 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(1001 , vector<int>(1001 , -1));
        int mx = INT_MIN;
        int sp = 0;
        for(int i = 0 ;i<n ;i++){
            for(int j = i ; j<n ; j++){
                if(solve(s , i , j , dp) == true){
                    if(j-i+1 > mx){
                        mx = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp , mx);
    }
};