class Solution(object):
    def diagonalSum(self, mat):
        sum = 0
        n = len(mat)
        for i in range(len(mat)):
            sum += mat[i][i]
            if(i != n-i-1):
                sum += mat[i][n-i-1]
        return sum
        