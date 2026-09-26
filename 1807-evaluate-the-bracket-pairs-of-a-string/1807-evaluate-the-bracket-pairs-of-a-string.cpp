class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for(const auto& k : knowledge){
            dict[k[0]] = k[1];
        }

        string res;
        int i = 0;
        int n = s.size();

        while(i < n){
            char ch = s[i++];
            switch (ch){
                case '(': {
                    string k;
                    while(i < n && s[i] != ')'){
                        k.push_back(s[i]);
                        i++;
                    }
                    res.append(dict.contains(k) ? dict[k] : "?");
                    i++;
                    break;
                }
                default :
                    res.append(1, ch);
                    break;
            }
        }
        return res;
    }
};