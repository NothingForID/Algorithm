// 基础冒泡排序
function bubbleSortBasic(arr) {
	const n = arr.length;
	// 外层循环控制轮次, 共 n - 1 轮
	for (let i = 0; i < n - 1; i++) {
		// 内层循环相邻比较, 比较次数逐轮递减
		for (let j = 0; j < n - 1 - i; j++) {
			// 若前大后小, 则交换位置, 实现升序排列
			if (arr[j] > arr[j + 1]) {
				[arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
			}
		}
	}
}

// 优化冒泡排序
// 添加提前终止标志
function bubbleSortOptimized(arr) {
	const n = arr.length;
	for (let i = 0; i < n - 1; i++) {
		// 外层控制添加是否交换标志, 初始默认为否
		let swapped = false;

		for (let j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				[arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
				swapped = true; // 标记发生交换
			}
		}

		// 若未发生交换, 则数组完全有序, 可提前终止
		if (!swapped) break;
	}
}

// 双向冒泡排序
// 鸡尾酒排序
function cocktailSort(arr) {
	// 定义遍历的左右边界
	let left = 0;
	let right = arr.length - 1;
	let swapped = true;

	while (swapped) {
		swapped = false;

		// 从左向右遍历, 将最大元素右移
		for (let i = left; i < right; i++) {
			if (arr[i] > arr[i + 1]) {
				[arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
				swapped = true;
			}
		}

		if (!swapped) break;

		// 移动最大元素之后左移右界, 同时修改标记
		right--;
		swapped = false;

		// 从右向左遍历, 将最小元素左移
		for (let i = right - 1; i >= left; i--) {
			if (arr[i] > arr[i + 1]) {
				[arr[i], arr[i + 1]] = [arr[i + 1], arr[i]];
				swapped = true;
			}
		}
		// 右移左界
		left++;
	}
}

// 打印数组
function printArray(arr) {
	console.log(arr.join(" "));
}

// 测试函数
(function main() {
	// 测试基础冒泡
	console.log("测试基础冒泡");
	const arr1 = [64, 34, 25, 12, 22, 11, 90];
	console.log("原始数组:");
	printArray(arr1);
	bubbleSortBasic(arr1);
	console.log("基础冒泡排序后的数组:");
	printArray(arr1);

	// 测试优化冒泡
	console.log("测试优化冒泡");
	const arr2 = [5, 1, 4, 2, 8, 0];
	console.log("原始数组:");
	printArray(arr2);
	bubbleSortOptimized(arr2);
	console.log("优化冒泡排序后的数组:");
	printArray(arr2);

	// 测试双向冒泡
	console.log("测试双向冒泡");
	const arr3 = [10, 3, 7, 1, 9, 2, 6];
	console.log("原始数组:");
	printArray(arr3);
	cocktailSort(arr3);
	console.log("双向冒泡排序后的数组:");
	printArray(arr3);
})();