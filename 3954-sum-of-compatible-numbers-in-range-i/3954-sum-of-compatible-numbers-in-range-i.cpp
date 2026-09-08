class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int start = max(1, n - k);
        int cnt = 0;
        for(int i = start; i <= n + k; i++){
            if((n&i) == 0) cnt += i;
        }
        return cnt;
    }
};