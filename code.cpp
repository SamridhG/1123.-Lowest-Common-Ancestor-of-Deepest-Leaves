class Solution {
public:
    stack<TreeNode*>last;
    queue<TreeNode*>level;
    void level_order(TreeNode* root)
    {
        level.push(root);
        last.push(NULL);
        last.push(root);
        last.push(NULL);
        while(!level.empty())
        {
            int size=level.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=level.front();
                level.pop();
                if(node->left!=NULL)
                {
                    level.push(node->left);
                    last.push(node->left);
                }
                 if(node->right!=NULL)
                {
                    level.push(node->right);
                    last.push(node->right);
                }
            }
            last.push(NULL);
        }
    }
    TreeNode* LCA(TreeNode* root,TreeNode* A,TreeNode* B)
    {
        if(root==NULL)return NULL;
    if(A==root || B==root) return root;
     TreeNode* Left=LCA(root->left,A,B);
        TreeNode* Right=LCA(root->right,A,B);
        if(Left && Right) return root;
        if(Left==NULL) return Right;
        if(Right==NULL)return Left;
        return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        level_order(root);
      last.pop();
        last.pop();
       TreeNode* A=last.top();
        last.pop();
        TreeNode* B=last.top();
        last.pop();
       while(B!=NULL)
        {
            TreeNode* Ans=LCA(root,A,B);
            last.push(Ans);
              A=last.top();
             last.pop();
            B=last.top();
             last.pop(); 
        }
     return A;
    }
};
