class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int sum2 = 0;
        for(int i = n-k; i<n ; i++)  sum2 +=arr[i];
        int ind1 = -1;
        int ind2 = n-k-1;
        int sum1 = 0;
        int ans = INT_MIN;
        while(ind1 < k && ind2<n){
            if(ind1 == -1) ans = max(ans , sum2);
            else{
                sum1 += arr[ind1];
                sum2 -= arr[ind2];
                ans = max(ans , sum2 + sum1);
            }
            ind1++;
            ind2++;
        }
        return ans;
    }
};