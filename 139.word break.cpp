class Solution {
public:
    /*void wordHelper(string s, int p, set<string>& wordSet, bool &f) {
        if (p == s.length()) {
            f = true;
            return;
        }
        for (int i = p; i < s.size(); i++) {
            string toFind = s.substr(p, i - p + 1);
            if (wordSet.count(toFind)!=0) {
                    wordHelper(s, i + 1, wordSet, f);
                }
        }
        return;
    }
    */
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet;
        bool f = false;
        vector<bool> res(s.size(), false);
        
        for (int i = 0; i < wordDict.size(); i++) {
            wordSet.insert(wordDict[i]);
        }
        //wordHelper(s, 0, wordSet, f);
        //return f;
        //if (wordSet.count(s.substr(0, 1))!=0) res[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (wordSet.count(s.substr(0, i+1))!=0) {
                res[i] = true;
                //continue;
            }
            for (int j = 0; j < i; j++) {
                if (res[j] && (wordSet.count(s.substr(j+1, i-j))!=0)) res[i] = true;
            }
        }
        return res[s.size()-1];
    }
};