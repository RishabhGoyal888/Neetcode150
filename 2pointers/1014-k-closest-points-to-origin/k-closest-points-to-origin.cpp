class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>> > maxhp;
        for(int i=0;i<points.size();i++){
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pair<int, pair<int,int> > p = { dis, {points[i][0],points[i][1]} };
            maxhp.push(p);
            if(maxhp.size() > k) maxhp.pop();
        }
        vector<vector<int>> res;
        while(maxhp.size() > 0 ){
            vector<int> curr;
            pair<int, int> currPoint = maxhp.top().second;
            maxhp.pop();
            curr.push_back(currPoint.first);
            curr.push_back(currPoint.second);
            res.push_back(curr);
        }
        return res;
    }
};