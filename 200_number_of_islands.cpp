/**
 * DFS solution which I coded up without looking at the solution <3
 * 
 * Not totally optimal (can avoid the 'visited' variable).
 */
class Solution {
private:
    int _width;
    int _height;

public:
    void dfs(int i, int j, vector<vector<char>>& grid, set<int>& visited) {
        int index = i * _width + j;

        if (visited.contains(index) || i < 0 || i >= _height || j < 0 || j >= _width || grid[i][j] == '0') {
            return;
        }

        visited.insert(index);

        dfs(i - 1, j, grid, visited);
        dfs(i, j + 1, grid, visited);
        dfs(i + 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        set<int> visited;

        _height = grid.size();
        _width = grid[0].size();

        int num_islands = 0;

        for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++) {
                if (grid[i][j] == '1' && !visited.contains(i * _width + j)) {
                    num_islands += 1;
                    dfs(i, j, grid, visited);
                }
            }
        }

        return num_islands;
    }
};

/**
 * This is better. It doesn't need the 'visited' variable. 
 * 
 * Can keep track of visited by changing the grid[i][j] to '0' when we visit it.
 */
class Solution2 {
private:
    int _width;
    int _height;

public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int index = i * _width + j;

        if (i < 0 || i >= _height || j < 0 || j >= _width || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        _height = grid.size();
        _width = grid[0].size();

        int num_islands = 0;

        for (int i = 0; i < _height; i++) {
            for (int j = 0; j < _width; j++) {
                if (grid[i][j] == '1') {
                    num_islands += 1;
                    dfs(i, j, grid);
                }
            }
        }

        return num_islands;
    }
};