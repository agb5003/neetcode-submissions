class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        listS = sorted(s)
        listT = sorted(t)
        return True if listS == listT else False