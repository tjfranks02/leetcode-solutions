"""
DFS graph problem. Locate a starting land tile to begin dfs from.
Then, dfs will mark all tiles in that particular island visited
by checking above, left, right and down tiles. 

Then, we iteratively find another land tile that hasn't yet been
visited and call dfs on this. Because this land tile has not yet
been visited, we know it must be part of a new island.
"""
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        visited = set()
        num_islands = 0

        def dfs_visit(i, j):
            if (i, j) in visited or i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] == '0':
                return

            if grid[i][j] == '1':
                visited.add((i, j))
                dfs_visit(i, j - 1)
                dfs_visit(i + 1, j)
                dfs_visit(i, j + 1)
                dfs_visit(i - 1, j)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (i, j) not in visited and grid[i][j] == '1':
                    num_islands += 1
                    dfs_visit(i, j)
        return num_islands