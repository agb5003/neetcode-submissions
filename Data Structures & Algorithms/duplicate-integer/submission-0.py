class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        newset = set(nums)
        if len(nums) != len(newset): return True
        return False