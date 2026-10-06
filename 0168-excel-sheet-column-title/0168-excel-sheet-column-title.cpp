class Solution {
    char mp[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
public:
    string convertToTitle(int columnNumber) {
        string s;
        while(columnNumber){
            columnNumber--;
            int i = columnNumber % 26;
            s.push_back(mp[i]);
            columnNumber /= 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};