vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        int ut=0,lt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j>i){
                    ut+=matrix[i][j];
                }
                else if(j<i){
                    lt+=matrix[i][j];
                }
                if(j==i){
                    ut+=matrix[i][j];
                    lt+=matrix[i][j];
                }
            }
        }
        return {ut,lt};
    }