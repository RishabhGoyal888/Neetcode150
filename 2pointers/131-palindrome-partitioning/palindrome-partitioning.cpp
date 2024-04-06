class Solution {
public:

    bool isPalindrome(int start, int end, string s){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void func(int start, int n, string s, vector<vector<string>> &ans, vector<string> &curr){
        if(start == n){
            ans.push_back(curr);
            return;
        }

        for(int i=start;i<n;i++){
            if(isPalindrome(start,i,s)){
                string temp = s.substr(start, i-start+1);
                curr.push_back(temp);
                func(i+1, n, s, ans, curr);
                curr.pop_back();
            }
        }

        return;
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        int start = 0;
        vector<vector<string>> ans;
        vector<string> curr;
        func(start, n, s, ans, curr);

        return ans;
    }
};