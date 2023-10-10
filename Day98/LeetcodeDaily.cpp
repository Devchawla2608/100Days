class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=n-1;
        sort(nums.begin(), nums.end());
        auto it=unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());//erase the repetive elements
        int m=nums.size(), k=n-m;
    //    cout<<"n="<<n<<" , m="<<m<<", k="<<k<<endl;

        queue<int> q;// hold the sliding window
        #pragma unroll
        for (int i=0; i<m; i++) {
            while (!q.empty() && nums[i]-q.front()>= n)//q.front() is too small
                q.pop();// pop away from q
            
            q.push(nums[i]);
            ans = min(ans, n-(int)(q.size()));
        } 
        return ans;
    }
};