#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
  class ST {
  private:
    struct TreeNode {
      int left, right;
      int cover;
      TreeNode *leftChild;
      TreeNode *rightChild;
      TreeNode(int l, int r)
          : left(l), right(r), cover(0), leftChild(NULL), rightChild(NULL){};
    };
    TreeNode *root;
    inline int min(int x, int y) { return x < y ? x : y; }
    inline int max(int x, int y) { return x > y ? x : y; }
    TreeNode *_buildTree(int left, int right) { // right is not included
      TreeNode *_root = new TreeNode(left, right);
      if (left < right - 1) {
        int mid = left + ((right - left) >> 1);
        _root->leftChild = _buildTree(left, mid);
        _root->rightChild = _buildTree(mid, right);
      }
      return _root;
    }
    void _insertSegment(int left, int right, TreeNode *r) {
      if (r == NULL)
        return;
      if (left <= r->left && right >= r->right)
        r->cover++;
      else {
        int mid = r->left + ((r->right - r->left) >> 1);
        if (left < mid)
          _insertSegment(left, right, r->leftChild);
        if (mid < right)
          _insertSegment(left, right, r->rightChild);
      }
    }
    void _deleteSegment(int left, int right, TreeNode *r) {
      if (r == NULL)
        return;
      if (left <= r->left && right >= r->right)
        r->cover--;
      else {
        int mid = r->left + ((r->right - r->left) >> 1);
        if (left < mid)
          _deleteSegment(left, right, r->leftChild);
        if (mid < right)
          _deleteSegment(left, right, r->rightChild);
      }
    }
    int _query(int left, int right, TreeNode *r) {
      if (root == NULL)
        return 0;
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
    int _count(TreeNode *r) {
      if (r == NULL)
        return 0;
      if (r->cover > 0)
        return r->right - r->left;
      return _count(r->leftChild) + _count(r->rightChild);
    }
    void _dfs(TreeNode *r) {
      if (r == NULL)
        return;
      cout << r->cover << " " << r->left << " " << r->right << endl;
      _dfs(r->leftChild);
      _dfs(r->rightChild);
    }
    void _calc(TreeNode *r, vector<Interval> &ans) {
      if (r == NULL)
        return;
      if (r->cover > 0) {
        ans.push_back(Interval(r->left, r->right));
        return;
      }
      if (r->leftChild)
        _calc(r->leftChild, ans);
      if (r->rightChild)
        _calc(r->rightChild, ans);
    }

  public:
    ST() : root(NULL){};
    void buildTree(int left, int right) { root = _buildTree(left, right); }
    void insertSegment(int left, int right) {
      _insertSegment(left, right, root);
    }
    void deleteSegment(int left, int right) {
      _deleteSegment(left, right, root);
    }
    int query(int left, int right) { return _query(left, right, root); }
    int count() { return _count(root); }
    void dfs() { _dfs(root); }
    void calc(vector<Interval> &ans) { _calc(root, ans); }
  };

public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() == 0)
      return intervals;
    ST st;
    int minst = intervals[0].start, mined = intervals[0].end;
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i].end > mined)
        mined = intervals[i].end;
      if (intervals[i].start < minst)
        minst = intervals[i].start;
    }
    st.buildTree(minst, mined);
    for (int i = 0; i < intervals.size(); i++) {
      st.insertSegment(intervals[i].start, intervals[i].end);
    }
    vector<Interval> ans;
    st.calc(ans);
    if (ans.size() == 0 || ans.size() == 1)
      return ans;
    for (int i =0 ;i < ans.size(); i++){
      cout << ans[i].start << " - " << ans[i].end << endl;
    }
    vector<Interval> res;
    int i = 1;
    int start = ans[0].start, end = ans[0].end;
    bool last = false;
    while (i < ans.size()) {
      last = false;
      while (i < ans.size() && ans[i].start == end) {
        end = ans[i].end;
        i++;
      }
      res.push_back(Interval(start, end));
      if (i < ans.size()) {
        start = ans[i].start;
        end = ans[i].end;
        i++;
        last = true;
      }
    }
    if (last)
      res.push_back(Interval(start, end));
    return res;
  }
};

int main() {
  Solution sol;
  vector<Interval> para = {Interval(1, 3), Interval(2, 6), Interval(8, 10),Interval(15, 18)};
  vector<Interval> para2 = {Interval(0, 0), Interval(1, 4)};
  vector<Interval> ans = sol.merge(para2);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].start << " " << ans[i].end << endl;
  }
  return 0;
}
