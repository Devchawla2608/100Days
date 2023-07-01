// Fair Distribution of Cookies
// You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.
// The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.
// Return the minimum unfairness of all distributions.
class Solution {
public:

    int solve(int index , vector<int> &arr , int k , vector<int> &bags){
        if(index<0) {
            int temp = INT_MIN;
            for(int i = 0 ;i<bags.size() ; i++){
                temp = max(temp , bags[i]);   
            }
            return temp;
        }
        int result = 1e9;
        for(int i = 0 ;i< k ; i++){
            int temp = bags[i];
            bags[i] += arr[index];
            result = min(result , solve(index-1 , arr , k , bags));
            bags[i] = temp;
        }
        return result;
    }
    int distributeCookies(vector<int>& arr, int k) {
        vector<int> bags(k , 0);
        return solve(arr.size() -1, arr , k , bags);
    }
};