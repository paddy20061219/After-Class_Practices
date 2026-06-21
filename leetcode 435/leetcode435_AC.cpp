#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 435 - Non-overlapping Intervals
// AC version

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return 0;
        }

        // 依照結束時間由小到大排序
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        int removeCount = 0;
        int lastEnd = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            // 如果目前區間的開始 < 前一個保留區間的結束，代表重疊
            if(start < lastEnd){
                removeCount++;
            } else {
                lastEnd = end;
            }
        }

        return removeCount;
    }
};
