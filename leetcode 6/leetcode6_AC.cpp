#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LeetCode 6 - Zigzag Conversion
// Correct version

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int currentRow = 0;
        int direction = 1;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0) {
                direction = 1;
            } else if (currentRow == numRows - 1) {
                direction = -1;
            }

            currentRow += direction;
        }

        string ans = "";
        for (string row : rows) {
            ans += row;
        }

        return ans;
    }
};
