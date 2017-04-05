class Solution(object):
  def hundredToWords(self, num):
    twn = ["One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
             "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"]
    tesn = ["Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"]
    if num <= 20:
      return twn[num-1]
    if num < 100:
      if num % 10 == 0:
        return tesn[(num // 10) - 1]
      return tesn[(num // 10) - 1] + " " + twn[num % 10 - 1]
    else:
      res = twn[(num // 100) - 1] + " Hundred"
      if num % 100 == 0:
        return res
      else:
        if num % 100 <= 20:
          return res + " " + twn[num%100 - 1]
        else:
          if (num % 100) % 10 == 0:
            return res + " " + tesn[(num%100) // 10 - 1]
          else:
            ten = (num % 100) // 10
            one = num % 10
            return res + " " + tesn[ten-1] + " " + twn[one-1]
  def numberToWords(self, num):
    if num == 0:
      return "Zero"
    quantees = ["", "Thousand", "Million", "Billion"]
    num_str = str(num)
    stages = 0
    if num < 1000:
      return self.hundredToWords(num)
    res = ""
    i = len(num_str)
    pre = False
    while (i > 0):
      left = 3 if i >= 3 else i
      if stages != 0:
        stg =  " " + quantees[stages]
      else:
        stg = ""
      if left ==3 and int(num_str[i-left:i]) < 100:
        pre = True
      else:
        pre = False
      if pre:
        andstr = " "
      else:
        andstr = " "
      if int(num_str[i-left:i]) == 0:
        pre = True
        stages += 1
        i -= left
        continue
      res = andstr + self.hundredToWords(int(num_str[i-left:i])) + stg + res
      stages += 1
      i -= left
    return res[1:] if pre else res[1:]

sol = Solution()
print(sol.numberToWords(3))
print(sol.numberToWords(12))
print(sol.numberToWords(23))
print(sol.numberToWords(123))
print(sol.numberToWords(12345))
print(sol.numberToWords(1234567))
print(sol.numberToWords(0))
print(sol.numberToWords(123000))
print(sol.numberToWords(1000010))
print(sol.numberToWords(201300))
print(sol.numberToWords(101))
