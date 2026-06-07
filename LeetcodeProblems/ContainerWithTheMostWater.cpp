#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int highestVolume = 0;
        int leftIndex = 0;
        int rightIndex = height.size() - 1;

        for (int i = 0; i < height.size(); i++) {
            int waterHeight = std::min(height[leftIndex], height[rightIndex]);
            int indexDifference = rightIndex - leftIndex;
            int newVolume = waterHeight * indexDifference;

            if (newVolume > highestVolume) {
                highestVolume = newVolume;
            }

            if (waterHeight == height[leftIndex]) {
                leftIndex++;
            }
            else
            {
                rightIndex--;
            }

            if (leftIndex == rightIndex) {
                break;
            }
        }

        return highestVolume;
    }
};