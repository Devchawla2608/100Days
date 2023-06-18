// 2328. Number of Increasing Paths in a Grid

// You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.
// Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.
// Two paths are considered different if they do not have exactly the same sequence of visited cells

int solve(int i , int j , vector<vector<int>> &grid , vector<vector<int>> &dp){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int left = 0; int right = 0; int up = 0; int down = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j>0 && grid[i][j] < grid[i][j-1]) left = solve(i , j-1 , grid, dp) + 1;

        if(j<m-1 && grid[i][j] < grid[i][j+1]) right = solve(i , j+1 , grid, dp) + 1;  
        if(i>0 && grid[i][j] < grid[i-1][j]) up = solve(i-1 , j , grid, dp) + 1;  
        if(i<n-1 && grid[i][j] < grid[i+1][j]) down = solve(i+1 , j , grid, dp) + 1;  
        return dp[i][j] = (left + right + up + down)%1000000007;
    }

    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dp(grid.size() , vector<int>(grid[0].size() , -1));
        for(int i = 0;i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size() ; j++){
                ans += solve(i , j , grid , dp);
                ans %= 1000000007;
            }
        }
        ans += grid.size()*grid[0].size();
        ans %= 1000000007;
        return ans;
    }