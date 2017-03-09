#include <queue>
#include <pair>

bool isValidCoordinate(int x, int y, int numRows, int numCols) {
    if(x >= 0 && x < numRows && y >= 0 && y < numCols) {
        return true;
    }
    return false;
}

void markIsland(vector<vector<char>>& grid, int numRows, int numCols, int i, int j) {
    int xOffset[4] = {0, -1, 0, 1};
    int yOffset[4] = {-1, 0, 1, 0};
    
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    
    while(!q.empty()) {
        pair<int, int> curr = q.front();
        grid[curr.first][curr.second] = 2;
        q.pop();
        
        for(int k = 0; k < 4; k++) {
            int x = curr.first + xOffset[k];
            int y = curr.second + yOffset[k];
            if(isValidCoordinate(x, y, numRows,numCols)) {
                if(grid[x][y] == 1) {
                    q.push(make_pair(x, y));
                }
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int numRows = grid.size();
    int numCols = grid[0].size();
    
    int islands = 0;
    if(numRows == 0) {
        return 0;
    }
    
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            if(grid[i][j] == 1) {
                islands++;
                markIsland(grid, numRows, numCols, i, j);
            }
        }
    }
    return islands;
}