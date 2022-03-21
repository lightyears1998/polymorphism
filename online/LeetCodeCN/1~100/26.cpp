class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = -1e5;
        auto j = nums.begin();
        for (auto i = nums.begin(); i != nums.end(); ++i) {
            if (*i != last) {
                swap(*i, *j);
                last = *j;
                ++j;
            }
        }
        return j - nums.begin();
    }
};
