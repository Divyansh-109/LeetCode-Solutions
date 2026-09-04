class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int minEl = INT_MAX;
        int maxEl = INT_MIN;

        vector<int> minFromI(n, 0);

        for (int i = n-1; i >= 0; i--){
            minEl = min(minEl, nums[i]);
            minFromI[i] = minEl;
        }

        for(int i = 0; i < n; i++){
            maxEl = max(maxEl, nums[i]);
            
            if(maxEl - minFromI[i] <= k){
                return i;
            }
        }
        return -1;
    }
};
