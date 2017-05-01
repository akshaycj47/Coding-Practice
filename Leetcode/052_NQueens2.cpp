#include <vector>
#include <string>

class Solution {
public:
    // Check if queen can be placed on this location or not
    bool isValidMove(std::vector<std::string>& board, int row, int col, int n) {
        
        // Check vertical top side
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') return false;
        }
        
        // Check top left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        
        // Check top right diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
    }

    // Utility function to solve N queens problem
    void solveNQueensUtil(std::vector<std::string>& board, int n, int row, int& count) {
        
        // If all queens are placed, then return true
        if(row >= n) {
            count++;
        }
        
        for(int i = 0; i < n; i++) {
            
            // Check if queen can be placed on the board
            if(isValidMove(board, row, i, n)) {
                
                // Place a queen on this position
                board[row][i] = 'Q';

                // Check if it generates a correct solution
                solveNQueensUtil(board, n, row + 1, count);
                
                // Backtrack, remove queen from the board
                board[row][i] = '.';
            }
        }
        
        return;
    }

    int totalNQueens(int n) {
        
        // Final count
        int count = 0;
        
        // First create the solution board
        std::vector<std::string> board;
        for(int i = 0; i < n; i++) {
            std::string row = "";
            for(int j = 0; j < n; j++) {
                row.push_back('.');
            }
            board.push_back(row);
        }
        
        // Solve N-Queens
        solveNQueensUtil(board, n, 0, count);
        
        return count;
    }
};