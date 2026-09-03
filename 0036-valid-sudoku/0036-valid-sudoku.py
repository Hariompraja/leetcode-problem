class Solution(object):
    def isValidSudoku(self, board):
        
        row = [set() for _ in range(9)]
        col = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]


        for i in range(9):
            for j in range(9):

                if(board[i][j] == '.'):
                    continue
                
                num = board[i][j]

                if num in row[i]:
                    return False
                row[i].add(num)

                if num in col[j]:
                    return False
                col[j].add(num)

                box = 3*(i//3) + (j//3)

                if num in boxes[box]:
                    return False
                boxes[box].add(num)
        return True
        