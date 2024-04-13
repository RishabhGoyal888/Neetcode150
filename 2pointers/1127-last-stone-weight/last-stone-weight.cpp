class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxhp;
        for(int i=0;i<stones.size();i++){
            maxhp.push(stones[i]);
        }

        while(maxhp.size() >= 2){
            int y = maxhp.top();
            maxhp.pop();
            int x = maxhp.top();
            maxhp.pop();
            maxhp.push(y-x);
        }
        return maxhp.top();
    }
};