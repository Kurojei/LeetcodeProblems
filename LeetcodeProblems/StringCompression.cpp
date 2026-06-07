#include <iostream>
#include <vector>
#include <string>

class StringCompression {
public:
    int compress(std::vector<char>& chars) {
        int currentCharCount = 0;
        char currentChar = ' ';
        char prevChar = ' ';
        int lastWriteIndex = 0;

        for (int i = 0; i < chars.size(); i++) {
            currentChar = chars[i];

            if (currentChar != prevChar && prevChar != ' ') {
                if (currentCharCount > 1) {
                    chars[lastWriteIndex] = prevChar;
                    lastWriteIndex++;

                    std::string charCount = std::to_string(currentCharCount);

                    for (int i = 0; i < charCount.size(); i++) {
                        chars[lastWriteIndex] = charCount[i];
                        lastWriteIndex++;
                    }
                }
                else {
                    chars[lastWriteIndex] = prevChar;
                    lastWriteIndex++;
                }

                currentCharCount = 1;
            }
            else {
                currentCharCount++;
            }

            prevChar = currentChar;
        }

        if (currentCharCount > 1) {
            chars[lastWriteIndex] = prevChar;
            lastWriteIndex++;
            std::string charCount = std::to_string(currentCharCount);

            for (int i = 0; i < charCount.size(); i++) {
                chars[lastWriteIndex] = charCount[i];
                lastWriteIndex++;
            }
        }
        else {
            chars[lastWriteIndex] = prevChar;
            lastWriteIndex++;
        }

        return lastWriteIndex;
    }
};