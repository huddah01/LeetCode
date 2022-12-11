class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Use dfs to go through the 2d array; We'll use a counter variable and every
        // Time we encounter a "1" we will trigger a dfs, during which we will mark the 1's
        // To 0's to signify that it was part of an island previously found

        int islands = 0;
        // Edge case empty grid
        if(grid.size() == 0) {
            return islands;
        }
        
        // Otherwise we iterate and search for islands
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                // We found an island so run dfs
                if(grid[i][j] == '1') {
                    islands += 1;
                    DFS(grid, i, j);
                }
            }
        }
        // Once we finish with nested for loop all islands should be found
        return islands;
    }
    /*
    // Helper method that runs dfs on adjacent indicies
    */
    void DFS(vector<vector<char>>& grid, int r, int c) {
        // We found a 1 so set that to 0
        grid[r][c] = '0';
        // Check the adjacent indicies and use if conditions to prevent going out of bounds
        // Checking upper
        if(r >= 1) {
            // Check that the index is part of the island
            if(grid[r - 1][c] == '1') {
                // If it is continue dfs
                DFS(grid, r - 1, c);
            }
        }
        // Checking right
        if(c < grid[r].size() - 1) {
            // Check that the index is part of the island
            if(grid[r][c + 1] == '1') {
                // If it is continue dfs
                DFS(grid, r, c + 1);
            }
        }
        // Checking down
        if(r < grid.size() - 1) {
            // Check that the index is part of the island
            if(grid[r + 1][c] == '1') {
                // If it is continue dfs
                DFS(grid, r + 1, c);
            } 
        }
        // Checking left
        if(c >= 1) {
            // Check that the index is part of the island
            if(grid[r][c - 1] == '1') {
                // If it is continue dfs
                DFS(grid, r, c - 1);
            }
        }
    }
};
