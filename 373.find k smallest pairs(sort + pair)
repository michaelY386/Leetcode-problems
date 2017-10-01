bool cmp(pair<int, int> a, pair<int, int> b) {
            return a.first+a.second < b.first+b.second;
    }  

class Solution {  
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<pair<int, int>> res;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                res.push_back({nums1[i], nums2[j]});
            }
        }
        sort(res.begin(), res.end(), cmp);
        if (res.size() > k) {
            res.erase(res.begin() + k, res.end());
        }
        return res;
    }
};