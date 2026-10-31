class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        vector<int> dp(grid[0].size());
        dp[0] = 1;

        for(auto& row: grid){
            int r = 0;
            for(int i = 0; i < row.size(); i++){
                if(row[i]){
                    swap(r, dp[i]);
                }else{
                    dp[i] = r = (dp[i] + r) % MOD;
                }
            }
        }

        return dp.back();
    }
};