class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        sliced = []
        sliced[:] = matrix[:]
        # First search for correct row
        if target == matrix[len(sliced)//2][0]:
            sliced[:] = sliced[len(sliced)//2]
        else:
            while len(sliced) > 1:
                if target < matrix[len(sliced)//2][0]:
                    sliced[:] = sliced[:len(sliced)//2]
                else:
                    sliced[:] = sliced[len(sliced)//2:]
            sliced[:] = sliced[0]
        print("sliced is", str(sliced))
        # Iterate through list to find target
        for i in sliced:
            if i == target:
                return True
        return False