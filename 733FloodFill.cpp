class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Use Depth First Search to go through the image; if image pixel doesn't equal the new
        // color then we can flood fill, if it does then we don't need to flood fill
        
        // If color equals then we don't flood fill
        if(image[sr][sc] == color) {
            return image;
        }
        // Otherwise we run DFS helper method to flood fill
        DFS(image, sr, sc, image[sr][sc], color);
        // Then return altered image
        return image;

    }
    /*
    // Helper method to perform depth first search
    */
    void DFS(vector<vector<int>>& image, int sr, int sc, int oldColor, int color) {
        // Check if the pixel is equal to the old color, this means it's equal to the color
        // the original pixel floodFill was called on so we can flood fill it
        if(image[sr][sc] == oldColor) {
            // First change the color to the new color
            image[sr][sc] = color;
            // Now we perform depth first search on the four directions making sure not to
            // go out of bounds
            // Checking up
            // We can't have an index less than 0 after subtracting 1
            if(sr >= 1) {
                DFS(image, sr - 1, sc, oldColor, color);
            }
            // Checking right
            // We can technically use any index for image as the image is square
            if(sc < image[sr].size() - 1) {
                DFS(image, sr, sc + 1, oldColor, color);
            }
            // Checking down
            if(sr < image.size() - 1) {
                DFS(image, sr + 1, sc, oldColor, color);
            }
            // Checking left
            if(sc >= 1) {
                DFS(image, sr, sc - 1, oldColor, color);
            }
        }
        // If it doesn't equal original color then we don't do anything
    }
};
