class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, cnt = 0, m = nums1.size(), n = nums2.size(), nn = n, mm = m;
        vector<double> mergeNum(m + n, 0);
        if (!m & !n) return 0;
        while (m && n) {
            if (nums1[i] > nums2[j]) {
                mergeNum[cnt] = nums2[j];
                j++;
                n--;
            }
            else {
                mergeNum[cnt] = nums1[i];
                i++;
                m--;
            }
            cnt++;
        }
        if (!m && n) {
            for (int k = j; k < nn; k++) {
                mergeNum[cnt] = nums2[k];
                cnt++;        
            }
        }
        if (m && !n) {
            for (int k = i ; k < mm; k++) {
                mergeNum[cnt] = nums1[k];
                cnt++;
            }
        }
        
        if ((mm + nn) % 2 == 0) {
            double res = (mergeNum[(mm+nn)/2] + mergeNum[(mm+nn)/2-1])/2;
            return res;
        }
        else return mergeNum[(mm + nn) / 2];
    }
};