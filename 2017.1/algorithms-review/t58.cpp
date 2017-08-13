class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        words = s.split(' ')
        noEmptyWords = list(filter(lambda x:x != ' ' and x != '', words))
        if len(noEmptyWords) == 0:
            return 0
        return len(noEmptyWords[-1])

sol = Solution()
print(sol.lengthOfLastWord("a "))
