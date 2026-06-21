#include <iostream>
#include <string>
using namespace std;

// LeetCode 1143 - Longest Common Subsequence
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int count = 0;

        // 蠢錯誤：只比較同一個 index 的字元
        // 但 subsequence 可以跳過字元，不一定要在同一個位置。
        int n = min(text1.length(), text2.length());

        for(int i = 0; i < n; i++){
            if(text1[i] == text2[i]){
                count++;
            }
        }

        return count;
    }
};
