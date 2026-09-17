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
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        auto solve = [&](auto &&self, TreeNode* root) -> pair<int, int> {
            if(!root){
                return {0, 0};
            }

            pair<int, int> left = self(self, root->left);
            pair<int, int> right = self(self, root->right);

            int nodeCnt = left.first + right.first + 1;
            int nodeSum = left.second + right.second + root->val;

            if(root->val == (nodeSum / nodeCnt)){
                cnt++;
            }

            return {nodeCnt, nodeSum};
        };

        solve(solve, root);
        return cnt;
    }
};