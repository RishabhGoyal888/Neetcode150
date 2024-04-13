class Solution {
public:
    void dfs(string digits, unordered_map<char, string> &mp, vector<string> &res, int index, string &curr, int n){
        if(index == n){
            res.push_back(curr);
        }
        string temp = mp[digits[index]];
        int size = temp.length();
        for(int i=0;i<size;i++){
            curr.push_back(temp[i]);
            dfs(digits, mp, res, index + 1, curr, n);
            curr.pop_back();
        }
        return;

    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0){
            return res;
        }
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        int n = digits.length();
        string curr;
        dfs(digits, mp, res, 0, curr, n);
        return res;
    }
};