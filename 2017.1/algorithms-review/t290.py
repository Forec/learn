class Solution1(object):
    def wordPattern(self, pattern, str):
        words = list(filter(lambda x : len(x) >= 1, str.split(' ')))
        wordDict = {}
        patDict = {}
        if len(pattern) != len(words):
            return False
        for i in range(0, len(pattern)):
            p = pattern[i]
            word = words[i]
            if wordDict.get(p) is None and patDict.get(word) is None:
                wordDict[p] = word
                patDict[word] = p
            elif wordDict.get(p) != word or patDict.get(word) != p:
                return False
        return True

q = Solution()
print(q.wordPattern("abc", "b c a"))

