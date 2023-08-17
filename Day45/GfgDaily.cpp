class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& arr) {
        vector<string> temp;
        
        for(int i = 0;i<arr.size() ; i++){
            string s = arr[i];
            sort(s.begin() , s.end());
            temp.push_back(s);
        }
        vector<vector<string>> ans;
        vector<int> vis(arr.size() , 0);
        
        for(int i = 0 ;i<temp.size() ; i++){
            vector<string> t;
            if(vis[i] == 1) continue;
            t.push_back(arr[i]);
            vis[i] = 1;
            for(int j = i+ 1 ; j<temp.size() ; j++){
                if(temp[i] == temp[j]){
                    vis[j] = 1;
                    t.push_back(arr[j]);
                }
            }
                ans.push_back(t);
        }
        return ans;
    }
};