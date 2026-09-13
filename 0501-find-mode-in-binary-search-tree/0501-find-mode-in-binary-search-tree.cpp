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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> f;
        int maxF = 0;
        auto solve = [&f, &maxF](auto &&self, TreeNode* root){
            if(!root) return;
            f[root->val]++;
            maxF = max(maxF, f[root->val]);
            self(self, root->left);
            self(self, root->right);
        };

        solve(solve, root);

        vector<int> ans;
        for(auto &x : f){
            if(x.second == maxF) ans.push_back(x.first);
        }

        return ans;
    }
};