class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        for(char ch : s){
            int x = (ch - 'A') + 1;
            ans = ans*26 + x;
        }
        return ans;
    }
};