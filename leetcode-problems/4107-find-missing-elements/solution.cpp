class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set <int> st (nums.begin(), nums.end());
        vector <int> result;

        int n = nums.size();
        int min = nums[0];
        int max = nums[n-1];

        for (int i = min; i < max; i++){
            if(st.find(i) == st.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};
