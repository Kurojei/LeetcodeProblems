#include <iostream>
#include <vector>

class Candies {
public:
	std::vector<bool> kidsWithCandies(const std::vector<int>& candies, const int extraCandies) {
		int currentBiggest = 0;
		int biggestWithoutExtra = 0;
		std::vector<bool> kidsWithCandies;
		for (int i = 0; i < candies.size(); i++) {
			if (candies[i] >= biggestWithoutExtra) {
				biggestWithoutExtra = candies[i];
			}
		}

		for (int kid : candies) {
			if (kid + extraCandies >= biggestWithoutExtra) {
				kidsWithCandies.push_back(true);
			}
			else {
				kidsWithCandies.push_back(false);
			}
		}

		return kidsWithCandies;
	}
};