class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currMax = 0;
        int winner = -1;

        for(int n : nums){
            if(winner == -1) {
                winner = n;
                currMax++;
                continue;
            }

            if(n == winner){
                currMax++;
            }else{
                currMax--;
                if(currMax == 0) winner = -1;
            }
        }
        return winner;
    }
};