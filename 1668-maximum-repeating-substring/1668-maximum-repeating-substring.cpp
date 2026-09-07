class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();
        int ans = 0;

        for(int i = 0; i <= n-m; i++){
            int cnt = 0;
            int j = i;
            while(j + m <= n && sequence.substr(j, m) == word){
                cnt++;
                j += m;
            }
            ans = max(cnt, ans);
        }
        return ans;
    }
};