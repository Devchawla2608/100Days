    // Transpose of Matrix
    // Write a program to find the transpose of a square matrix of size N*N. Transpose of a matrix is obtained by changing rows to columns and columns to rows.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i>=j){
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;
                }
            }
        }
    }