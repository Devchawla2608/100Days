class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9+7;
        unordered_map<int , long long int> mp;
        sort(arr.begin() , arr.end());
        for(int i = 0 ;i<arr.size() ; i++){
            mp[arr[i]]++;
        }
        for(int i = 0 ;i<arr.size() ; i++){
            int cnt = 0;
            for(int j = 0 ;j<i ; j++){
                int u = arr[i];
                int v = arr[j];
                if(u%v == 0){
                    long long int temp = (mp[u/v]*mp[v])%mod;
                    cnt = (cnt+ temp)%mod; 
                }
            }
            mp[arr[i]] = (mp[arr[i]] + cnt)%mod;
        }
        int val = 0;
        for(auto it : mp){
            val = (val +  it.second)%mod;
        }
        return val%mod;
    }
};