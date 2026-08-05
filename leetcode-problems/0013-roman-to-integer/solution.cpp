class Solution {
public:
    int romanToInt(string s) {
        int val[128] = {};
        val['M'] = 1000;
        val['D'] = 500;
        val['C'] = 100;
        val['L'] = 50;
        val['X'] = 10;
        val['V'] = 5;
        val['I'] = 1;

        int ans = 0;
        for (int i = 0; i < s.size(); i++){
            if (i + 1 < s.size() && val[s[i]] < val[s[i+1]]){
                ans -= val[s[i]];
            } else {
                ans += val[s[i]];
            }
        }
        return ans;
    }
};
