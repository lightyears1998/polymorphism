// 删去字符串中的元音
// https://leetcode-cn.com/problems/remove-vowels-from-a-string/
// 正则表达式

function removeVowels(S: string): string {
    return S.replace(/[aeiou]/ig, '')
};
