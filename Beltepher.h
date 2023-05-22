#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

class Beltepher {

    struct LetterInfo {
        char letter;
        int count;
        std::vector<int> positions;
    };

    public:
        std::vector<LetterInfo> analyzeString(const std::string& normessage) {
            std::vector<LetterInfo> letters;

            for (int i = 0; i < normessage.size(); i++) {
                char c = normessage[i];

                if (isalpha(c)) {
                    auto it = std::find_if(letters.begin(), letters.end(),
                        [c](const LetterInfo& info) { return info.letter == c; });

                    if (it != letters.end()) {
                        it->count++;
                        it->positions.push_back(i + 1);
                    } else {
                        letters.push_back({ c, 1, { i + 1 } });
                    }
                }
            }

            for (const auto& info : letters) {
                std::cout << info.count << info.letter;
                for (int position : info.positions) {
                    std::cout << position;
                }
            }
        }

        std::string ROT(char message[100], int rotate) {
            message[99] = '\0';
            std::string rotatedmsg;
            for (int i = 0; message[i] != '\0'; i++) {
                if (!isdigit(message[i])) {
                    if (isupper(message[i])) {
                        rotatedmsg += (message[i] - 'A' + rotate) % 26 + 'A';
                    }
                    else if (islower(message[i])) {
                        rotatedmsg += (message[i] - 'a' + rotate) % 26 + 'a';
                    }
                }
            }
            return rotatedmsg;
        }
};