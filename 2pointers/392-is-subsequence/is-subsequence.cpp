class Solution {
public:
    bool isSubsequence(string s, string t) {
        // write your code here
        int n = t.size();
        int m = s.size();
        int j=0;
        for(int i=0;i<n && j<m;i++){
            if(t[i] == s[j]){
                j++;
            }
        }
        if(j == m) return true;
        return false;
    }
};