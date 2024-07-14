class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string s1, s2;
        int h, l;
        if(x >= y){
            s1 = "ab";
            s2 = "ba";
            h = x;
            l = y;
        } else{
            s1 = "ba";
            s2 = "ab";
            h = y;
            l = x;
        }

        int ans = 0;
        vector<char> v;

        for(auto c:s){
            if(c == s1[1] && !v.empty() && v.back() == s1[0]){
                v.pop_back();
                ans += h;
            }
            else{
                v.push_back(c);
            }
        }
        vector<char> v2;
        for(auto c:v){
            if(c == s2[1] && !v2.empty() && v2.back() == s2[0]){
                v2.pop_back();
                ans += l;
            }
            else{
                v2.push_back(c);
            }
        }
        return ans;
    }
};