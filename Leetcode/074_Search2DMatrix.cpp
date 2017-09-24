#include <vector>

class Solution {
public:
    bool searchArray(std::vector<int>& arr, int target) {
        
        // Regular binary search
        int lo = 0;
        int hi = arr.size() - 1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(arr[mid] == target) {
                return true;
            }
            else if(arr[mid] > target) {
                hi = mid - 1;
            }
            else if(arr[mid] < target) {
                lo = mid + 1;   
            }
        }
        
        return false;
    }
    
    int findRow(std::vector<std::vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        
        // Base case, no need to search
        if(target > matrix[m - 1][0]) {
            return m - 1;
        }
        
        int result = -1;
        int lo = 0;
        int hi = m - 1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if(target >= matrix[mid][0]) {
                result = mid;
                lo = mid + 1;
            }
            else if(target < matrix[mid][0]) {
                hi = mid - 1;
            }
        }
        
        return result;
    }
    
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        if(m == 0) {
            return false;
        }
        
        int n = matrix[0].size();
        if(n == 0) {
            return false;
        }
        
        // Decide which row to search
        int row = findRow(matrix, target);
        
        // If no row found, return false
        if(row == -1) return false;
        
        // Otherwise search that particular row for the target
        return searchArray(matrix[row], target);
    }
};