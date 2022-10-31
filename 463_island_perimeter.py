"""
Graph problem solved using DFS. Identify piece of land to start DFS on and
call DFS on it. Base case is when we reach a boundary/water. As usual with
DFS, keep track of land we have already visited in the grid.
"""
class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        visited = set()
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return self.dfs(grid, visited, i, j)

    def dfs(self, grid, visited, i, j):
        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]) or grid[i][j] == 0:
            return 1
        
        if (i, j) in visited:
            return 0

        visited.add((i, j))

        perim = self.dfs(grid, visited, i - 1, j)
        perim += self.dfs(grid, visited, i, j + 1)
        perim += self.dfs(grid, visited, i + 1, j)
        perim += self.dfs(grid, visited, i, j - 1)

        return perim