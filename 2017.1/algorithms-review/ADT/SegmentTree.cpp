/* Segment Tree is binary search tree, like Interval Tree. Each node stores a segment, and leaf represents value. It can look for the time a segment appears in several segments in O(logn). The build time for the tree is nlogn.
   It is also nearly complete.
   Notice that most conditions, we need to discretize the input, for example:
   [10000, 20000], [21000, 23000], [19000, 40000], [45000, 47000]
   We should sort those points and renumber them: 10000, 19000, 20000, 21000, 23000, 40000, 45000, 47000
   and we numbered them with                          0,     1,     2,     3,     4,     5,     6,     7
   [0, 2], [3, 4], [1, 5], [6, 7]
   We can use a dict to represent the relationship between index and its origin value.

   ST must ensure that segments are left-closed and right-opened: [left..right). If the segment is both-closed, there exists shortback for discretization.
   Discretization's shortback if both-closed:
   consider [1, 10] [1, 4] [5, 10]  // 1: 0, 4: 1, 5: 2, 10: 3,     [0, 3], [0, 1], [2, 3]
            [1, 10] [1, 4] [6, 10]  // 1: 0, 4: 1, 6: 2, 10: 3,     [0, 3], [0, 1], [2, 3]
            After discretization, the two list of segments are same. However, in list1, the [1, 10] is fully covered by [1, 4] and [5, 10], but list2 not. So discretization cannot show this difference if both-closed.
 */

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct TreeNode{
  int left, right;
  int cover;
  TreeNode* leftChild;
  TreeNode* rightChild;
  TreeNode(int l, int r):
    left(l), right(r), cover(0),
    leftChild(NULL), rightChild(NULL){};
};

class ST{
private:
  TreeNode * root;
  inline int min(int x, int y) {
    return x < y ? x : y;
  }
  inline int max(int x, int y){
    return x > y ? x : y;
  }
  TreeNode* _buildTree(int left, int right){ // right is not included
    TreeNode * _root = new TreeNode(left, right);
    if (left < right - 1){
      int mid = left + ((right - left) >> 1);
      _root->leftChild = _buildTree(left, mid);
      _root->rightChild = _buildTree(mid, right);
    }
    return _root;
  }
  void _insertSegment(int left, int right, TreeNode *r){
    if (r == NULL) return;
    if (left <= r->left && right >= r->right)
      r->cover++;
    else{
      int mid = r->left + ((r->right - r->left) >> 1);
      if (left < mid)
        _insertSegment(left, right, r->leftChild);
      if (mid < right)
        _insertSegment(left, right, r->rightChild);
      // The current node should be updated.
      // we should use a delay tag to indicate that the node may be modified.
      // update the tag whenever we query or insert.
    }
  }
  void _deleteSegment(int left, int right, TreeNode *r){
    if (r == NULL) return;
    if (left <= r->left && right >= r->right)
      r->cover--;
    else{
      int mid = r->left + ((r->right - r->left) >> 1);
      if (left < mid)
        _deleteSegment(left, right, r->leftChild);
      if (mid < right)
        _deleteSegment(left, right, r->rightChild);
    }
  }
  int _query(int left, int right, TreeNode * r){
    if (root == NULL)  return 0;
    if (right > r->right || left < r->left)
      return 0;
    if (r->left >= r->right - 1)
      return r->cover;
    int mid = r->left + ((r->right - r->left) >> 1);
    int tleft = INT_MAX, tright = INT_MAX;
    if (left < mid)
      tleft = _query(max(left, r->left), min(right, mid), r->leftChild);
    if (right > mid)
      tright = _query(max(left, mid), min(right, r->right), r->rightChild);
    int childCover = min(tleft, tright);
    if (left >= r->left && right <= r->right)
      childCover += r->cover;
    return childCover;
  }
  int _count(TreeNode * r){
    if (r == NULL) return 0;
    if (r->cover > 0)
      return r->right - r->left;
    return _count(r->leftChild) + _count(r->rightChild);
  }
  void _dfs(TreeNode* r){
    if (r ==  NULL) return;
    cout << r->cover << " " << r->left << " " << r->right << endl;
    _dfs(r->leftChild);
    _dfs(r->rightChild);
  }
public:
  ST(): root(NULL){};
  void buildTree(int left, int right){
    root = _buildTree(left, right);
  }
  void insertSegment(int left, int right){
    _insertSegment(left, right, root);
  }
  void deleteSegment(int left, int right){
    _deleteSegment(left, right, root);
  }
  int query(int left, int right){
    return _query(left, right, root);
  }
  int count(){
    return _count(root);
  }
  void dfs(){
    _dfs(root);
  }
};

int main(){
  ST st;
  st.buildTree(0, 10);
  st.insertSegment(1, 4);
  st.insertSegment(3, 4);
  st.insertSegment(3, 5);
  st.insertSegment(4, 7);
  for (int i = 0; i < 6; i++)
    cout << i << "-" << i+4 << " " << st.query(i, i+4) << endl;
  cout << st.count() << endl;
  return 0;
}
