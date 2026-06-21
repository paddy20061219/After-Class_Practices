#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// LeetCode 347 - Top K Frequent Elements
// AC version

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        // 先統計每個數字出現幾次
        for(int num : nums){
            count[num]++;
        }

        priority_queue<pair<int, int>> pq;

        // pair 的 first 放次數，second 放數字
        for(auto item : count){
            int num = item.first;
            int times = item.second;

            pq.push({times, num});
        }

        vector<int> ans;

        // 拿出出現次數最多的 k 個數字
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
