class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (unsigned i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }
        for (unsigned i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int add = target - num;
            if (mp.find(add) != mp.end() && mp[add] != i) {
                return vector<int> {int(i), mp[add]};
            }
        }
        return {};
    }
};
