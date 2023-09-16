#define pp pair<int,pair<int , int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
                // 
        priority_queue < pair<int , pair<int , int>>, 
        vector< pair<int , pair<int , int>>>, greater< pair<int , pair<int , int>>>> q;
        int n = heights.size();
        int m =heights[0].size();
        vector<vector<int>> dis(n , vector<int>(m , 1e9));
        dis[0][0] = 0;
        q.push({0 , {0 , 0}});
        while(q.size() != 0){
            int eff = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            if(row == n-1 && col == m-1) return eff;
            q.pop();
            int a[4] = {row-1 , row , row+1 , row};
            int b[4] = {col , col-1 , col , col+1};
            for(int i = 0;i<4 ; i++){
                if(a[i] <0 || b[i] <0 || a[i] >= n || b[i] >=m) continue;
                int newEff = max(abs(heights[a[i]][b[i]] - heights[row][col]) , eff);
                if(newEff < dis[a[i]][b[i]]){
                    dis[a[i]][b[i]] = newEff;
                    q.push({newEff , {a[i] , b[i]}});
                }
            }
        }

        return 0;
    }
};