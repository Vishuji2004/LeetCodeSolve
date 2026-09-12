class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> freq;
        int i = 0;
        for(int x : nums) freq[x].push_back(i++);

        int cnt = 0;
        for(auto &x: freq){
            if(x.second.size() == 3){
                int d1 = x.second[1] - x.second[0];
                int d2 = x.second[2] - x.second[1];
                if(d1 == d2) cnt++;
            }
        }
        return cnt;
    }
};