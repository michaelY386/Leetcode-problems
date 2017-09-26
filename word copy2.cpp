class Solution {
public:
    void isMatch(int p1, int p2, string p, string s, unordered_map<char, string> &hash, bool &f) {
        if (p1 == p.length() && p2 == s.length()) { f = true; return; } 
        if (p1 == p.length() && p2 != s.length()) return;
        if (p1 != p.length() && p2 == s.length()) return;
        char c = p[p1];
        int i, len;
        if (hash.find(c)!=hash.end()) {
            string t = hash[c];
            len = t.length();
            for (i = 0; i < len; i++) {
                if ((p2 + i) >= s.length()) return;
                if (s[p2 + i] != t[i]) return;          
            }
            p2+=i;
            p1++;
            isMatch(p1, p2, p, s, hash, f);
        }
        // a new pattern
        else {
            for (i = p2; i < s.length(); i++) {
                int ff = 0;
                string tt = s.substr(p2, i+1-p2);
                for (auto j : hash) if (j.second == tt) { ff = 1; }
                if (!ff) {
                    hash[c] = tt;
                    isMatch(p1+1, i+1, p, s, hash, f);
                    hash.erase(c);
                }
            }
        }
        return;
    }
    
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> hash;
        bool f = false;
        isMatch(0, 0, pattern, str, hash, f);
        return f;
    }
};