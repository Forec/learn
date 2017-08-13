class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        def num2perm(num, p):
            p = sorted(p)
            b = p[:]
            n = len(p)
            for i in range(n-1, -1, -1):
                p[i] = num % (n-i)
                num = num // (n-i)
            for i in range(n-1, -1, -1):
                for j in range(i-1, -1, -1):
                    if p[j] <= p[i]:
                        p[i] +=1
            for i in range(n):
                p[i] = b[p[i]]
            return list(map(lambda x:str(x), p))
        return ''.join(num2perm(k-1, [i for i in range(1, n+1)]))

sol = Solution()
print(sol.getPermutation(3, 4))
