#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int writeIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }

        for (int j = writeIndex; j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};