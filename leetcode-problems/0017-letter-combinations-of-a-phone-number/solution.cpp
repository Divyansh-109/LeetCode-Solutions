class Solution {
public:
    vector <string> mp = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector <string> ans;

    void dfs(string &digits, int idx, string &curr){
        if (idx == digits.size()){
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for (char ch: letters){
            curr.push_back(ch);
            dfs(digits, idx+1, curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string curr;
        dfs(digits, 0, curr);
        return ans;
    }
};
