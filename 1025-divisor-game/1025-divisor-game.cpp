class Solution {
private: 
    unordered_map<int, bool> memoA;
    unordered_map<int, bool> memoB;
    bool alice(int n){
        if(n == 1) return false;
        if(memoA.count(n)) return memoA[n];
        bool ans = false;
        for(int i = 1; i <= (n+1)/2; i++){
            if(n%i == 0){
                ans |= !bob(n-i);
                if(ans) break;
            }
        }
        return memoA[n] = ans;
    }

    bool bob(int n){
        if(n == 1) return false;
        if(memoB.count(n)) return memoB[n];
        bool ans = false;
        for(int i = 1; i <= (n+1)/2; i++){
            if(n%i == 0){
                ans |= !alice(n-i);
                if(ans) break;
            }
        }
        return memoB[n] = ans;
    }
public:
    bool divisorGame(int n) {
        return alice(n);
    }
};