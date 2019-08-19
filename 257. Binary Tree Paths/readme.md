代码一次ac 这里第一次使用to_string函数,substr函数


```
class Solution {
public:
    vector<string> ret;
    void func(TreeNode* root,string path)
    {
        if(!root->left and !root->right) 
        {
            ret.push_back(path.substr(2) +"->"+ to_string(root->val));
            return;   
        }
        if(root->left) func(root->left,path + "->" + to_string(root->val));
        if(root->right) func(root->right,path + "->" + to_string(root->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return ret;
        if(!root->left and !root->right) return vector<string> {to_string(root->val)};
        func(root,"");
        return ret;
    }
};
```

看了一下stoi()的用法，如下：

```

int main()
{	
	string name = "123";
	int a = stoi(name);
	cout<<a<<endl;
	return 0;
}
```