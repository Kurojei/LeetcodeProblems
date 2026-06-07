#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        std::vector<int> answer(nums.size());
        std::vector<int> leftProducts(nums.size(), 1);
        std::vector<int> rightProducts(nums.size(), 1);

        int cumulativeProduct = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                continue;
            }
            else {
                cumulativeProduct *= nums[i - 1];
                leftProducts[i] = cumulativeProduct;
            }
        }

        cumulativeProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                continue;
            }
            else {
                cumulativeProduct *= nums[i + 1];
                rightProducts[i] = cumulativeProduct;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            answer[i] = leftProducts[i] * rightProducts[i];
        }

        return answer;
    }
};