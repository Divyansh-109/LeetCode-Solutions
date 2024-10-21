class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged_l = sorted(nums1 + nums2) 
        a = len(merged_l)
        if a % 2 == 0:
            med = (merged_l[a // 2 - 1] + merged_l[a // 2]) / 2
        else:
            med = float(merged_l[a // 2])

        return med
