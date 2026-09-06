def subarrayProd(arr, start, end):
    if start > end:
        return 0
    return math.prod(arr[start:end + 1])   
def split_list(lst, ele):
    result = []
    current = []
    for item in lst:
        if item == ele:
            result.append(current)
            current = []
        else:
            current.append(item)
    result.append(current)
    return result
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 1 and nums[0] < 0: return nums[0]
        groups = split_list(nums, 0)
        res = 0;
        for group in groups:
            start, end = 0, len(group)-1
            while start < len(group) and group[start] > 0: start += 1
            while end >= 0 and group[end] > 0: end-= 1
            res = max(
                res,
                subarrayProd(group, 0, len(group)-1),
                subarrayProd(group, start+1, len(group)-1), 
                subarrayProd(group, 0, end-1)
            )
        return res
