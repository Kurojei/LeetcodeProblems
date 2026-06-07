#include <iostream>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        std::string smallerString;
        std::string longerString;

        if (str1.size() < str2.size() || str1.size() == str2.size()) {
            smallerString = str1;
            longerString = str2;
        }
        else {
            smallerString = str2;
            longerString = str1;
        }

        std::string substr;
        for (int i = smallerString.size(); i > 0; i--) {
            substr = smallerString.substr(0, i);
            if (isDivisibleAndTiles(substr, smallerString) &&
                isDivisibleAndTiles(substr, longerString)) {
                return substr;
            }
        }

        return "";
    }

    bool isDivisibleAndTiles(std::string substr, std::string input) {
        std::string potentialGcd;

        if (substr.empty() || input.empty()) return false;

        if (input.size() % substr.size() != 0) {
            return false;
        }

        while (potentialGcd.size() <= input.size()) {
            if (potentialGcd == input) {
                return true;
            }

            potentialGcd.append(substr);
        }

        return false;
    }
};