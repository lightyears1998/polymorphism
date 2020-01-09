// 求指定字符串的回文半径
// str - 字符串
// len - 储存字符串的回文半径，注意空间大小
// n   - 字符串的长度
void manacher(char str[], int len[], int n)
{
	len[0] = 1;
	for (int i = 1, j = 0; i < (n << 1) - 1; ++i)
	{
		int p = i >> 1, q = i - p, r = ((j + 1) >> 1) + len[j] - 1;
		len[i] = r < q ? 0 : min(r - q + 1, len[(j << 1) - i]);
		while (p > len[i] - 1 && q + len[i] < n && str[p - len[i]] == str[q + len[i]])
			++len[i];
		if (q + len[i] - 1> r)
			j = i;
	}
}
