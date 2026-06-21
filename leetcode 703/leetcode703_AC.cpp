#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

// LeetCode 703 - Kth Largest Element in a Stream
// AC version

class KthLargest {
private:
    int kValue;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        kValue = k;

        for(int num : nums){
            minHeap.push(num);

            if(minHeap.size() > kValue){
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);

        if(minHeap.size() > kValue){
            minHeap.pop();
        }

        return minHeap.top();
    }
};
