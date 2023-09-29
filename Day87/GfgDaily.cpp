  
  void dfs(int i , int j , vector<vector<int>> &temp , vector<vector<int>> &vis){
        vis[i][j] = 1;
        int a[] = {i-1 , i , i+1 , i};
        int b[] = {j , j -1 , j , j+1};
        for(int k = 0 ;k< 4 ;k++){
            if(a[k] <0 || a[k] >= temp.size() || b[k] < 0 || b[k] >= temp[0].size()) continue;
            if(temp[a[k]][b[k]] == 1 && vis[a[k]][b[k]] != 1){
                dfs(a[k] , b[k] , temp , vis);
            }
        }
    }
  
    int numberOfEnclaves(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        vector<vector<int>> temp = mat;
        for(int i = 0 ; i<n ; i++){
            if(mat[i][0] == 1 && vis[i][0] != 1){
                dfs(i , 0 , temp , vis);
            }
        }
        for(int i = 0 ; i<n ; i++){
            if(mat[i][m-1] == 1 && vis[i][m-1] != 1){
                dfs(i , m-1 , temp , vis);
            }
        }
        for(int i = 0 ; i<m ; i++){
            if(mat[0][i] == 1 && vis[0][i] != 1){
                dfs(0 , i , temp , vis);
            }
        }
        for(int i = 0 ; i<m ; i++){
            if(mat[n-1][i] == 1 && vis[n-1][i] != 1){
                dfs(n-1 , i , temp , vis);
            }
        }
        int count = 0;
        for(int i = 0 ;i<n ; i++){
            for(int j = 0 ;j<m ; j++){
                if(temp[i][j] == 1 && vis[i][j] != 1){
                    count++;   
                }
            }
        }
        return count;
    }