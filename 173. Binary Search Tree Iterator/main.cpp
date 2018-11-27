/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        find_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* r = st.top();
        st.pop();
        if(r->right)
            find_left(r->right);
        return r->val;
    }
    void find_left(TreeNode* root)
    {
        TreeNode* tmp = root;
        while(tmp!=nullptr)
        {
            st.push(tmp);
            tmp = tmp->left;
        }

    }
};

这个题目刚看到的时候，不知道干啥的，看了答案知道明白了。。。