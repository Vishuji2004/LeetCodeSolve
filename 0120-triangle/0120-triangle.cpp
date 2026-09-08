class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;

        for(int i = 1; i < n; i++){
            int m = dp[i].size();
            dp[i][0] += dp[i-1][0]; dp[i][m-1] += dp[i-1][m-2];
            for(int j = 1; j < m-1; j++){
                dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]);
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};