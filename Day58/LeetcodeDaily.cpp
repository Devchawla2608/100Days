class Solution {
public:
    bool isGood(vector<int>& nums) {
        vector<int> vis(nums.size() , 0);
        int mx = nums.size()-1;
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] > mx) return false;
            vis[nums[i]]++;
        }
        for(int i = 1 ;i<=mx ; i++){
            if(i == mx){
                if(vis[i] != 2) return false;
                else return true;
            }else{
                if(vis[i] != 1) return false;
            }
        }
        return true;
    }
};