class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0; string repeated = word;
        while(sequence.find(repeated) != string::npos){
            ans++;
            repeated += word;
        }
        return ans;
    }
};