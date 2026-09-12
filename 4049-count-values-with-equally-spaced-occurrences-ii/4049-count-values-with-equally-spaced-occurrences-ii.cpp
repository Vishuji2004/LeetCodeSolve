class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> freq;
        int i = 0;
        for(int x : nums) freq[x].push_back(i++);

        int cnt = 0;
        for(auto &x: freq){
            if(x.second.size() >= 3){
                int d1 = x.second[1] - x.second[0];
                bool f = true;
                for(int j = 2; j < x.second.size(); j++){
                    if(x.second[j] - x.second[j-1] != d1){
                        f = false; break;
                    }
                }
                if(f) cnt++;
            }
        }
        return cnt;
    }
};