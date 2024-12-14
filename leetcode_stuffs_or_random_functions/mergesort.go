package main

// basic merge sort function to sort slices/arrays
func sortArray(nums []int) []int {

	sorted := mergeSort(nums)

	return sorted
}

// standard mergesort function, breaks it down recusrsively
func mergeSort(nums []int) []int {
	if len(nums) < 2 {
		return nums
	}
	mid := len(nums) / 2

	leftArr := mergeSort(nums[:mid])
	rightArr := mergeSort(nums[mid:])

	sort := merge(leftArr, rightArr)

	return sort

}

// actual mergeing
func merge(x []int, y []int) []int {

	merged := []int{}
	i := 0
	j := 0
	// 2 trackers each going through respective arrays check if they are greater or less than where the others 'pointer' is at
	for i < len(x) && j < len(y) {
		if x[i] < y[j] {
			merged = append(merged, x[i])
			i++
		} else {
			merged = append(merged, y[j])
			j++
		}
	}
	// yay this works, adds the remaing of each array to the sorted array since the rest should all be sorted without for loop
	merged = append(merged, x[i:]...)
	merged = append(merged, y[j:]...)

	return merged

}
