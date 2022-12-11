class Solution {
public:
    int climbStairs(int n) {
        // We can use dynamic programming to solve this, we see the optimal solution
        // Can be reached from the solution of subproblems, we can reach the ith step
        // In two ways, taking a single step from i - 1, or 2 steps from i - 2

        // Base case 1
        if(n == 1) {
            return 1;
        }
        // Initialize the dp vector with size n + 1 since we don't use index 0
        vector<int> dp (n + 1, 0);
        // dp[1] has 1 path,  dp[2] has 2 paths the 1 step + 1 step and the 2 steps
        dp[1] = 1;
        dp[2] = 2;
        // Now we calculate the rest of the vector
        for(int i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        // Return the last element of the vector
        return dp[n];
    }
};
