#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution1 {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for (int i = 1; i < k; i++)
      pq.pop();
    return pq.top();
  }
};

class Solution2 {
public:
  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int l = left + 1, r = right;
    while (l <= r) {
      if (nums[l] < pivot && nums[r] > pivot)
        swap(nums[l++], nums[r--]);
      if (nums[l] >= pivot) l++;
      if (nums[r] <= pivot) r--;
    }
    swap(nums[left], nums[r]);
    return r;
  }

  int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;
    while (true) {
      int pos = partition(nums, left, right);
      if (pos == k - 1) return nums[pos];
      if (pos > k - 1) right = pos - 1;
      else left = pos + 1;
    }
  }
};

class Solution {
public:
    inline int left(int idx) {
        return (idx << 1) + 1;
    }
    inline int right(int idx) {
        return (idx << 1) + 2;
    }
    void max_heapify(vector<int>& nums, int idx) {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest]) largest = l;
        if (r < heap_size && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void build_max_heap(vector<int>& nums) {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) - 1; i >= 0; i--)
            max_heapify(nums, i);
    }
    int findKthLargest(vector<int>& nums, int k) {
        build_max_heap(nums);
        for (int i = 0; i < k; i++) {
            swap(nums[0], nums[heap_size - 1]);
            heap_size--;
            max_heapify(nums, 0);
        }
        return nums[heap_size];
    }
private:
    int heap_size;
}

int main(){
  Solution sol;
  vector<int> para ={3,2,1,5,6,4};
  cout << sol.findKthLargest(para, 2)<<endl;
  return 0;
}
