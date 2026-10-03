class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0; int ans = 0;
        for(char ch : s){
            if(ch == ')'){
                cnt -= 1;
                if(cnt < 0){
                    ans -= cnt;
                    cnt = 0;
                }
            }else {
                cnt += 1;
            }
        }

        ans += cnt;
        return ans;
    }
};