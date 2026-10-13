/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/



class Solution {
public:
    bool check(vector<vector<int>>& grid, int l, int r, int u, int d){
        int a = 1, b = 0;
        for(int i = u;i<d;i++){
            for(int j = l;j<r;j++){
                int y = grid[i][j];
                a = (a & y);
                b = (b | y);
            }
        }
        if(a == 1 || b == 0) return true;
        return false;
    }
    
    Node* construct(vector<vector<int>>& grid, int l = 0, int r = -1, int u = 0, int d = -1) {
        // Initialize boundaries for the first function call
        if(r == -1){
            r = grid.size();
            d = r;
        }

        // If the current section is all 0s or all 1s, it becomes a leaf node
        if(check(grid, l, r, u, d)){
            return new Node(grid[u][l], true);
        }
        
        int n = r - l;
        
        // If mixed, it's an internal node. Split into 4 quadrants.
        return new Node(1,
                    false, 
                    construct(grid, l + 0,   l + n/2, u + 0,   u + n/2), 
                    construct(grid, l + n/2, l + n,   u + 0,   u + n/2), 
                    construct(grid, l + 0,   l + n/2, u + n/2, u + n), 
                    construct(grid, l + n/2, l + n,   u + n/2, u + n)
        );
    }
};