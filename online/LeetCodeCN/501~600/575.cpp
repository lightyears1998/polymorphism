// 分糖果
// https://leetcode-cn.com/problems/distribute-candies/

// 简单逻辑

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int sum = candyType.size();
        int type = 0;
        sort(candyType.begin(), candyType.end());
        auto end = unique(candyType.begin(), candyType.end());
        return min(int(end - candyType.begin()), sum / 2);
    }
};
