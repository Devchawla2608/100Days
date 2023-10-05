class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(int i = 0 ;i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        vector<int> temp;
        for(auto it: mp){
            int val = it.first;
            int fre = it.second;
            if(fre > nums.size()/3) temp.push_back(val);
        }
        return temp;
    }
};