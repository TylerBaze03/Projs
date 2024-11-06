package main

import (
	"fmt"
)

func matrixMulti(m1 [][]int, m2 [][]int) (result [][]int) {
	if checkColxRow(m1, m2) == false {
		return
	} else {

		prodCol := []int{}

		sl := [][]int{}

		for i := 0; i < len(m1); i++ {
			for j := 0; j < len(m2[0]); j++ {
				for k := 0; k < len(m2); k++ {
					prodCol[k] = m2[j][k]
				}
				sl[i][j] = dotProduct(m1[i], prodCol)
			}

		}

	}
	return
}
func dotProduct(m1 []int, m2 []int) (result int) {
	for i := 0; i < len(m1); i++ {
		result += m1[i] * m2[i]
	}
	return
}
func checkColxRow(m1 [][]int, m2 [][]int) (result bool) {

	var row int = 0
	row = len(m1)

	var col int = 0

	col = len(m2[0])

	if col != row {
		result = false
	} else {
		result = true
	}
	return
}

func main() {

	m1 := [][]int{{1, 2, 3}, {4, 5, 6}}
	m2 := [][]int{{7, 8}, {9, 10}, {11, 12}}
	fmt.Print(matrixMulti(m1, m2))

}
