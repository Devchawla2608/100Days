class DisjointSet{ 
    private:
    vector<int> rank , size , parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1 , 0);
        size.resize(n+1 , 1);
        parent.resize(n+1);
        for(int i = 0;i<=n; i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }
    
    void unionBySize(int u , int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_u] += size[ulp_v];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
    }
    
    void unionByRank(int u , int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &arr) {
        int n = arr.size();
        DisjointSet ds(n);
        unordered_map<string , int> ourmap;
        for(int i = 0;i<n ; i++){
            for(int j = 1;j<arr[i].size() ; j++){
                string mail = arr[i][j];
                if(ourmap.find(mail) == ourmap.end()){
                    ourmap[mail] = i;
                }else{
                    ds.unionBySize(i , ourmap[mail]);
                }
            }
        }
        vector<string> mergedMail[n];
        for(auto it : ourmap){
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i = 0;i<n ; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin() , mergedMail[i].end());
            vector<string> temp;
            temp.push_back(arr[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};