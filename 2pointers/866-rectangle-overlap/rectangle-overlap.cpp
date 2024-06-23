class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];  
        
        // x2 <= x3 when R1 is on the left of R2 and they do not intersect
        // x4 <= x1 when R2 is on the left of R1 and they do not intersect
        if(x2 <= x3 || x4 <= x1)
            return false;
        
        // y2 <= y3 when R2 is above R1 and they do not intersect
        // y4 <= y1 when R1 is above R2 and they do not intersect
        if (y2 <= y3 || y4 <= y1)
             return false;
        
        
        
        return true;
    }
};