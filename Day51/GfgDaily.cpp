
class DisjointSet{ 
    public:
    vector<int> rank , size , parent;
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


class Solution {
  public:
    int numProvinces(vector<vector<int>> arr, int V) {
        DisjointSet ds(V);
        for(int i = 0;i<V ; i++){
            for(int j = 0;j<V ; j++){
                if(arr[i][j] == 1){
                    ds.unionBySize(i , j);
                }
            }
        }
        int count = 0;
        for(int i = 0;i<V ; i++){
            if(i == ds.parent[i]) count++; 
        }
        return count;
    }
};