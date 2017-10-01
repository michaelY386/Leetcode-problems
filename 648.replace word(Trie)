class Solution {
public:
    struct TrieNode {
        bool isWord = false; 
        int childCnt = 0;
        TrieNode* child[26];
        //TrieNode(): isWord(false), childCnt(0) {
            //for (auto &i : child) {
            //    i = NULL;
            //}
        //}
    };
    
    void insertTrie(string word, TrieNode *root) {
        if (!root) return;
        for (char c : word) {
            if (!root->child[c - 'a']) {
                root->child[c - 'a'] = new TrieNode();
                root->childCnt++;
            }
            root = root->child[c - 'a'];
        }
        root->isWord = true;
    }

    string findTrie(string word, TrieNode *root) {
        string res = "";
        for (char c : word) {
            if (!root->child[c - 'a'] && root->isWord == false) return word;
            if (root->child[c - 'a'] != NULL) {
                res += c;
                root = root->child[c-'a'];
            }       
            if (root->isWord) return res;
        }
        return word;
    }
          
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode *root = new TrieNode();
        int i = 0, j = 0, endf = 0;
        string ans = "";
        
        for (int k = 0; k < dict.size(); k++) {
            insertTrie(dict[k], root);
        }
        
        while (!endf) {
            while (sentence[i] != ' ' && i < sentence.size()) i++;
            if (i == sentence.size()) endf = 1;
            if (!endf) ans+=findTrie(sentence.substr(j, i - j), root) + ' ';
            else ans += findTrie(sentence.substr(j, i - j), root);
            j = ++i;
        }
        
        return ans;
    }
};