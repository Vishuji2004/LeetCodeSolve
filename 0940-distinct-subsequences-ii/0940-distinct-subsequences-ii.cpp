#define MOD 1000000007
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n+1, 1);
        unordered_map<char, int> used;
        for(int i = 0; i < n; i++){
            char last = s[i];
            dp[i+1] = (2*dp[i])%MOD;
            if(used.contains(last)){
                dp[i+1] -= dp[used[last]];
            }
            dp[i+1] %= MOD;
            used[last] = i;
        }
        dp[n]--;
        if(dp[n] < 0) dp[n] += MOD;
        return dp[n];
    }
};