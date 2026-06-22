class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        vector<int> n(s.begin(), s.end());
        int max_len = 0;
        for (int i = 0; i < n.size(); i++) {
            int j = i + 1;
            int len = 1;
            while (j<n.size() && n[j] - n[j - 1] == 1) {
                j++;
                len++;
            }
            max_len = max(max_len, len);
            i = j-1;
        }
        return max_len;
    }
};
