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
    void paths(TreeNode* root, string s, vector<string>& ans){
        if(!root) return;

        if(!root->left && !root->right){
            s += format("{}", root->val);
            ans.push_back(s);
            return;
        }

        s += format("{}->", root->val);
        paths(root->left, s, ans);
        paths(root->right, s, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        paths(root, "", ans);
        return ans;
    }
};