#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n;  //사용자로부터 갯수 입력받음
int* arr;
int answer = 0;


//팩토리얼 구하는 함수
int fact(int n) {
	if (n == 0) return 1;
	else return fact(n - 1) * n;
}

//같은 것이 있는 순열 구하기
int fact_same(int arr[]) {
	int sum = arr[0] + arr[1] + arr[2];
	int fact_num = fact(sum);
	for (int i = 0; i < 3; i++) {
		if (arr[i] > 1)
			fact_num /= fact(arr[i]);
	}
	return fact_num;
}

int main() {

	int A[3] = { 0, };
	
	scanf("%d", &n);          //사용자로부터 입력받을 숫자 갯수 입력받음
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++) {

		for (int j = arr[i]-1; j >= 0; j--) {
		
			int p = arr[i] - j;

			for (int k = p / 2; k >= 0; k--) {

				if (k == 0) {         
					if (p % 3 == 0) {
						A[0] = j;
						A[1] = 0;
						A[2] = p / 3;
						answer += fact_same(A);

					}

				}
				else
				{
					if (p - (2*k) == 0) {
						A[0] = j;
						A[1] = k;
						A[2] = 0;
						answer += fact_same(A);
					}

					else if ((p - (2*k) != 0)&& ((p - (2*k)) % 3 == 0)) {
						A[0] = j;
						A[1] = k;
						A[2] = (p - (2 * k)) / 3;
						answer += fact_same(A);

					}
				
					
				}

				for (int i = 0; i < 3; i++) {
					A[i] = 0;
				}
			}
			

		}
		printf("%d\n", answer + 1);
		answer = 0;
	}

}