from functools import lru_cache
class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dp = [[set() for _ in range(m)] for _ in range(n)]
        def dfs(r, c, XOR):
            XOR = XOR^grid[r][c]
            if XOR in dp[r][c]:
                return

            dp[r][c].add(XOR)

            if r == n-1 and c == m-1: return
            if r+1 < n:
                dfs(r+1, c, XOR)
            if c+1 < m:
                dfs(r, c+1, XOR)

        dfs(0, 0, 0)
        return min(dp[n-1][m-1])
        