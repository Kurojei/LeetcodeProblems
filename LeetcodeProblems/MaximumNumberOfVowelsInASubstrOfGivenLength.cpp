#include <iostream>

class Solution {
public:
    int maxVowels(std::string s, int k) {
        int currentVowels = 0;
        int maxVowels = 0;
        int subArrayStart = 0;
        int subArrayEnd = k;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                currentVowels++;
            }
        }

        maxVowels = currentVowels;

        while (subArrayEnd <= s.size()) {
            if (currentVowels > maxVowels) {
                maxVowels = currentVowels;
            }

            if (isVowel(s[subArrayStart])) {
                currentVowels--;
            }

            if (isVowel(s[subArrayEnd])) {
                currentVowels++;
            }

            subArrayStart++;
            subArrayEnd++;
        }

        return maxVowels;
    }

    bool isVowel(const char& letter) {
        char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };

        for (int i = 0; i < 5; i++) {
            if (letter == vowels[i]) {
                return true;
            }
        }

        return false;
    }
};