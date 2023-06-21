
// You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

// You can do the following operation any number of times:

// Increase or decrease any element of the array nums by 1.
// The cost of doing one operation on the ith element is cost[i].

// Return the minimum total cost such that all the elements of the array nums become equal.

class Solution {
public:

    long long calc(vector<int>&nums, vector<int>& cost, long long median){

        long long ans = 0;

         for(int i=0;i<nums.size();i++)
           ans += abs(1ll*nums[i]-median)*(1ll*cost[i]);

         return ans;  
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        long long tot = 0;
        long long sum = 0;
        int n = nums.size();

        vector<pair<int,int>> vec;

        for(int i=0;i<nums.size();i++)
            vec.push_back({nums[i],cost[i]});

        sort(vec.begin(),vec.end());

        for(int i=0;i<n;i++)
        sum += vec[i].second;

        long long median;
        int i=0;

        while(tot < (sum+1)/2 && i<n){

             tot += 1ll*vec[i].second;
             median = vec[i].first;
             i++;
        }    
        
        
        return calc(nums,cost,median);
    }
};