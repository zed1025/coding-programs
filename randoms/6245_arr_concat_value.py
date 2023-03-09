# https://leetcode.com/contest/weekly-contest-332/problems/find-the-array-concatenation-value/
# Easy, AC

def solution(nums):
    n = len(nums)
    ans = 0
    j = n-1
    i = 0
    for i in range(n//2):
        if i>j:
            break
        j = j-1
        num1 = "{}".format(nums[i])
        num2 = "{}".format(nums[n-i-1])
        temp = num1+num2
        temp = int(temp)
        ans += temp

    # print(i, j)

    if n%2 != 0:
        ans += nums[i+1]

    return ans
    

nums1 = [7,52,2,4]
nums2 = [5,14,13,8,12]
print(solution(nums1))
print(solution(nums2))