    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V , 1e9);
        dis[S] = 0;
        set<pair<int , int>> st;
        st.insert({0 , S});
        while(st.size() != 0){
            int d = (*(st.begin())).first;
            int node = (*(st.begin())).second;
            st.erase((*(st.begin())));
            for(auto it : adj[node]){
                int edgeWeight = it[1];
                int edgeNode = it[0];
                if(dis[edgeNode] >  edgeWeight + d){
                    if(dis[edgeNode] != 1e9) st.erase({dis[edgeNode] , edgeNode});
                    dis[edgeNode] = edgeWeight + d;
                    st.insert({dis[edgeNode] , edgeNode});
                }
            }
        }
        return dis;
    }