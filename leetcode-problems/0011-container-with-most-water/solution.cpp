class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int maxWater = 0;
        while (left < right){
            int curr_width = right - left;
            int curr_height = min(height[right], height[left]);

            int area = curr_width * curr_height;
            maxWater = max(maxWater, area);

            if(height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};
