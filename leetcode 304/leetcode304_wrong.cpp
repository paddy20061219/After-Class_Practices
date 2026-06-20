#include <iostream>
#include <vector>
using namespace std;

// LeetCode 304 - Range Sum Query 2D - Immutable
// Wrong version: this code is intentionally incorrect.

class NumMatrix {
private:
    vector<vector<int>> matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        // 錯誤想法：只加 row1 這一列
        // 但題目要求的是 row1 到 row2、col1 到 col2 的整個矩形範圍。
        for (int col = col1; col <= col2; col++) {
            sum += matrix[row1][col];
        }

        return sum;
    }
};
