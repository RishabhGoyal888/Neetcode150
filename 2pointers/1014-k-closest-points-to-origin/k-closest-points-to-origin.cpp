
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>> > maxhp;
        for(int i=0;i<points.size();i++){
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxhp.push({dis,points[i]});
            if(maxhp.size() > k) maxhp.pop();
        }
        vector<vector<int>> res;
        while(maxhp.size() > 0 ){
            vector<int> curr = maxhp.top().second;
            maxhp.pop();
            res.push_back(curr);
        }
        return res;
    }
};