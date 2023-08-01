class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n , 0);
        vector<int> right(n , 0);
        stack<int> st;
        for(int i = 0;i<n ; i++){
            while(st.size() != 0){
                int front = st.top();
                if(heights[front] >= heights[i]){
                    st.pop();
                }else{
                    left[i] = front + 1;
                    st.push(i);
                    break;
                }
            }
            if(st.size() == 0){
                st.push(i);
                left[i] = 0;
            }
        }
        while(st.size() !=0) st.pop();
        for(int i = n-1;i>=0 ; i--){
            while(st.size() != 0){
                int front = st.top();
                if(heights[front] >= heights[i]){
                    st.pop();
                }else{
                    right[i] = front -1;
                    st.push(i);
                    break;
                }
            }
            if(st.size() == 0){
                st.push(i);
                right[i] = n-1;
            }
        }
        int ans = INT_MIN;
        for(int i = 0;i<n ; i++){
            int val = ((right[i] - left[i]) +1)*heights[i];
            ans = max(val , ans);
        }
    return ans;
    }
};