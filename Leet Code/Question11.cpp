class Solution {
public:
    int maxArea(std::vector<int>& height) {

    // A variable maxValue Storing the maxValue of the area
        int maxValue = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j) {
            //min and max functions from the algorithem header file
            int minHeight = min(height[i], height[j]);
            int width = j - i;

            int area = minHeight * width;

            maxValue = max(maxValue, area);

            if (height[i] < height[j]) {
                i++;
            } else if (height[j] < height[i]) {
                j--;
            } else {
                i++;
                j--;
            }
        }

        return maxValue;
    }
};
