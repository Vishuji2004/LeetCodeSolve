class Solution {
public:
    char findTheDifference(string s, string t) {
        string n = s + t;
        int c = 0;
        for(char ch : n){
            c ^= (ch - 'a');
        }
        return c + 'a';
    }
};