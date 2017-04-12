#include <vector>

class Solution {
public:
    bool checkValidRow(std::vector<std::vector<char>>& board, int row) {
        
        // Create a map to check if any numbers are repeated
        std::vector<bool> m(9, false);
        
        // Start checking
        for(int i = 0; i < 9; i++) {
            char curr = board[row][i];
            if(curr == '.') continue;
            
            if(m[curr - '0'] == true) {
                return false;
            }
            else {
                m[curr - '0'] = true;
            }
        }
        return true;
    }
    
    bool checkValidCol(std::vector<std::vector<char>>& board, int col) {
        
        // Create a map to check if any numbers are repeated
        std::vector<bool> m(9, false);
        
        // Start checking
        for(int i = 0; i < 9; i++) {
            char curr = board[i][col];
            if(curr == '.') continue;
            
            if(m[curr - '0'] == true) {
                return false;
            }
            else {
                m[curr - '0'] = true;
            }
        }
        return true;
    }
    
    bool checkValidBox(std::vector<std::vector<char>>& board, int box_i, int box_j) {
        
        // Create a map to check if any numbers are repeated
        std::vector<bool> m(9, false);
        
        // Start checking
        for(int i = box_i; i < box_i + 3; i++) {
            for(int j = box_j; j < box_j + 3; j++) {
                
                char curr = board[i][j];
                if(curr == '.') continue;
                
                if(m[curr - '0'] == true) {
                    return false;
                }
                else {
                    m[curr - '0'] = true;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        
        // Any suduko board is not valid if number of rows and number of columns are not 9
        if(board.size() != 9 || board[0].size() != 9) {
            return false;
        }
        
        // Check if all rows are valid
        for(int row = 0; row < 9; row++) {
            if(checkValidRow(board, row) == false) return false;
        }
        
        // Check if all columns are valid
        for(int col = 0; col < 9; col++) {
            if(checkValidCol(board, col) == false) return false;
        }
        
        // Check if all boxes are valid
        for(int box = 0; box < 9; box++) {
            int box_i = (box / 3) * 3;
            int box_j = (box * 3) % 9;
            if(checkValidBox(board, box_i, box_j) == false) return false;
        }
        
        return true;
    }
};