// 分糖果

// 简单逻辑

func distributeCandies(candyType []int) int {
	mp := make(map[int]int)
	for _, v := range candyType {
		mp[v] = mp[v] + 1
	}

	a1 := int(len(candyType) / 2)
	b1 := len(mp)

	if b1 < a1 {
		return b1
	}
	return a1
}
