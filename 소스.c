#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//사용자로부터 값 입벽받기위한 배열
int* A;
int* B;
int sum = 0;   //최종결과값
int index;     //최댓값의 index 기억하기 위해
int n;

//오름차순 정렬해주는 함수
void sort(int arr[]) {
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n- 1-i; j++)
		{
			if (arr[j] > arr[j+ 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+ 1] = temp;
			}
		}
	}
}

//최댓값 찾아주는 함수
int findMax(int arr[]) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] >= max) {
			max = arr[i];
			index = i;  //최댓값에 해당하는 index 기억시킴
		}   
	}
	arr[index] = 0;   //최댓값에 해당되는 값 0으로 설정(다음 최댓값 찾을때 고려 안하기 위해)
	return max;
}



int main() {

	//배열 크기
	scanf("%d", &n);

	//배열 할당
	A = (int*)malloc(sizeof(int) * n);
	B = (int*)malloc(sizeof(int) * n);

	//배열에 값 할당
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}

	
	//배열 A 오름차순 정렬
	sort(A);

	
	//배열 A에서 작은값 * 배열 B에서 큰값 곱해서 누적해서 sum에 더해주기
	for (int i = 0; i < n; i++) {
			sum+=A[i]*findMax(B);
	}

	//결과값 출력
	printf("%d", sum);
}