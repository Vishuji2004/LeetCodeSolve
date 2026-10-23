class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int r = 0; bool f = true;
        for(int i = 0; i < n; i++){
            if(nums[i] != i) {
                if(f){
                    r |= nums[i];
                    f = false;
                } else r &= nums[i];
            }
        }
        return r;
    }
};