#include <iostream>
#include <vector>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        std::vector<char> vowels;
        int vowelsEncountered = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowels.push_back(s[i]);
            }
        }

        std::reverse(vowels.begin(), vowels.end());
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[vowelsEncountered];
                vowelsEncountered++;
            }
        }

        return s;
    }

    bool isVowel(const char& letter) {
        char vowels[10] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };

        for (int i = 0; i < 10; i++) {
            if (letter == vowels[i]) {
                return true;
            }
        }

        return false;
    }
};