#include <stdio.h>

int max(int x, int y){
	return x > y ? x : y;
}
int min(int x, int y){
	return x < y ? x : y;
}
int findKth(int nums1[], int m, int nums2[], int n, int k){
	if (m > n)
		return findKth(nums2, n, nums1, m, k);
	if (m == 0)
		return nums2[k-1];
	if (k == 1)
		return min(nums1[0], nums2[0]);
	int left = min(k/2, m), right = k - left;
	if (nums1[left - 1] < nums2[right - 1])
		return findKth(nums1 + left, m - left, nums2, n, k - left);
	else if (nums1[left-1] > nums2[right - 1])
		return findKth(nums1, m, nums2 + right, n - right, k - right);
	else
		return nums1[left-1];
}

double findMedianSortedArrays(int* nums1,
							  int nums1Size,
							  int* nums2,
							  int nums2Size) {
	int total = nums1Size + nums2Size;
	if (total & 1)
		return findKth(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
	else
		return ((double)(findKth(nums1, nums1Size, nums2, nums2Size, total/2) +
						 findKth(nums1, nums1Size, nums2, nums2Size, total/2 + 1)))/2;
}

int main(){
	int para1[] = {1};
	int para2[] = {1};
	printf("%f\n", findMedianSortedArrays(para1,
										  sizeof(para1)/sizeof(int),
										  para2,
										  sizeof(para2)/sizeof(int)));
	return 0;
}
