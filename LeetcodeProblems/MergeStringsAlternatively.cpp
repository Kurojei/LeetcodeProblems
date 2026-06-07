#include <iostream>
#include <vector>

class Solution {
public:
	std::string mergeAlternately(std::string word1, std::string word2) {
		int firstStringIndex = 0;
		int secondStringIndex = 0;

		std::string result = "";
		int totalChars = word1.length() + word2.length();

		for (int i = 0; i < totalChars; i++) {
			if (!word1[firstStringIndex]) {
				result += word2.substr(secondStringIndex, word2.length());
				break;
			}
			if (!word2[secondStringIndex]) {
				result += word1.substr(firstStringIndex, word1.length());
				break;
			}

			if (i % 2 == 0) {
				result += word1[firstStringIndex];
				firstStringIndex++;
			}
			else {
				result += word2[secondStringIndex];
				secondStringIndex++;
			}
		}

		return result;
	}
};