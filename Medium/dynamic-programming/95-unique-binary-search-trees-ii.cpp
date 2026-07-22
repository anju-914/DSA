// 95. Unique Binary Search Trees II
// Difficulty: Medium
// Topics: Dynamic Programming, Backtracking, Tree, Binary Search Tree, Binary Tree
// Link: https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*> uniqueBst(int start, int end){
    if(start> end) return {nullptr};
    vector<TreeNode*> res;
    for(int i=start;i<= end;i++){
        auto leftSubtree = uniqueBst(start,i-1);
        auto rightSubtree = uniqueBst(i+1,end);
        for(auto left: leftSubtree){
            for(auto right: rightSubtree){
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                res.push_back(root);
            }
        }
    }
    return res;
}

public:
    vector<TreeNode*> generateTrees(int n) {
        return uniqueBst(1,n);
    }
};