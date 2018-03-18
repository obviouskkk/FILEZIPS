/* ***********************************************************************

  > File Name: printMatrix.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Fri 16 Mar 2018 10:38:48 PM CST

 ********************************************************************** */
#include <vector>
#include <stdio.h>
#include <iterator>


using std::vector;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) 
	{
		vector<int> ret;
		int row_end = matrix.size();
		int col_end = matrix[0].size();
        int final_size = row_end * col_end;
		if (row_end == 0 || col_end == 0)
			return ret;
		row_end -= 1;
		col_end -= 1;
		int row_begin = 0;
		int col_begin = 0;
		while (row_end >= row_begin || col_end >= col_begin) {
            if (final_size == (int)ret.size())
                break;
            if (row_end == row_begin && col_end == col_begin) { // 只有一个数字
                ret.push_back(matrix[row_begin][col_begin]);
                break;
            }
            if (row_end == row_begin) { // 只有一行
                for (int i = col_begin; i <= col_end; ++i) {
                    ret.push_back(matrix[row_begin][i]);
                }
                break;
            }
            if (col_end == col_begin) { // 只有一列
                for (int i = row_begin; i <= row_end; ++i) {
                    ret.push_back(matrix[i][col_begin]);
                }
                break;
            }
            // 打印第一行 row_begin
            for (int i = col_begin; i <= col_end; ++i) {
                ret.push_back(matrix[row_begin][i]);
            }
            row_begin ++;
            // 打印最后一列 col_end
            for (int i = row_begin; i <= row_end; ++i) {
                ret.push_back(matrix[i][col_end]);
            }
            col_end --;
            // 打印最下面一行 row_end
            for (int i = col_end; i >= col_begin; --i) {
                ret.push_back(matrix[row_end][i]);
            }
            row_end --;
            // 打印第一竖行 col_begin
            for (int i = row_end; i >= row_begin; --i) {
                ret.push_back(matrix[i][col_begin]);
            }
            col_begin ++;
		}
		return ret;
	}
};



/*
 * 特殊测试情况
 * 1. 只有一个数
 * 2. 3*4
 * 3. 4*3
 * 4. 5*5
 * 5. 2*5
 */


int main()
{
	int row_1[3] = {1, 2, 3 };
	int row_2[3] = {5, 6, 7};
	int row_3[3] = {9, 10, 11};
	int row_4[3] = {13, 14, 15};
	std::vector< vector<int> > Matrix;
    std::vector<int> VEC_1(std::begin(row_1), std::end(row_1));
    std::vector<int> VEC_2(std::begin(row_2), std::end(row_2));
    std::vector<int> VEC_3(std::begin(row_3), std::end(row_3));
    std::vector<int> VEC_4(std::begin(row_4), std::end(row_4));
    Matrix.push_back(VEC_1);
    Matrix.push_back(VEC_2);
    Matrix.push_back(VEC_3);
    Matrix.push_back(VEC_4);
    Solution ppl;
    std::vector<int > ret =  ppl.printMatrix(Matrix);
    for (auto i : ret) 
        printf("%d ", i);
    printf("\n");
	return 0;
}

