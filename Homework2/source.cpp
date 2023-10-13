#include "Header.h"
#include<iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<int>> data1 = { {1, 2}, {3, 4} };
    Matrix<int> mat1(data1);

    vector<vector<int>> data2 = { {5, 6}, {7, 8} };
    Matrix<int> mat2(data2);

    cout << "Matrix 1:\n" << mat1;
    cout << "Matrix 2:\n" << mat2;

    Matrix<int> sum = mat1 + mat2;
    Matrix<int> product = mat1 * mat2;
    Matrix<int> scaled = mat1 * 2;

    cout << "Matrix 1 + Matrix 2:\n" << sum;
    cout << "Matrix 1 * Matrix 2:\n" << product;
    cout << "Matrix 1 * 2:\n" << scaled;

    return 0;
}
