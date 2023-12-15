/**
 * My original solution which works but isn't as clean as the one below.
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int row = 0; row < numRows; row++) {
            triangle.push_back(vector<int>());

            for (int col = 0; col <= row; col++) {
                int num = 1;

                if (col > 0 && col != row) {
                    num = triangle[row - 1][col - 1] + triangle[row - 1][col];
                }

                triangle[row].push_back(num);
            }
        }

        return triangle;
    }
};

/**
 * Cleaner solution that I stole from NeetCode but technically coded myself.
 */
class SolutionBetter {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int row = 0; row < numRows; row++) {
            triangle.push_back(vector<int>(row + 1, 1));

            for (int col = 1; col < row; col++) {
                int num = triangle[row - 1][col - 1] + triangle[row - 1][col];
                triangle[row][col] = num;
            }
        }

        return triangle;
    }
};