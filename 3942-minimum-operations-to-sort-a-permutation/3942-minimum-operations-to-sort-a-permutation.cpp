class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        if(n == 1) {
            return 0;
        }

        auto look = [n, nums]()->int{
            for(int i = 0; i < n; i++){
                if(nums[i] == 0) return i;
            }
            return -1;
        };

        int start = look();

        bool asc = true;
        bool desc = true;

        for(int i = 1; i < n; i++){
            int v = nums[(start + i) % n];

            if(v != i) asc = false;
            if(v != n-i) desc = false;

            if(!asc && !desc) return -1;
        }

        if(asc) return min(start, n - start + 2);
        
        return min(n - start, start + 2);
    }
}; 