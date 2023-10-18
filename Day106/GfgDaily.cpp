class Solution {
  public:
  
    vector<int> eventualSafeNodes(int V, vector<int> a[]) {
	    vector<int> adj[V];
        vector<int> degree(V , 0);
	    for(int i = 0 ;i< V; i++){
	        for(int j = 0 ; j<a[i].size() ; j++){
	            int v = a[i][j];
	            adj[v].push_back(i);
	        }
	    }
	    for(int i = 0 ;i< V; i++){
	        for(int j = 0 ; j<adj[i].size() ; j++){
	            degree[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    vector<int> result;
	    for(int i = 0 ;i<V ; i++){
	        if(degree[i] == 0) q.push(i);
	    }
	    while(q.size() != 0){
	        int element = q.front();
	        q.pop();
	        result.push_back(element);
	        for(int i = 0 ; i< adj[element].size() ; i++){
	            degree[adj[element][i]]--;
	            if(degree[adj[element][i]] == 0) q.push(adj[element][i]);
	        }
	    }
	    sort(result.begin() , result.end());
	    return result;
    }
};