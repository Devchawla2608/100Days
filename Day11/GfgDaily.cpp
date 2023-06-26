
// nCr
// Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.
class Solution{
public:
    int nCr(int n, int r){
        if(n<r)return 0;
        if((n-r) < r) r = n-r;
        vector<int> dp(r+1 , 0);
        dp[0] = 1;
        for(int i = 1 ;i<= n ; i++){
            for(int j = min(r , i) ; j> 0 ;j--){
                dp[j] = (dp[j] + dp[j-1])%1000000007;
            }
        }
        return dp[r];
    }
};