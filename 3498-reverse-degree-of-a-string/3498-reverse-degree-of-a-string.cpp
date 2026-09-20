class Solution {
public:
    int reverseDegree(string s) {
        int tot = 0;
        int i = 1;
        for(char c : s){
            int n = 26 - (c - 'a');
            tot += n*i;
            i++;
        }
        return tot;
    }
};