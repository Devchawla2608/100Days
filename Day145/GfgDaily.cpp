   vector<int> par;
    
    int find(int n){
        if(par[n]==n) return n;
        return par[n]=find(par[n]);
    }
    
    bool Union(int a, int b){
        int x=find(a);
        int y=find(b);
        if(x!=y){
            par[x]=y;
            return false;
        }
        return true;
    }
    
	int detectCycle(int V, vector<int>adj[])
	{
	    par.resize(V);
	    iota(par.begin(),par.end(),0);
	    
	    for(int i=0;i<V;i++){
    	    for(int j=0;j<adj[i].size();j++){
    	        //i<adj[i][j] to handle case for 1->2 and 2->1 not considre as cycle
    	        if(i<adj[i][j] && Union(i,adj[i][j])){
    	            return 1;
    	        }
    	    }
	    }
	    return 0;
	    
	}