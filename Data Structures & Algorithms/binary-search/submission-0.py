class Solution:
    def search(self, nums: List[int], target: int) -> int:
        part = []
        part[:] = nums[:]
        while len(part) != 1:
            print("part is " + str(part), "nums is " + str(nums))
            if target < part[len(part)//2]:
                part[:] = part[0:len(part)//2]
            else:
                part[:] = part[len(part)//2:]
        return nums.index(part[0]) if target == part[0] else -1