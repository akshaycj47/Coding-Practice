#include <vector>
#include <iostream>

class Solution {
public:
    // Check if given value is already present in the row
    bool checkRow(std::vector<std::vector<char>>& board, int row, char val) {
    
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == val) {
                return false;
            }
        }
        return true;
    }
    
    // Check if given value is already present in the column
    bool checkCol(std::vector<std::vector<char>>& board, int col, char val) {
        
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == val) {
                return false;
            }
        }
        return true;
    }
    
    // Check if given value is already present in the box
    bool checkBox(std::vector<std::vector<char>>& board, int i, int j, char val) {
        
        // Calculate start indices of the box
        int start_i = (i / 3) * 3;
        int start_j = (j / 3) * 3;
        
        // Start checking
        for(int x = start_i; x < start_i + 3; x++) {
            for(int y = start_j; y < start_j + 3; y++) {
                if(board[x][y] == val) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    // Check if current move is safe or not
    bool isSafe(std::vector<std::vector<char>>& board, int i, int j, char val) {
        
        return checkRow(board, i, val) && checkCol(board, j, val) && checkBox(board, i, j, val);
    }

    bool solveSudokuUtil(std::vector<std::vector<char>>& board, int pos, int i, int j) {
        
        // If we reach the end of the board
        if(pos == 81) return true;
        
        // If the current position is already occupied (i.e. not blank)
        if(board[i][j] != '.') {
            return solveSudokuUtil(board, pos + 1, (pos + 1) / 9, (pos + 1) % 9);
        }
        
        // Try out all valid numbers for current blank position
        for(int k = 1; k <= 9; k++) {
            
            char curr = k + '0';
            if(isSafe(board, i, j, curr)) {
                board[i][j] = curr;
                
                if(solveSudokuUtil(board, pos + 1, (pos + 1) / 9, (pos + 1) % 9)) {
                    return true;
                }
                else {
                    board[i][j] = '.';                               // Backtracking
                }
            }
        }
        return false;
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        
        // Remove edge cases
        if(board.size() != 9 || board[0].size() != 9) {
            return;
        }
        
        // Start from the first position of Sudoku
        if(solveSudokuUtil(board, 0, 0, 0) == false) {
            std::cout << "Sudoku solution cannot be found\n";
        }
        
        return;
    }
};