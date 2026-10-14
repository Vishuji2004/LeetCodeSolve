class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s;
        while(sum >= 9){
            s.push_back('9');
            sum -= 9;
        }

        if(sum > 0) s.push_back(sum + '0');
        
        num -= s.size();
        if(num < 0) return "";
        while(num > 0){
            s.push_back('0');
            num -= 1;
        }

        return s;
    }
};