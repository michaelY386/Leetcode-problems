class Solution {
public:
    bool canFinish(int num, vector<pair<int, int>>& pre) {
        vector<vector<int>> g(num+1, vector<int>(num+1, 0));
        vector<int> in(num+1, 0);
        queue<int> q;
        
        for (auto i: pre) {
            g[i.first][i.second] = 1;
            in[i.second]++;
        }
        //if (g[0][0] == 1) return true;
        for (int i = 0; i < num; i++) {
            if (in[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int t = q.front();
                for (int j = 0; j < num; j++) {
                    if (g[t][j] == 1) {
                        //g[t][j] = 0;
                        in[j]--;
                        if (in[j] == 0 && j != t) q.push(j);
                    }
                }
                q.pop();
            }
        }
        
        for (int i = 0; i < num; i++) {
            if (in[i]!=0) return false;
        }
        return true;
    }
};