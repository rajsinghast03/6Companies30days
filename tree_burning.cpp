/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  TreeNode *startNode;
  void mapParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp,
                 int start)
  {
    queue<TreeNode *> q;
    q.push(root);

    mp[root] = root;
    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      if (node->val == start)
        startNode = node;

      if (node->left)
      {
        q.push(node->left);
        mp[node->left] = node;
      }
      if (node->right)
      {
        q.push(node->right);
        mp[node->right] = node;
      }
    }
  }
  int amountOfTime(TreeNode *root, int start)
  {
    unordered_map<TreeNode *, TreeNode *> mp;
    unordered_map<TreeNode *, int> vis;
    mapParent(root, mp, start);
    queue<TreeNode *> q;
    q.push(startNode);
    int time = 0;

    while (!q.empty())
    {
      int sz = q.size();

      bool infect = false;
      for (int i = 0; i < sz; ++i)
      {
        TreeNode *node = q.front();
        q.pop();
        vis[node] = 1;

        if (node->left && !vis[node->left])
        {
          infect = true;
          vis[node->left] = 1;
          q.push(node->left);
        }
        if (node->right && !vis[node->right])
        {
          infect = true;
          vis[node->right] = 1;
          q.push(node->right);
        }
        if (mp[node] != node && !vis[mp[node]])
        {
          infect = true;
          vis[mp[node]] = 1;
          q.push(mp[node]);
        }
      }

      if (infect)
        time++;
    }

    return time;
  }
};