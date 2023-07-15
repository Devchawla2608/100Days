// Maximum Number of Events That Can Be Attended II
// You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.

// You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.

// Return the maximum sum of values that you can receive by attending events.

class Solution {
public:

    static bool cmp(vector<int> &a , vector<int> &b){
        return a[0]<b[0];
    }
    int f(int index, int k  , vector<vector<int>> &arr , vector<vector<int>> &dp){
        if(index == arr.size()) return 0;
        if(k == 0) return 0;
        if(dp[index][k] !=-1) return dp[index][k];
        int take = arr[index][2];
        for(int i = index+1;i<arr.size() ; i++){
            if(arr[i][0] > arr[index][1]){
                take += f(i , k-1 , arr , dp);
                break;
            }
        }
        int notTake = f(index+1 , k , arr , dp);
        return dp[index][k] =  max(take , notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>> dp(events.size() , vector<int>(k+1 , -1));
        sort(events.begin() , events.end() , cmp );
        return f(0 , k , events , dp);
    }
};