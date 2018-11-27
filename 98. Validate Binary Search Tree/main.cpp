class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return func(root,pre);
    }
    bool func(TreeNode* root,TreeNode*& pre)
    {
        if(root == nullptr) return true;
        if(!func(root->left,pre)) return false;
        if(pre&&pre->val>=root->val) return false;
        pre = root;
        return func(root->right,pre);
    }
};

这个程序看了discussion 才知道的 唉 。。。。