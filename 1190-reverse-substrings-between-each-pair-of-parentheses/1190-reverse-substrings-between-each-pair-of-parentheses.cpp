class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string res; stack<char> st;

        for(int i = 0; i < n; i++){
            if(st.empty() && s[i] != '('){
                res.push_back(s[i]);
            }else if(s[i] == ')'){
                string t;
                while(st.top() != '('){
                    t.push_back(st.top());
                    st.pop();
                }
                st.pop();
                if(st.empty()) res.append(t);
                else {
                    for(char ch : t) st.push(ch);
                }
            }else{
                st.push(s[i]);
            }
        }
        return res;
    }
};