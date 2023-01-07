class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> soln;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int topBound = 0;
        int leftBound = 0;
        int rightBound = cols - 1;
        int botBound = rows - 1;

        while(soln.size() < rows * cols) {
            // Left to right
            for(int i = leftBound; i <= rightBound; i++) {
                soln.push_back(matrix[topBound][i]);
            }
            // Top to bottom
            for(int i = topBound + 1; i <= botBound; i++) {
                soln.push_back(matrix[i][rightBound]);
            }

            if(topBound != botBound) {
                // Right to left
                for(int i = rightBound - 1; i >= leftBound; i--) {
                    soln.push_back(matrix[botBound][i]);
                }
            }

            if(leftBound != rightBound) {
                // Bottom to top
                for(int i = botBound - 1; i > topBound; i--) {
                    soln.push_back(matrix[i][leftBound]);
                }
            }

            leftBound += 1;
            rightBound -= 1;
            topBound += 1;
            botBound -= 1;
        }

        return soln;
    }
};
