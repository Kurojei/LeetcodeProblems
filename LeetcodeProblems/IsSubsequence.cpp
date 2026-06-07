#include <iostream>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int checkIndex = 0;

        if (s.empty()) return true;

        for (int i = 0; i < t.size(); i++) {
            if (s[checkIndex] == t[i]) {
                checkIndex++;
                if (checkIndex == s.size()) {
                    return true;
                }
            }
        }

        return false;
    }
};