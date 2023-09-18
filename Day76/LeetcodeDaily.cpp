#define pp pair<int , int>

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> temp;
        priority_queue<pp , vector<pp> , greater<pp>> q;
        for(int i = 0 ;i<mat.size() ; i++){
            int cnt = 0;
            for(int j = 0 ; j<mat[0].size() ; j++){
                if(mat[i][j] == 1) cnt++;
            }
            q.push({cnt , i});
        }
        while(k--){
            temp.push_back(q.top().second);
            q.pop();
        }
        return temp;
    }
};