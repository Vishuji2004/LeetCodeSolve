class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> st;
        for(char ch: s){
            switch(ch){
                case ')':{
                    if(st.size() != 1){
                        res.push_back(')');
                    }
                    st.pop();
                    break;
                }
                case '(':
                    st.push('(');
                    if(st.size() != 1) res.push_back('(');
                    break;
            }
        }
        return res;
    }
};