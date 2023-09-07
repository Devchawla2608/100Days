class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dis(100000 , 1e9);
        queue<pair<int , int>> q;
        q.push({0 , start});
        dis[start] = 0;
        int result = 1e9;
        while(q.size() != 0){
            int node = q.front().second;
            int steps = q.front().first;
            q.pop();
            if(node == end){
                result = min(result , steps);
                continue;
            }
            for(int i = 0 ; i<arr.size() ; i++){
                int v = (arr[i]*node)%100000;
                // if(v > end) continue;
                if(dis[v] > steps + 1){
                    dis[v] = steps+1;
                    q.push({steps+1 , v});
                }
            }
        }
        if(result == 1e9) return -1;
        return result;
    }
};