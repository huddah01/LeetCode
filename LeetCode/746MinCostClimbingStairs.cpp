class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // We can use dynamic programming here as we can reach the optimal solution from
        // Find the solution of the subproblems

        // Create a vector of int to store each solution of the sub problems
        vector<int> dp(cost.size() + 1, 0);

        // Have a minCost to assign values to the vector
        int minCost = 0;

        // Iterate starting at 2 because index 0 and 1 is automatically 0
        for(int i = 2; i < cost.size() + 1; i++) {
            // Check between two steps or one step which is less
            // We compare the current cost at step i - 2 and how much it would cost
            // Step from there to the current cost at step i - 1 and how much it would
            // Cost to step from there
            if(dp[i - 2] + cost[i - 2] < dp[i - 1] + cost[i - 1]) {
                minCost = dp[i - 2] + cost[i - 2];
            }
            else {
                minCost = dp[i - 1] + cost[i - 1];
            }
            dp[i] = minCost;
        }
        // Return the last step
        return dp[cost.size()];
    }
};
