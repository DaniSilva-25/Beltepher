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
        bool compareLetterInfo(const LetterInfo& lhs, const LetterInfo& rhs) {
            char lhsLower = std::tolower(lhs.letter);
            char rhsLower = std::tolower(rhs.letter);

            if (lhsLower == rhsLower) {
                return lhs.letter < rhs.letter; // Compare case-sensitive
            }

            return lhsLower < rhsLower; // Compare case-insensitive
        }

        std::string analyzeString(const std::string& normessage) {
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

            std::sort(letters.begin(), letters.end(), [](const LetterInfo& lhs, const LetterInfo& rhs) {
                char lhsLower = std::tolower(lhs.letter);
                char rhsLower = std::tolower(rhs.letter);

                if (lhsLower == rhsLower) {
                    return lhs.letter < rhs.letter; // Compare case-sensitive
                }

                return lhsLower < rhsLower; // Compare case-insensitive
            });

            std::string encstring;
            for (const auto& info : letters) {
                encstring += std::to_string(info.count) + info.letter; // Convert count to string
                for (int position : info.positions) {
                    encstring += std::to_string(position); // Convert position to string
                }
            }
            return encstring;
        }

        std::string ROT(const std::string& message, int shift) {
            std::string encryptedMessage;
            for (char c : message) {
                if (isalpha(c)) {
                    char base = isupper(c) ? 'A' : 'a';
                    char shiftedChar = (c - base + shift) % 26 + base;
                    encryptedMessage += shiftedChar;
                } else {
                    encryptedMessage += c;
                }
            }
            return encryptedMessage;
        }

        std::string hideShift(const std::string& rotatedmsg, int shift, int position) {
            std::string shifted;
            if (shift < 10) shifted = "R0" + std::to_string(shift);
            else shifted = "R" + std::to_string(shift);
            std::string encstring;
            
            int adjstr = position - 1;
            int endstr = position + 2;
            // Insert the shifted information at the specified position
            encstring = rotatedmsg.substr(0, adjstr) + shifted + rotatedmsg.substr(adjstr);
            
            int endPosition = position + 2;

            // Construct the final formatted string
            std::string finalString = std::to_string(position) + "-" + std::to_string(endstr) + ":" + encstring;

            return finalString;
        }

        
        std::string QuickEncrypt(std::string msg){
            std::string finalmsg = analyzeString(msg);
            int rtam = 13;
            finalmsg = ROT(finalmsg, rtam);
            int siz = finalmsg.size();
            finalmsg = hideShift(finalmsg, rtam, (siz - 3));
            return finalmsg;
        }
};