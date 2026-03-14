// 1582. Special Positions in a Binary Matrix
// Dificulty easy
// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<int>rowcount(row,0);
        vector<int>colcount(col,0);

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 1){
                    rowcount[i]++;
                    colcount[j]++;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 1 && rowcount[i] == 1 && colcount[j]==1){
                    count++;
                }

        
    }
}
return count;
    }
};