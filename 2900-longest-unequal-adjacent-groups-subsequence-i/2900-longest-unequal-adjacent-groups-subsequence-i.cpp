class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> zeroStart;
        vector<string> oneStart;

        int pre = 1;
        for(int i = 0; i < groups.size(); i++){
            if(pre && !groups[i]) {
                zeroStart.push_back(words[i]);
                pre = groups[i];
            }else if(!pre && groups[i]){
                zeroStart.push_back(words[i]);
                pre = groups[i];               
            }
        }

        pre = 0;
        for(int i = 0; i < groups.size(); i++){
            if(pre && !groups[i]) {
                oneStart.push_back(words[i]);
                pre = groups[i];
            }else if(!pre && groups[i]){
                oneStart.push_back(words[i]);
                pre = groups[i];               
            }
        }

        return oneStart.size() > zeroStart.size() ? oneStart : zeroStart;
    }
};