class Solution {
public:
    int uniquePaths(int m, int n) {
        // Use dynamic programming noting that dp[n][m] = dp[m-1][n] + dp[m][n-1]

        // Create the 2d vector
        vector<vector<int>> dp(m, vector<int>(n));
        
        // Initialize the start of the 2d vector we know the robot has only 1 unique path to
        // The right end and to the bottom end of the vector
        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for(int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        // Now we populate the 2d vector starting at 1
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Return the bottom left element to get all unique paths
        return dp[m - 1][n - 1];
    }
};
