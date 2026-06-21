#include <iostream>
#include <vector>
using namespace std;

// LeetCode 860 - Lemonade Change
// AC version

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                five++;
            } else if(bills[i] == 10){
                if(five == 0){
                    return false;
                }

                five--;
                ten++;
            } else {
                // bills[i] == 20，要找 15 元

                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                } else if(five >= 3){
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
