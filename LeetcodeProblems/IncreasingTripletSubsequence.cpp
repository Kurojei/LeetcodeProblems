#include <vector>

class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int lowestValue = INT_MAX;
        int lowestIndex = INT_MAX;
        int potentialLowest = INT_MAX;
        int potentialLowestIndex = INT_MAX;

        int middleValue = INT_MAX;
        int middleIndex = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > middleValue) {
                return true;
            }

            if (nums[i] <= lowestValue) {
                if (i < middleIndex) {
                    lowestValue = nums[i];
                    lowestIndex = i;
                }

                if (nums[i] > potentialLowest) {
                    middleValue = nums[i];
                    middleIndex = i;

                    lowestValue = nums[potentialLowestIndex];
                    lowestIndex = potentialLowestIndex;
                }
                else {
                    potentialLowest = nums[i];
                    potentialLowestIndex = i;
                }
            }
            else {
                middleValue = nums[i];
                middleIndex = i;
            }
        }

        return false;
    }
};