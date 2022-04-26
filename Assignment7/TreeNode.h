// abstract TreeNode class

template <typename E>
class TreeNode
{
  public:
    E value;
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
      key = 0;
      value = E();
      left = nullptr;
      right = nullptr;
    }

    TreeNode(int k, E v)
    {
      key = k;
      value = v;
      left = nullptr;
      right = nullptr;
    }

    virtual ~TreeNode(){}
};
