#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LeetCode 763 - Partition Labels
// AC version

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0);

        // 先記錄每個字母最後一次出現的位置
        for(int i = 0; i < s.length(); i++){
            last[s[i] - 'a'] = i;
        }

        vector<int> ans;

        int start = 0;
        int end = 0;

        for(int i = 0; i < s.length(); i++){
            end = max(end, last[s[i] - 'a']);

            // 如果 i 走到目前這段的最右邊
            // 代表這一段可以切開
            if(i == end){
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};
