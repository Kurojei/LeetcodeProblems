#include <iostream>
#include <vector>

class Flowerbed {
public:
	bool CanPlaceFlowers(std::vector<int>& flowerbed, int n) {
		int flowersThatCanBePlaced = 0;

		for (int i = 0; i < flowerbed.size(); i++) {
			if (flowerbed[i] == 0) {
				if (i == 0 || flowerbed[i - 1] == 0) {
					if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
						flowerbed[i] = 1;
						flowersThatCanBePlaced++;
					}
				}
			}
		}

		return flowersThatCanBePlaced >= n;
	}
};
