class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i+1; j < (i + n); j++){
                if(s[(j-1)%n] == s[j%n]){
                    cnt++;
                }
            }
            if(cnt == k) ans++;
        }
        return ans;
    }
};