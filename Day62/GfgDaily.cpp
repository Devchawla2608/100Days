    void dfs(vector<vector<int>> &vis , vector<vector<char>> &arr , int n , int m , int i , int j){
        vis[i][j] = 1;
        int a[] = {i-1 , i , i+1 , i};
        int b[] = {j , j-1 , j , j+1};
        for(int k = 0 ; k<4 ; k++){
            if(a[k] <0 || b[k] <0 || a[k] >= n|| b[k] >= m) continue;
            if(vis[a[k]][b[k]] != 1 && arr[a[k]][b[k]] == 'O'){
                vis[a[k]][b[k]] = 1;
                dfs(vis , arr , n , m , a[k] , b[k]);
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> arr)
    {
        // Steps 
        // 1.) Vis 
        vector<vector<int>> vis(n  , vector<int>(m , 0));
        for(int i = 0 ;i< n ; i++){
            if(vis[i][0] != 1 && arr[i][0] == 'O'){
                dfs(vis , arr , n , m , i , 0);
            }
        }
        for(int i = 0 ;i< n ; i++){
            if(vis[i][m-1] != 1 && arr[i][m-1] == 'O'){
                dfs(vis , arr , n , m , i , m-1);
            }
        }
        for(int i = 0 ;i< m ; i++){
            if(vis[0][i] != 1 && arr[0][i] == 'O'){
                dfs(vis , arr , n , m , 0 , i);
            }
        }
        for(int i = 0 ;i< m ; i++){
            if(vis[n-1][i] != 1 && arr[n-1][i] == 'O'){
                dfs(vis , arr , n , m , n-1 , i);
            }
        }
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(vis[i][j] != 1 && arr[i][j] == 'O'){
                    arr[i][j] = 'X';
                    vis[i][j] = 1;
                }
            }
        }
        return arr;
    }