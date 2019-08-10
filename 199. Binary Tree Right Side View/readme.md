这个题就是把每层的最后一个元素给保存下来


想用c++ 一次 bug free 还需要多练练
```
#include <queue>
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == NULL) return vector<int>();
        queue<TreeNode*> pre_data;
        pre_data.push(root);
        queue<TreeNode*> cur_data;
        vector<int> ret;
        ret.push_back(root->val);
        while(!pre_data.empty())
        {
            while(!pre_data.empty())
            {
                auto tmp =pre_data.front();
                if(tmp->left) cur_data.push(tmp->left);
                if(tmp->right) cur_data.push(tmp->right);
                pre_data.pop();
                
            }
            if(!cur_data.empty()) ret.push_back(cur_data.back()->val);
            pre_data = cur_data;
            cur_data = queue<TreeNode*>();
        }
        return ret;
        
    }
};
```