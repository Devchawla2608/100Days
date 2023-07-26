    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dis(V , 1e8);
        dis[S] = 0;
        for(int i = 0;i<V-1 ; i++){
            for(int i = 0;i<edges.size() ; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if(dis[u] != 1e8 && dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                }
            }
        }
        bool get = false;
        for(int i = 0;i<edges.size() ; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if(dis[u] != 1e8 &&  dis[v] > dis[u] + w){
                    get = true;
                    dis[v] = dis[u] + w;
                    break;
                }
            }
        if(get == true){
            vector<int> temp;
            temp.push_back(-1);
            return temp;
        }
        return dis;
    }