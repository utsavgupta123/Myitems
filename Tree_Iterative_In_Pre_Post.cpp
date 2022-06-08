// Iterative Pre Post Inorder
// Step-1  state==1  Pre mae push State++ Push left child
// Step-2  state==2  Post mae push State++ Push right child
// Step-3  state==3  In mae push Pop()

// Code-
vector<int> preorderTraversal(TreeNode *root)
{
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    if (root == NULL)
        return {};
    while (st.size() > 0)
    {
        auto curr = st.top();
        int state = curr.second;
        if (state == 1)
        {
            // Preorder
            pre.push_back(curr.first->val);
            st.top().second++;
            if (curr.first->left != NULL)
            {
                st.push({curr.first->left, 1});
            }
        }
        else if (state == 2)
        {
            // Inorder
            st.top().second++;
            in.push_back(curr.first->val);
            if (curr.first->right != NULL)
            {
                st.push({curr.first->right, 1});
            }
        }
        else
        {
            // Post order
            post.push_back(curr.first->val);
            st.pop();
        }
    }
    return ans;
}
