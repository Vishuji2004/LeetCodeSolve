class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;

        int pre = -1;
        for(int i = 0; i < groups.size(); i++){
            if(groups[i] != pre){
                ans.push_back(words[i]);
                pre = groups[i];
            }
        }

        return ans;
    }
};