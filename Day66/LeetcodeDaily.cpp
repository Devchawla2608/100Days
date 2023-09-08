class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;

        int i = 1;

        while(i<=numRows){

            temp.resize(i , 0);

            temp[0] = 1;

            temp[i-1] = 1;
            if(i == 1){
                ans.push_back(temp);
                i++;
                continue;
            }
            vector<int> pre = ans[i-2];
            for(int j = 1 ; j<i-1 ; j++){
                temp[j] = pre[j] + pre[j-1];
            }

            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};