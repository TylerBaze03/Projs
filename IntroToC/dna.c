<<<<<<< HEAD
/* Assignment 12
Tyler Bazemore
4/1/2023
COP3223C*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	FILE *dnaCode;
	char dnaArr[1000], compare[1000];
	char a = 'a';
	int comp = 0,numStr, i = 0, j = 0, l = 0, x = 0, x3l, canNum;
	double score[10] = {0};
	double finalScores[10] = {0};
	double bestscore = 0;
	dnaCode = fopen("input1.txt", "r");
	if(dnaCode == NULL){
    	return 1;
    	}
	char dnaMaster[250];
// 2 gets statements to find master dna which we compare to
// and one statement to find how many comparisons to do
	fgets(dnaArr, 1000, dnaCode);
	fgets(compare, 1000, dnaCode);
	strcpy(dnaMaster, dnaArr);
	comp = atof(compare);
	while(fgets(dnaArr, 1000, dnaCode)){
	// this resets the length of the string every loop than gets the new length 
    	l = 0;
    	l = strlen(dnaArr);
    	for (i = 0;i < l;i++){
	// Creating different if statements for when to add to score
        	if (dnaArr[i] == dnaMaster[i]){
            	score[x] = score[x] + 3;
        	}
        	else if(dnaArr[i] == 'A' && dnaMaster[i] == 'T'){
            	score[x] = score[x] + 1;
        	}
        	else if(dnaArr[i] == 'T' && dnaMaster[i] == 'A'){
            	score[x] = score[x] + 1;
        	}
        	else if(dnaArr[i] == 'C' && dnaMaster[i] == 'G'){
            	score[x] = score[x] + 1;
        	}
        	else if(dnaArr[i] == 'G' && dnaMaster[i] == 'C'){
            	score[x] = score[x] + 1;
        	}
    	}
	// assigning variable for calculating final score than adds to x which is a counter
	// for scores in the list
    	x3l = 3 * l;
    	score[x] = score[x]*100;
    	finalScores[x] = score[x] / x3l;
    	x++;
	}
	for (j = 0;j<comp;j++){
    	if (finalScores[j] > bestscore){
        	bestscore = finalScores[j];
        	canNum = j;
    	}
	}
// if statement for when there is a perfect match or imperfect
	if (finalScores[canNum] == 100){
    	printf("Candidate %d is a perfect match.", canNum +1);
	}
	else{
    	printf("The best match is Candidate %d, with a score of %.2f.", canNum+1, finalScores[canNum]);
	}
	fclose(dnaCode);
	return 0;
}
=======
/* Assignment 12
Tyler Bazemore
4/1/2023
COP3223C*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	FILE *dnaCode;
	char dnaArr[1000], compare[1000];
	char a = 'a';
	int comp = 0,numStr, i = 0, j = 0, l = 0, x = 0, x3l, canNum;
	double score[10] = {0};
	double finalScores[10] = {0};
	double bestscore = 0;
	dnaCode = fopen("input1.txt", "r");
	if(dnaCode == NULL){
    	return 1;
    	}
	char dnaMaster[250];
// 2 gets statements to find master dna which we compare to
// and one statement to find how many comparisons to do
	fgets(dnaArr, 1000, dnaCode);
	fgets(compare, 1000, dnaCode);
	strcpy(dnaMaster, dnaArr);
	comp = atof(compare);
	while(fgets(dnaArr, 1000, dnaCode)){
	// this resets the length of the string every loop than gets the new length 
    	l = 0;
    	l = strlen(dnaArr);
    	for (i = 0;i < l;i++){
	// Creating different if statements for when to add to score
        	if (dnaArr[i] == dnaMaster[i]){
            	score[x] = score[x] + 3;
        	}
        	else if(dnaArr[i] == 'A' && dnaMaster[i] == 'T'){
            	score[x] = score[x] + 1;
        	}
        	else if(dnaArr[i] == 'T' && dnaMaster[i] == 'A'){
            	score[x] = score[x] + 1;
        	}
        	else if(dnaArr[i] == 'C' && dnaMaster[i] == 'G'){
            	score[x] = score[x] + 1;
        	}
        	else if(dnaArr[i] == 'G' && dnaMaster[i] == 'C'){
            	score[x] = score[x] + 1;
        	}
    	}
	// assigning variable for calculating final score than adds to x which is a counter
	// for scores in the list
    	x3l = 3 * l;
    	score[x] = score[x]*100;
    	finalScores[x] = score[x] / x3l;
    	x++;
	}
	for (j = 0;j<comp;j++){
    	if (finalScores[j] > bestscore){
        	bestscore = finalScores[j];
        	canNum = j;
    	}
	}
// if statement for when there is a perfect match or imperfect
	if (finalScores[canNum] == 100){
    	printf("Candidate %d is a perfect match.", canNum +1);
	}
	else{
    	printf("The best match is Candidate %d, with a score of %.2f.", canNum+1, finalScores[canNum]);
	}
	fclose(dnaCode);
	return 0;
}
>>>>>>> b756d6d (Updating repositroy using git)
