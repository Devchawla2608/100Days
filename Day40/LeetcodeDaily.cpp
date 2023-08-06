class Solution {
public:

    long long solve(int usedSongs , int currL , int goal , int n , int k ,  vector<vector< long long>> &dp){
        if(currL == goal) return usedSongs == n;
        if(dp[usedSongs][currL] != -1) return dp[usedSongs][currL];
        long long usedSongPlay  = (solve(usedSongs , currL+1 , goal , n , k, dp)*max(0 , usedSongs-k))%1000000007;
        long long newSongPlay = (solve(usedSongs+1 , currL+1 , goal , n , k  , dp)*(n-usedSongs))%1000000007;
        long long total = (usedSongPlay + newSongPlay);
        return  dp[usedSongs][currL] = total%1000000007;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector< long long>> dp(101 , vector< long long>(101 , -1));
        return (int)solve(0 , 0 , goal , n , k , dp);
    }
};