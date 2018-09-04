#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MORE 1
/*
 * Given input file containing scores scored by batsman
 *
 * Pakistan
 * 23
 * Pakistan
 * 127
 * India
 * 3
 * India
 * 71
 * Australia
 * 31
 * India
 * 22
 * Pakistan
 * 81
 *
 * Print the name of the countries with which he has never scored a century
 */
typedef struct list {
	char	country[32];
	int	count;
	struct list *next;
} List;

List *start = NULL;

void insert(char *country, int score) {
	List *tmp = start;
	while (tmp != NULL) {
		if (strcmp(tmp->country, country) == 0) {
			break;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL) {
		List *node = (List *)malloc(sizeof (List));
		strcpy(node->country, country);
		if (score >= 100) {
			node->count = MORE;
		} else {
			node->count = 0;
		}
		node->next = NULL;
		if (start == NULL) {
			start = node;
		} else {
			node->next = start;
			start = node;
		}
	} else {
		if (score >= 100) {
			tmp->count = MORE;
		}
	}
}

int getListSize() {
	int count = 0;
	List *tmp = start;
	while (tmp != NULL) {
		if (tmp->count != MORE) {
			count++;
		}
		tmp = tmp->next;
	}
	return count;
}

void printCount(char *inFile, char *outFile) {
	FILE *fp = fopen(inFile, "r");
	char country[64], score[10];
	printf("%s \n", inFile);
	while (fgets(country, sizeof (country), fp) != NULL) {
		if (fgets(score, sizeof (score), fp) == NULL) {
			fprintf(stderr, "Error in file format");
			return;
		}
		insert(country, atoi(score));
	}
	close(fp);
	fp = fopen(outFile, "w");
	fprintf(fp, "%d\n", getListSize());
	printf("Total count: %d\n", getListSize());
	close(fp);
	return; 
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		return -1;
	}
	printCount(argv[1], argv[2]);
	return 0;
}
