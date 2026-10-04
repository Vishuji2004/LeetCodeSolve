class Solution {
private:
    vector<vector<int>> dp;
    bool solve(string s, int i, int bal){
        int n = s.size();
        if(i >= n) return bal == 0;
        if(dp[i][bal] != -1) return dp[i][bal];

        char ch = s[i];
        bool ans = false;

        if(ch == '('){
            bal += 1;
            bool ans = solve(s, i+1, bal);
            bal -= 1;
            return dp[i][bal] = ans;
        }

        if(ch == ')'){
            if(bal == 0) return false;
            bal -= 1;
            bool ans = solve(s, i+1, bal);
            bal += 1;
            return dp[i][bal] = ans;
        }

        bool empty = solve(s, i+1, bal);

        bal += 1;
        bool open = solve(s, i+1, bal);
        bal -= 1;

        bool close = false;
        if(bal != 0){
            bal -= 1;
            close = solve(s, i+1, bal);
            bal += 1;
        }

        return dp[i][bal] = empty || open || close;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n+1, -1));
        return solve(s, 0, 0);
    }
};