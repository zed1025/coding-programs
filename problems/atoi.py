

class Solution:
	def myAtoi(self, s: str) -> int:
		sign,num,flag = 1,0,0
		s = s.strip()
		if len(s) == 0: return 0
		if s[0] == "-":
			sign = -1
		for i in s:
			if i.isdigit():
				num = num*10 + int(i)
				flag = 1
			elif (i == "+" or i == "-") and (flag == 0):
				flag = 1
				pass
			else: break
		num = num*sign
		if (-2**31<=num<=(2**31)-1): return num
		if num<0: return -2**31
		else: return 2**31-1

	def myAtoi2(self, s: str) -> int:
    	INT_MAX = pow(2,31) - 1 
		INT_MIN = -pow(2,31)

		s = s.strip()
		num = 0

		# 0 means "+" | 1 means "-" | and more than 1 mean -> "-+..."
		sign = 0    

		for i in range(len(s)):  
			# If s[i] is a sign, we need to make sure it's either at index 0 or had another sign before it,
			# Example 1: consider '00000-42absc' this is invalid because the sign is not in the beginning,
			# but if we set sign to 1, it will be assigned to the result which is wrong!
			if s[i] in ["+", "-"] and sign == 0 and i == 0:
				if s[i] == "-": sign += 1 
				else: continue

			elif s[i].isnumeric():
				# Check overflow and underflow conditions. 
				if ((num > INT_MAX // 10) or (num == INT_MAX // 10 and int(s[i]) > INT_MAX % 10)):
					return INT_MIN if sign == 1 else INT_MAX
				
				num = num * 10 + int(s[i])
				
			# break if we found a non numeric value
			else: break
				
		return -num if sign == 1 else num


s = Solution()
myStr = ["42", "   -42", "4193 with words", "words and 987", "", "-", "+9", "21474836460"]
x = s.myAtoi2(myStr[7])
print(x, type(x))    