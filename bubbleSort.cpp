#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 基础冒泡排序
void bubbleSortBasic(vector<int>& arr) {
	int n = arr.size();
	// 外层循环控制轮次, 共 n - 1 轮
	for (int i = 0; i < n - 1; i++) {
		// 内层循环相邻比较, 比较次数逐轮递减
		for (int j = 0; j < n - 1 - i; j++) {
			// 若前大后小, 则交换位置, 实现升序排列
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// 优化冒泡排序
// 添加提前终止标志
void bubbleSortOptimized(vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		// 外层控制添加是否交换标志, 初始默认为否
		bool swapped = false;

		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true; // 标记发生交换
			}
		}

		// 若未发生交换, 则数组完全有序, 可提前终止
		if (!swapped) break;
	}
}

// 双向冒泡排序
// 鸡尾酒排序
void cocktailSort(vector<int>& arr) {
	// 定义遍历的左右边界
	int left = 0, right = arr.size() - 1;
	bool swapped = true;

	while(swapped) {
		swapped = false;

		// 从左向右遍历, 将最大元素右移
		for (int i = left; i < right; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (!swapped) break;

		// 移动最大元素之后左移右届, 同时修改标记
		right--;
		swapped = false;

		// 从右向左遍历，将最小元素左移
		for (int i = right - 1; i >= left; i--) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		// 右移左届
		left++; 
	}
}

// 打印数组
void printArray(const vector<int>& arr) {
	for (int num : arr) {
		cout << num << " ";
	}
	cout << endl;
}

// 测试函数
int main() {
	// 测试基础冒泡
	cout << "测试基础冒泡";
	vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
	cout << "\n原始数组:";
	printArray(arr1);
	bubbleSortBasic(arr1);
	cout << "基础冒泡排序后的数组:";
	printArray(arr1);
	
	// 测试优化冒泡
	cout << "测试优化冒泡";
	vector<int> arr2 = {5, 1, 4, 2, 8, 0};
	cout << "\n原始数组:";
	printArray(arr2);
	bubbleSortOptimized(arr2);
	cout << "优化冒泡排序后的数组:";
	printArray(arr2);
	
	// 测试双向冒泡
	cout << "测试双向冒泡";
	vector<int> arr3 = {10, 3, 7, 1, 9, 2 ,6};
	cout << "\n原始数组:";
	printArray(arr3);
	cocktailSort(arr3);
	cout << "双向冒泡排序后的数组:";
	printArray(arr3);
	
	return 0;
}