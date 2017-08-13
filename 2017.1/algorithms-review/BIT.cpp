#include <iostream>
#define MAXN 100
int MaxVal;
int tree[MAXN];

int read(int idx){ // 返回c[idx]
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, int val){ // 更新f[idx] 后，对 tree数组也要更新
	while (idx <= MaxVal){
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int readSingle(int idx){  // 读取单个 f[idx]
	int sum = tree[idx];
	if (idx > 0){
		int z = idx - (idx & -idx);  // 如果 idx 是奇数，则 z 刚好等于 idx-1，O(1)，否则偶数需要 O(logn)
		idx--;
		while (z != idx){
			sum -= tree[idx];
			idx -= (idx & -idx);
		}
	}
	return sum;
}

void scale(int c){ // 对整体缩放
	for (int i = 1; i <= MaxVal; i++){
		tree[i] /= c;
	}
}

int find(int cumFre){
	// 如果数组中存在负数，则只能依次求出 c[0..n-1]
	// 若数组元素均为非负，则tree 数组必然非降，可二分查找
	int idx = 0;
	while (bitMask != 0 && idx < MaxVal){
		int tIdx = idx + bitMask;    // bitMask 是 MaxVal 的最高位
		if (cumFre == tree[tIdx])
			return tIdx;
		else if (cumFre > tree[tIdx]){  // tree[tIdx] < cumFre，则将已适配的部分减去
			// 如果 cumFre < tree[tIdx] ，则不会保留当前的 tIdx
			idx = tIdx;
			cumFre -= tree[tIdx];
		}
		bitMask >>= 1;
	}
	if (cumFre != 0)
		return -1;
	return idx;
}

int findG(int cumFre){ // 当存在多个与 cumFre 相同的 F[i] 时，findG 会返回最大的 i，而 find 会返回随机的 i
	int idx = 0;
	while (bitMask != 0 && idx < MaxVal){
		int tIdx = idx + bitMask;
		if (cumFre >= tree[tIdx]){
			idx = tIdx;
			cumFre -= tree[tIdx];
		}
		bitMask >>= 1;
	}
	if (cumFre != 0)
		return -1;
	return idx;
}
