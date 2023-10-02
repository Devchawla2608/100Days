	int distinctSubsequences(string s)
	{
	    int mod = 1e9+7;
	    int n = s.size();
	    vector<int> dp(n+1);
	    dp[0] = 1;
	    unordered_map<char , int> mp;
	    for(int i = 1 ; i<=n ; i++){
	        char ch = s[i-1];
	        dp[i] = (2*dp[i-1])%mod;
	        if(mp.count(ch) != 0){
	            int index = mp[ch];
	            dp[i] = (dp[i]-dp[index-1] + mod)%mod;
	        }
	        mp[ch] = i;
	    }
	    return dp[n];
	}