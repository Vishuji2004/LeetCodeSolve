class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        auto solve = [&dp, s, t](auto &&self, int i, int j){
            if(i == s.size()){
                if(j == t.size()) return 1;
                else return 0;
            }
            if(j == t.size()) return 1;
            if(dp[i][j] != -1) return dp[i][j];

            int take = 0, skip = 0;
            if(s[i] == t[j]) take += self(self, i+1, j+1);
            skip += self(self, i+1, j);

            return dp[i][j] = take + skip;
        };

        return solve(solve, 0, 0);
    }
};