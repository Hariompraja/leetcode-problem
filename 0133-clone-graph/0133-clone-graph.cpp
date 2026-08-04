class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){return NULL;}
        vector<bool>vis(101,false);
        vector<Node*>v(101);
        for(int i=1;i<=100;i++)
        {
            v[i] = new Node(i);
        }
        queue<Node*>q;
        q.push(node);
        vis[node->val] = true;
        while(!q.empty()){
            node = q.front();
            int x = node->val;
            q.pop();
            for(auto it:node->neighbors)
            {
                (v[x]->neighbors).push_back(v[it->val]);
                if(!vis[it->val]){
                    q.push(it);
                    vis[it->val] = true;
                }
            }
        }
        return v[1];
    }
};