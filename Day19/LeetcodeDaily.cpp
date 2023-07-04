137. Single Number I
// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
// You must implement a solution with a linear runtime complexity and use only constant extra space.
class Solution {
public:
 int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(auto x: nums){
            m[x]++;
        }

        for(auto x: m){
            if(x.second == 1){
                return x.first;
            }
        }
        
        return -1;
    }
};