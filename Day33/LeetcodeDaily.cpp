class Solution {
public:
    long long maxArrayValue(vector<int>& arr) {
        vector<long long> nums;
        for(int i = 0;i<arr.size() ;i++){
            nums.push_back(arr[i]);
        }
        while(true){
            bool change = true;
            for(int i = nums.size()-1 ;i>0 ; i--){
                if(nums[i-1] <= nums[i]){
                    long long sum = nums[i] + nums[i-1];
                    nums.erase(nums.begin() + i-1);
                    nums[i-1] = sum;
                    change = false;
                }
            }
            if(change == true) break;
        }
        long long ans = INT_MIN;
        for(int i = 0;i<nums.size() ; i++){
            ans = max(ans , nums[i]);
        }
        return ans;
    }
};