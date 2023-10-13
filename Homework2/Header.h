#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Matrix
{
private:
	vector<vector<T>> data;
	int rows;
	int cols;

public:
	Matrix(int n, int m);//零矩阵
	Matrix(vector<vector<T>>& input_data);//自定义矩阵
	Matrix<T> operator+(const Matrix<T>& b_mat);//矩阵加法
	Matrix<T> operator*(const Matrix<T>& b_mat);//矩阵乘法
	Matrix<T> operator*(const T scalar);//矩阵数乘

	friend ostream& operator<<(ostream& os, const Matrix& mat) {//矩阵输出
		for (int i = 0; i < mat.rows; ++i) {
			for (int j = 0; j < mat.cols; ++j) {
				os << mat.data[i][j] << " ";
			}
			os << std::endl;
		}
		return os;
	}
		
};

template <typename T> Matrix<T>::Matrix(int n, int m) :rows(n), cols(m)
{
	data.resize(rows, vector<T>(cols, 0));
}

template <typename T> Matrix<T>::Matrix(vector<vector<T>>& input_data)
{
	rows = input_data.size();
	cols = input_data[0].size();
	data = input_data;
}

template <typename T> Matrix<T> Matrix<T>::operator+(const Matrix<T>& b_mat)
{
	if (rows != b_mat.rows || cols != b_mat.cols)
	{
		cout << "They have different rows and columes,cannot be added" << endl;

	}
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result.data[i][j] = data[i][j] + b_mat.data[i][j];
		}
	}
	return result;
}

template <typename T> Matrix<T> Matrix<T>::operator*(const Matrix<T>& b_mat)
{
	if (cols != b_mat.rows)
	{
		cout << "They have different rows and colume,cannot be multiplied." << endl;
	}
	Matrix result(rows, b_mat.cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < b_mat.cols; j++)
		{
			for (int k = 0; k < cols; k++)
			{
				result.data[i][j] += data[i][k] * b_mat.data[k][j];
			}
		}
	}
	return result;
}

template <typename T> Matrix<T> Matrix<T>::operator*(const T scalar)
{
	Matrix result(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			result.data[i][j] = data[i][j] * scalar;
		}
	}
	return result;
}


