class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(); int n = grid[0].size();

        if(grid[0][0] == ')') return false;
        if(grid[m-1][n-1] == '(') return false;

        unordered_map<int, bool> dp;

        auto solve = [&](auto&& self, int r, int c, int cnt) -> bool{
            if(r >= m) return false;
            if(c >= n) return false;

            char ch = grid[r][c];
            int newCnt = (ch == ')') ? cnt - 1 : cnt + 1;
            if(newCnt < 0) return false;

            if(r == m-1 && c == n-1){
                return newCnt == 0;
            }

            int key = (r << 16) | (c << 8) | cnt;
            if(dp.find(key) != dp.end()) return dp[key];

            bool down = self(self, r+1, c, newCnt);
            bool right = self(self, r, c+1, newCnt);

            return dp[key] = (down | right);
        };

        return solve(solve, 0, 0, 0);
    }
};