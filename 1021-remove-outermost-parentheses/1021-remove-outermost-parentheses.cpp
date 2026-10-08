class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int cnt = 0;
        for(char ch: s){
            switch(ch){
                case ')':{
                    if(cnt != 1){
                        res.push_back(')');
                    }
                    cnt--;
                    break;
                }
                case '(':
                    cnt++;
                    if(cnt != 1) res.push_back('(');
                    break;
            }
        }
        return res;
    }
};