class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0, cnt = 0;

        for(char ch : s){
            switch(ch){
                case '(':{
                    st.push(cnt);
                    cnt = 0;
                    break;
                }case ')':{
                    if(!st.empty()){
                        int prev = st.top(); st.pop();
                        cnt += (2+prev);
                        ans = max(ans, cnt);
                    }else{
                        cnt = 0;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};