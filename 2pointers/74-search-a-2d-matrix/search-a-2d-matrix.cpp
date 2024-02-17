class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() - 1;
        int m = matrix[0].size() - 1;
        int lowrow = 0;
        int highrow = n;
        while(lowrow < highrow){
            int midrow = lowrow + (highrow-lowrow)/2;

            if(matrix[midrow][0] == target)
                return true;
            else if(matrix[midrow][0] < target && matrix[midrow + 1][0] > target){
                lowrow = midrow;
                break;
            }
            else if(matrix[midrow][0] < target)
                lowrow=midrow+1;
            else
                highrow=midrow-1;
        }

        int lowcol = 0;
        int highcol = m;

        while(lowcol <= highcol){
            int midcol = lowcol + (highcol - lowcol)/2;
            if(matrix[lowrow][midcol] == target)
                return true;
            else if(matrix[lowrow][midcol] > target){
                highcol = midcol - 1;
            }
            else
                lowcol = midcol + 1;
        }

        return false;
    }
};