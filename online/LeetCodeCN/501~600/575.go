// 分糖果
// https://leetcode-cn.com/problems/distribute-candies/

// 简单逻辑

func distributeCandies(candyType []int) int {
	sort.Slice(candyType, func(i, j int) bool {
		return candyType[i] < candyType[j]
	})

	ans := 0
	prev := int(1e7)
	for _, v := range candyType {
		if prev != v {
			ans++
			prev = v
		}
	}

	if ans < len(candyType)/2 {
		return ans
	}
	return int(len(candyType) / 2)
}
