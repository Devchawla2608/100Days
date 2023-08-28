class Solution {
public:
    string reorganizeString(string str) {
        unordered_map<char , int> mp;
        for(auto it : str) mp[it]++;
        priority_queue<pair<int , char>> q;
        for(auto it : mp){
            q.push({it.second , it.first});
        }
        int val = q.top().first;
        int n = str.size();
        if(val > (n+1)/2) {return "";}
        string temp(str.size() , '#');
        int i = 0;
        while(q.size() != 0){
            int c = q.top().second;
            int count = q.top().first;
            q.pop();
            while(count--){
                temp[i] = c;
                i = i + 2;
                if(i>= n) i = 1;
            }
            if(i>= n) i = 1;
        }
        return temp;
    }
};