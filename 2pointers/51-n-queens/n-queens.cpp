// code for output in index of where queen needs to be placed
// class Solution {
// public:

//     bool isValid(int col, int row, int n, vector<int> curr){
//         //upper diagonal
//         int temp = row - 1;
//         for(int i=curr.size()-1;i>=0;i--){
//             if(temp<0) break;
//             if(curr[i] == temp)
//                 return false;
//             temp--;
//         }

//         //lower diagonal
//         temp = row + 1;
//         for(int i=curr.size()-1;i>=0;i--){
//             if(temp >=n) break;
//             if(curr[i] == temp)
//                 return false;
//             temp++;
//         }

//         for(int i=0;i<curr.size();i++){
//             if(curr[i] == row)
//                 return false;
//         }

//         return true;
//     }

//     void func(int col, int n, vector<int> &curr, vector<vector<int>> &ans){
//         if(col==n){
//             ans.push_back(curr);
//             return;
//         }

//         for(int row=0; row<n;row++){
//             if(isValid(col,row,n,curr)){
//                 curr.push_back(row);
//                 func(col+1, n, curr, ans);
//                 curr.pop_back();
//             }
//         }
//         return;
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<int> curr;
//         vector<vector<int>> ans;
//         vector<vector<string>> res;
//         func(0,n, curr, ans);

//         for(auto x: ans){
//             for(auto y:x){
//                 cout<<y;
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:

    bool isValid(int col, int row, int n, vector<int> curr){
        //upper diagonal
        int temp = row - 1;
        for(int i=curr.size()-1;i>=0;i--){
            if(temp<0) break;
            if(curr[i] == temp)
                return false;
            temp--;
        }

        //lower diagonal
        temp = row + 1;
        for(int i=curr.size()-1;i>=0;i--){
            if(temp >=n) break;
            if(curr[i] == temp)
                return false;
            temp++;
        }

        for(int i=0;i<curr.size();i++){
            if(curr[i] == row)
                return false;
        }

        return true;
    }

    void func(int col, int n, vector<int> &curr, vector<vector<int>> &ans){
        if(col==n){
            ans.push_back(curr);
            return;
        }

        for(int row=0; row<n;row++){
            if(isValid(col,row,n,curr)){
                curr.push_back(row);
                func(col+1, n, curr, ans);
                curr.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        vector<vector<string>> res;
        
        func(0,n, curr, ans);

        for(auto x: ans){
            vector<string> currstr;
            for(auto y:x){
                string temp = "";
                for(int i=0;i<n;i++){
                    if(i==y){
                        temp.push_back('Q');
                    } else{
                        temp.push_back('.');
                    }
                }
                currstr.push_back(temp);
            }
            res.push_back(currstr);
        }
        return res;
    }
};