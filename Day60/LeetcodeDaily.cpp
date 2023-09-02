class Solution {
public:

    int f(int i , int j , string s , vector<string> &arr , unordered_map<string , int> &mp , vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j]; 
        string str = s.substr(i , j-i+1);
        if(mp[str] != 0) return 0;
        int val = j-i+1;
        for(int k = i; k<j ; k++){
            int leftAns = f(i , k , s , arr , mp, dp);
            int rightAns = f(k+1 , j , s , arr , mp, dp);
            val = min(val ,  leftAns + rightAns); 
        }
        return dp[i][j] = val;
    }

    int minExtraChar(string s, vector<string>& arr) {
        unordered_map<string , int> mp;
        vector<vector<int>> dp(s.size() , vector<int>(s.size() , 0));
        for(auto it : arr) mp[it]++;

        for(int i = s.size()-1 ;i>=0 ; i--){
            for(int j = 0 ; j<s.size() ; j++){
                if(i>j) {dp[i][j] = 0; continue;}
                    string str = s.substr(i , j-i+1);
                    if(mp[str] != 0) { dp[i][j] =  0; continue;}
                    int val = j-i+1;
                    for(int k = i; k<j ; k++){
                        int leftAns = dp[i][k];
                        int rightAns = dp[k+1][j];
                        val = min(val ,  leftAns + rightAns); 
                    }
                    dp[i][j] = val;
            }
        }

        return dp[0][s.size()-1];
    }
};