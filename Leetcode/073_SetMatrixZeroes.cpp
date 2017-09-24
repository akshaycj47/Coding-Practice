class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        
        // Store states of each row and column in the first row and column.
        // For the first column, use a new variable
        for(int i = 0; i < m; i++) {
            if(matrix[i][0] == 0) col0 = 0;
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        // Start making the rows and columns 0 based on first row and column,
        // don't forget col0
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 1; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if(col0 == 0) matrix[i][0] = 0;
        }
    }
};