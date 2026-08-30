class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minElemIdx = min_element(begin(nums), end(nums)) - begin(nums);
        int maxElemIdx = max_element(begin(nums), end(nums)) - begin(nums);

        int left = min(minElemIdx, maxElemIdx);
        int right = max(minElemIdx, maxElemIdx);

        return min({left+1+n-right, right+1, n-left});
    }
};
