class Solution {
private:
    void solve(vector<string>& res, int cnt, int count,int n,string s){
        if(n==0 && cnt==0){
            res.push_back(s);
            return ;
        }
        if(n==0){
            return;
        }
        if(cnt>0){
            solve(res,cnt-1,count,n-1,s+')');
        }
        if(cnt<count){
            solve(res,cnt+1,count,n-1,s+'(');
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>  s;
        solve(s,0,n,2*n,"");
        return s;
    }
};