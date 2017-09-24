class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Base cases
        int m = matrix.size();
        if(m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if(n == 0) {
            return false;
        }
        
        // We start search the matrix from top right corner, initialize the current position to top right corner, 
        // if the target is greater than the value in current position, then the target can not be in entire row 
        // of current position because the row is sorted, if the target is less than the value in current position, 
        // then the target can not in the entire column because the column is sorted too. We can rule out one row 
        // or one column each time, so the time complexity is O(m+n).
        int i = 0;
        int j = n - 1;
        
        while(i < m && j >= 0) {
            if(target == matrix[i][j]) {
                return true;
            }
            else if(target < matrix[i][j]) {
                j--;
            }
            else if(target > matrix[i][j]) {
                i++;
            }
        }
        
        return false;
    }
};