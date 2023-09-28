class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int a = 1e9; //odd
        int b = 1e9; //even
        int i = 0;
        int j = 1;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]%2 == 0)i++;
            else a = i;
            if(nums[j]%2 != 0) j++;
            else b = j;
            if((a!= 1e9 && b!=1e9)){
                if(a<b){ 
                    swap(nums[a] , nums[b]);
                    i++;
                    j++;
                    a = 1e9;
                    b = 1e9;
                }else{
                    j = i+1;
                    a = 1e9;
                    b = 1e9;
                }
            }
        }
        return nums;
    }
};