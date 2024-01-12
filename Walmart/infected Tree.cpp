/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void convert(TreeNode* root, int p, unordered_map<int, vector<int>>&gr){
        if(!root){
            return;
        }
        vector<int>&list = gr[root->val];
        if(p!=0){
            list.push_back(p);
        }
        if(root->left){
            list.push_back(root->left->val);
        }
        if(root->right){
            list.push_back(root->right->val);
        }
        
        convert(root->left, root->val, gr);
        convert(root->right, root->val, gr);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>>gr;
        convert(root,0,gr);
        queue<int>q;
        q.push(start);
        unordered_set<int>visited;
        visited.insert(start);
        
        int min =0;
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                for(int child:gr[node]){
                    if(visited.find(child)==visited.end()){
                        visited.insert(child);
                        q.push(child);
                    }
                }
            }
            min++;
        }
        return min-1;
    }
};