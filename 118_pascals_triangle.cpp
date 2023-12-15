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