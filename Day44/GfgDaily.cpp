    int lengthOfLIS(vector<int>& nums) {
        vector<int> after(nums.size()+1 , 0);
        vector<int> temp(nums.size()+1 , 0);
        for(int i = nums.size()-1 ; i>=0 ; i--){
            for(int j = i-1 ; j>= -1 ; j--){
                int notPick = after[j+1];
                int pick = 0;
                if(j == -1 || nums[i]> nums[j]){
                    pick = after[i+1] + 1;
                }
                temp[j+1] =  max(notPick , pick);
            }
            after = temp;
        }
        return after[-1+1];
    }
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp{a[0]};
        
        for (int i = 0; i < n; i++){
            if(a[i] > dp.back()) dp.push_back(a[i]);
            else *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        }
        return dp.size();
    }