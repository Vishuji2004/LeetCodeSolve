class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans = -1;
        int i = 0;
        for(int x : nums){
            int c = 0;
            int t = x;
            while(t > 0){
                c += t%10;
                t /= 10;
            }
            if(c == i){
                ans = i;
                break;
            }
            i++;
        }
        return ans;
    }
};