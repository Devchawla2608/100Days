class Solution {
public:

    void shortest_distance(vector<vector<int>>&arr){
	    int n = arr.size();
	    int m = arr[0].size();
	    for(int i = 0;i<n ; i++){
	        for(int j = 0;j<m ; j++){
	            if(arr[i][j] == -1) arr[i][j] = 1e9;
	        }
	    }
	    for(int via = 0; via<n ; via++){
    	    for(int i = 0;i<n ; i++){
	            for(int j = 0;j<m ; j++){
	                arr[i][j] = min(arr[i][j] , arr[i][via] + arr[via][j]);
	            }
	        }    
	    }
	    for(int i = 0;i<n ; i++){
	        for(int j = 0;j<m ; j++){
	            if(arr[i][j] == 1e9) arr[i][j] = -1 ;
	        }
	    }
	}

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> arr(n , vector<int>(n , 1e9));
        for(int i = 0;i<edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            arr[u][v] = w;
            arr[v][u] = w;
        }
        shortest_distance(arr);
        int ans = 1e9;
        int node = 0;
        for(int i = 0;i<n ; i++){
            int temp = 0;
            for(int j = 0;j<n ; j++){
                if( i!= j &&  arr[i][j] <=distanceThreshold){
                    temp++;
                }
            }
            if(temp<=ans){
                node = i;
                ans = temp;
            }
        }
        return node;
    }
};