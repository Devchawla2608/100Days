class Solution {
public:
#define ll long long
    int minimumSeconds(vector<int>& nums) {
        ll n = nums.size();
        unordered_map<ll , vector<ll>> pos;
        for(int i = 0;i<n ; i++){
            pos[nums[i]].push_back(i);
        }
        ll ans = n;
        for(auto it : pos){
            ll prev = 0;
            ll cur = 0;
            for(int i = 1 ; i<it.second.size() ; i++){
                cur = max(cur , (it.second[i] - it.second[i-1])/2);
            }
            ll r = (n-1 - it.second.back() + it.second[0] +1)/2;
            cur = max(cur , r);
            ans = min(ans , cur);
        }
        return ans;
    }
};