class Solution {
public:
    bool checkShift(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        
        for (int i = 0; i < 30; i++) {
            string st = "";
            for (int j = 0; j < s1.size(); j++) {
                char c = (s1[j] + i) % 123;
                if (c < 97) c = c + 97; 
                st = st + c;
            }
            if (s2 == st) return true;
        }
        return false;
    }
    
    vector<vector<string>> groupStrings(vector<string>& s) {
        vector<string> tmp;
        vector<int> flag(s.size(), -1);
        vector<vector<string>> res;
        int cnt = 0;
        if (s.size() == 0) return res;
        for (int i = 0; i < s.size(); i++) {
            if (flag[i] == -1) {
                flag[i] = ++cnt;
                tmp.clear();
                tmp.push_back(s[i]);
                for (int j = i + 1; j < s.size(); j++) {
                    if (checkShift(s[i], s[j])) {
                        flag[j] = cnt;
                        tmp.push_back(s[j]);
                    }
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};