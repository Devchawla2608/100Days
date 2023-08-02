class Solution {
public:

    void solve(vector<int>& nums , vector<int>& ans , vector<vector<int>> &result , unordered_map<int , int> &ourmap){
        if(ans.size() == nums.size()){
            result.push_back(ans);
            return;
        }
        for(int i = 0;i<nums.size() ; i++){
            if(ourmap[nums[i]] > 0) continue;
            ans.push_back(nums[i]);
            ourmap[nums[i]]++;
            solve(nums , ans , result , ourmap);
            ans.erase(ans.end()-1);
            ourmap[nums[i]]--;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int , int> ourmap;
        vector<vector<int>> result;
        vector<int> ans;
        solve(nums , ans , result , ourmap);
        return result;
    }
};