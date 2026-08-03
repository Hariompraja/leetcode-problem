class Solution {
public:
    int numTrees(int n) {

        vector<int>numTrees(n+1,0);
        numTrees[0] = 1;
        for(int NoOfNodes=1; NoOfNodes<=n; NoOfNodes++){
            int total = 0;
            for(int root = 1; root <= NoOfNodes; root++){

               int NoOfNodesInLeftSubtree = root-1;
               int NoOfNodesInRightSubtree = NoOfNodes-root;

               total += (numTrees[NoOfNodesInLeftSubtree] * numTrees[NoOfNodesInRightSubtree]);

            }

            numTrees[NoOfNodes] = total;
        }

        return numTrees[n];
      
    }
};