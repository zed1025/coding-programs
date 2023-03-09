# https://leetcode.com/contest/weekly-contest-332/problems/count-the-number-of-fair-pairs/
# Medium, TLE


def countFairPairs(nums, lower, upper):
    count = 0
    n = len(nums)
    for i in range(n-1):
        for j in range(i+1, n):
            if(lower <= nums[i] + nums[j] <= upper):
                count += 1
    return count

nums = [0,1,7,4,4,5]
lower = 3
upper = 6
print(countFairPairs(nums, lower, upper))