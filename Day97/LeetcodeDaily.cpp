class Solution {
public:
    vector<int> searchRange(vector<int>& nums , int start , int end ,  int target){
        if(start>end){
            vector<int> v;
            v.push_back(-1);
             v.push_back(-1);
            return v;
        }
        if(start==end){
            if(nums[start] == target){
                vector<int> v;
                v.push_back(start);
                v.push_back(end);
                return v;
            }else{
                vector<int> v;
                v.push_back(-1);
                  v.push_back(-1);
                return v;
            }
        }
            int mid = (start + end)/2;
            if(nums[mid] == target){
                vector<int> held;
                held.push_back(mid);
                held.push_back(mid);
                vector<int> x = searchRange(nums , mid+1 , end , target);
                vector<int> y = searchRange(nums , start , mid - 1 , target);
                if(y[0] != -1){
                    held[0] = min(y[0] , held[0]);
                }
                held[1] = max(held[1] , max(x[1] , y[1]));
                return held;
            }else if(nums[mid] < target){
                return searchRange(nums , mid+1 , end , target);
            }else{
               return searchRange(nums , start , mid - 1 , target);
            }
        }
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchRange(nums , 0 , nums.size() -1 , target);
    }
};