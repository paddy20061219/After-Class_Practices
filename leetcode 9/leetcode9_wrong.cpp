class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return true;
        return x % 10 == x / 10;
    }
};
