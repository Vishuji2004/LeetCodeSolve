class Solution {
public:
    int minInsertions(string s) {
        int i = 0; int n = s.size();
        long long ans = 0; long long cnt = 0;

        while(i < n){
            char ch = s[i];
            switch(ch) {
                case '(' :{
                    cnt++;
                    i++;
                    break;
                }
                case ')' :{
                    if((i+1 < n) && s[i+1] == ')'){
                        if(cnt > 0) cnt--;
                        else ans++;
                        i+=2;
                    }else{
                        if(cnt > 0) {cnt--; ans++;}
                        else ans+=2;
                        i++;
                    }
                    break;
                }
            }
        }
        if(cnt) ans = ans + 2*cnt;
        return (int)ans;
    }
};