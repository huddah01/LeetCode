class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initial idea: Iterate through vector and at each index find the highest profit
        // We will use a nested for loop for this, at each i we use a for loop for the remaining
        // Days and find possible profits
        // The idea had O(n^2) runtime which resulted in runtime errors, the one pass idea is faster
        // while not using more memory
        /**
        // Initialize variable for holding max profit
        int maxProfit = 0;

        // For loop to iterate through vector we can use size - 1 for the first loop since buying
        // on the last day implies no profit since we cannot sell in the future
        for(int i = 0; i < prices.size() - 1; i++) {
            // Assuming we buy on day i + 1 we check possible profits in the future
            for(int j = i + 1; j < prices.size(); j++) {
                // If profit(prices[j] - prices[i]) is higher than our current max profit then that
                // Becomes the new max profit
                if(maxProfit < prices[j] - prices[i]) {
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        // Return max profit
        return maxProfit;
        */

        // Suggested idea: Use a second variable called lowest price, with lowest price we keep the lowest
        // Buy price encounter and begin checking for profits and update max profit normally, if we ever
        // Find a variable lower than our current lowest price we can update lowest price and keep looking
        // For a max profit normally

        // Initialize variable for holding max profit and lowest buy price which will just be day 1
        int maxProfit = 0;
        int lowestBuy = prices[0];

        // Edge case of prices size 1
        if(prices.size() == 1) {
            return maxProfit;
        }

        // For loop to check for max profit
        for(int i = 1; i < prices.size(); i++) {
            // First check if buy price is lower
            if(prices[i] < lowestBuy) {
                // Then we have new lowest price
                lowestBuy = prices[i];
            }
            // Otherwise we check for max profit normally
            else if(maxProfit < prices[i] - lowestBuy) {
                // If new profit is higher than we have a new max profit
                maxProfit = prices[i] - lowestBuy;
            }
        }
        // After for loop we can just return max profit
        return maxProfit;
    }
};
