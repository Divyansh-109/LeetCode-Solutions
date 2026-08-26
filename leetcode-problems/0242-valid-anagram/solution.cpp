class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        int x[26] = {0};
        for (int i = 0; i < s.size(); i++){
            x[s[i]-'a']++;
            x[t[i]-'a']--;
        }
        for (auto it: x){
            if (it != 0){
                return false;
            }
        }
        return true;
    }
};
