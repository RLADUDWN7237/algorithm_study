#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int* powerset;    //멱집합
int answer = 0;   //최종산출물
int n;       //사탕 N종류
int* input;  //사용자로부터 입력받은 사탕 가격 저장할 배열 input
int* include;   


//합계 구하는 함수 sum
double sum(int arr[]) {
	double total = 0.0;
	for (int i = 0; i < n; i++) {
		total += (double)arr[i];
	}
	return total;
}

//멱집합 구하는 함수 
int powerSet(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++) {
			if (include[i]) powerset[i] = input[i];
		}
		if (primef(sum(powerset))) answer++;
		for (int i = 0; i < n; i++) {
			powerset[i] = 0;
		}
		return;
	}
	include[k] = 0;
	powerSet(k + 1);
	include[k] = 1;
	powerSet(k + 1);
}


//소수 판별 함수
int primef(double hap) {
	int prime = 1;
	for (int i = 2; i <= (int)sqrt(hap); i++) {
		if ((int)hap % i == 0) {
			prime = 0; // 소수이다.
			break;
		}
	}
	return prime;
}


int main() {
	
	scanf("%d", &n);    //사용자로부터 원소 갯수 입력받음
	  
	powerset = (int*)malloc(sizeof(int) * n);   
	for (int i = 0; i < n; i++) {
		powerset[i] = 0;
	}
	input = (int*)malloc(sizeof(int) * n);
	include = (int*)malloc(sizeof(int) * n); //int형 배열 input을 n개의 크기로 만듦

	//for문 돌면서 사용자 입력값 input배열에 저장
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);      
	}
	 
	powerSet(0);
	printf("%d", answer-1);	

	return 0;

}