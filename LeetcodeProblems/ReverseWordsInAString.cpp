#include <iostream>
#include <vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::vector<std::string> words;
        std::string wordToPush;
        std::string reversedString{};
        bool lastCharSpace = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!lastCharSpace) {
                    words.push_back(wordToPush);
                }
                wordToPush.clear();
                lastCharSpace = true;
            }
            else {
                wordToPush += s[i];
                lastCharSpace = false;
            }
        }

        if (!lastCharSpace) {
            words.push_back(wordToPush);
        }

        for (int i = words.size() - 1; i >= 0; i--) {
            reversedString.append(words[i]);

            if (i > 0) {
                reversedString += ' ';
            }
        }

        return reversedString;
    }
};