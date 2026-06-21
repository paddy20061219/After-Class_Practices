#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1893 - Check if All the Integers in a Range Are Covered
// AC version

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int num = left; num <= right; num++){
            bool found = false;

            // 檢查 num 有沒有被任何一個 range 包到
            for(int i = 0; i < ranges.size(); i++){
                int start = ranges[i][0];
                int end = ranges[i][1];

                if(start <= num && num <= end){
                    found = true;
                    break;
                }
            }

            // 只要有一個數字沒被包到，就回傳 false
            if(found == false){
                return false;
            }
        }

        return true;
    }
};
