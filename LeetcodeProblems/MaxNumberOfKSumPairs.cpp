#include <vector>
#include <algorithm>

class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        int pairCounter = 0;
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;

        std::sort(nums.begin(), nums.end());

        while (rightIndex != leftIndex && leftIndex < rightIndex) {
            const int sum = nums[leftIndex] + nums[rightIndex];
            if (sum == k) {
                pairCounter++;
                leftIndex++;
                rightIndex--;
            }
            else {
                if (sum > k) {
                    rightIndex--;
                }
                else {
                    leftIndex++;
                }
            }
        }

        return pairCounter;
    }
};