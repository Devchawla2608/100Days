class Solution {
public:

    int minDeletions(string s) {
        unordered_map<char , int> mp1;
        unordered_map<int , int> mp2;
        for(auto it : s){
            mp1[it]++;
        }
        for(auto it: mp1){
            mp2[it.second]++;
        }
        priority_queue<pair<int , int>> q;
        for(auto it : mp2){
            q.push({it.first , it.second});
        }
        int cnt = 0;
        while(q.size() != 0){
            int el = q.top().first;
            int fre = q.top().second;
            cout<<el<<" el "<<fre<<endl;
            q.pop();
            if(fre == 1) continue;
            cnt += fre - 1;
            int newEl =  q.top().first;
            if(newEl == el - 1){
                int newFre = q.top().second;
                q.pop();
                q.push({newEl , newFre + fre-1});
            }else{
                if(el -1 == 0) continue;
                q.push({el-1 , fre-1});
            }
        }
    return cnt;
    }
};