class Solution {
public:
    int kthFactor(int n, int k) {
        int ans = -1;
        auto solve = [&](int n, int k){
            for(int i = 1; i <= n; i++){
                if(n % i == 0) {
                    k--;
                    if(k == 0) {
                        ans = i;
                        break;
                    }
                }
            }
        };
        solve(n, k);
        return ans;
    }
};