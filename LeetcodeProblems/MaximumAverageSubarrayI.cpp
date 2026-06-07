#include <vector>

class Solution {
    double findMaxAverage(const std::vector<int>& nums, const int& k) {
        double maxSum = -INFINITY;
        int subArrayStart = 0;
        int subArrayEnd = k;

        if (k >= nums.size()) {
            return CalculateSum(nums, nums.size()) / k;
        };

        double sum = CalculateSum(nums, k);
        while (subArrayEnd <= nums.size()) {
            if (sum > maxSum) {
                maxSum = sum;
            }

            sum -= nums[subArrayStart];
            sum += nums[subArrayEnd];

            subArrayStart++;
            subArrayEnd++;
        }

        return maxSum / k;
    }

    double CalculateSum(const std::vector<int>& nums, const int& end) {
        double currentAverage = 0;

        for (double i = 0; i < end; i++) {
            currentAverage += nums[i];
        }

        return currentAverage;
    }
};