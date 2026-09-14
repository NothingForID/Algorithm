# 基础冒泡排序
def bubble_sort_basic(arr):
	n = len(arr)
	# 外层循环控制轮次, 共 n - 1 轮
	for i in range(n - 1):
		# 内层循环相邻比较, 比较次数逐轮递减
		for j in range(n - 1 - i):
			# 若前大后小, 则交换位置, 实现升序排列
			if arr[j] > arr[j + 1]:
				arr[j], arr[j + 1] = arr[j + 1], arr[j]

# 优化冒泡排序
# 添加提前终止标志
def bubble_sort_optimized(arr):
	n = len(arr)
	for i in range(n - 1):
		# 外层控制添加是否交换标志, 初始默认为否
		swapped = False

		for j in range(n - 1 - i):
			if arr[j] > arr[j + 1]:
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
				swapped = True  # 标记发生交换

		# 若未发生交换, 则数组完全有序, 可提前终止
		if not swapped:
			break

# 双向冒泡排序
# 鸡尾酒排序
def cocktail_sort(arr):
	# 定义遍历的左右边界
	left = 0
	right = len(arr) - 1
	swapped = True

	while swapped:
		swapped = False

		# 从左向右遍历, 将最大元素右移
		for i in range(left, right):
			if arr[i] > arr[i + 1]:
				arr[i], arr[i + 1] = arr[i + 1], arr[i]
				swapped = True

		if not swapped:
			break

		# 移动最大元素之后左移右界, 同时修改标记
		right -= 1
		swapped = False

		# 从右向左遍历, 将最小元素左移
		for i in range(right - 1, left - 1, -1):
			if arr[i] > arr[i + 1]:
				arr[i], arr[i + 1] = arr[i + 1], arr[i]
				swapped = True
		# 右移左界
		left += 1

# 打印数组
def print_array(arr):
	print(" ".join(map(str, arr)))

# 测试函数
def main():
	# 测试基础冒泡
	print("测试基础冒泡")
	arr1 = [64, 34, 25, 12, 22, 11, 90]
	print("原始数组:")
	print_array(arr1)
	bubble_sort_basic(arr1)
	print("基础冒泡排序后的数组:")
	print_array(arr1)

	# 测试优化冒泡
	print("测试优化冒泡")
	arr2 = [5, 1, 4, 2, 8, 0]
	print("原始数组:")
	print_array(arr2)
	bubble_sort_optimized(arr2)
	print("优化冒泡排序后的数组:")
	print_array(arr2)

	# 测试双向冒泡
	print("测试双向冒泡")
	arr3 = [10, 3, 7, 1, 9, 2, 6]
	print("原始数组:")
	print_array(arr3)
	cocktail_sort(arr3)
	print("双向冒泡排序后的数组:")
	print_array(arr3)

if __name__ == "__main__":
	main()