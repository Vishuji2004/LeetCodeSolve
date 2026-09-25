class Solution {
public:
    int calculate(string s) {
        int i = 0; int n = s.size();
        
        auto get_int = [&]() -> int {
            int num = 0;
            while(i < n){
                if(s[i] == ' ') {i++;continue;}
                if('0' <= s[i] && s[i] <= '9'){
                    num = 10*num + (s[i] - '0');
                }else break;
                i++;
            }
            return num;
        };

        stack<int> st;
        st.push(get_int());
        while(i < n){
            char ch = s[i];
            i++;
            switch(ch){
                case '+':
                    st.push(get_int());
                    break;
                case '-':
                    st.push(-get_int());
                    break;
                case '*':{
                    int num1 = st.top(); st.pop();
                    int num2 = get_int();
                    st.push((int)num1*num2);
                    break;
                }
                case '/':{
                    int num3 = st.top(); st.pop();
                    int num4 = get_int();
                    st.push(num3/num4);
                    break;
                }
                case ' ':
                    continue;
            }
        }
        
        int res = 0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};