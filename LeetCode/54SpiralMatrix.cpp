class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Initialize solution vector and bounds
        vector<int> soln;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int topBound = 0;
        int leftBound = 0;
        int rightBound = cols - 1;
        int botBound = rows - 1;

        // Until the solution vector is filled with every element
        while(soln.size() < rows * cols) {
            // Left to right
            for(int i = leftBound; i <= rightBound; i++) {
                // Traversing along the top of the spiral
                soln.push_back(matrix[topBound][i]);
            }
            // Top to bottom
            // We have the + 1 because we already visited that element in the previous
            // For loop
            for(int i = topBound + 1; i <= botBound; i++) {
                // Traversing down along the right side of the spiral
                soln.push_back(matrix[i][rightBound]);
            }

            // If top and bottom bounds  are equal then we squeezed the entire matrix and
            // Are done
            if(topBound != botBound) {
                // Right to left
                // We have minus one as we already visited that element in the previous
                // For loop
                for(int i = rightBound - 1; i >= leftBound; i--) {
                    // Traversing across along the bottom of the spiral
                    soln.push_back(matrix[botBound][i]);
                }
            }

            // If left and right bounds are equal then we squeezed the entire matrix
            // And are done
            if(leftBound != rightBound) {
                // Bottom to top
                // - 1 because visited in the last for loop
                for(int i = botBound - 1; i > topBound; i--) {
                    // Traversing up along the left side of the spiral
                    soln.push_back(matrix[i][leftBound]);
                }
            }

            // We squeeze the bounds
            leftBound += 1;
            rightBound -= 1;
            topBound += 1;
            botBound -= 1;
        }

        // Once we visited every element the solution vector should be in the right
        // Order so we return
        return soln;
    }
};
