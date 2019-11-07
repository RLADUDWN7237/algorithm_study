#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000

int n;
int arr[100000][2];

int cmp(int (*a)[], int (*b)[]) {
	if ((*a)[0] == (*b)[0])
		return (*a)[1] > (*b)[1] ? 1 : ((*a)[1] < (*b)[1] ? -1 : 0);
	else return (*a)[0] > (*b)[0] ? 1 : ((*a)[0] < (*b)[0] ? -1 : 0);
}

void main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	qsort(arr, n, 8, cmp);

	for (int i = 0; i < n; i++)
		printf("%d  %d\n", arr[i][0], arr[i][1]);

}
