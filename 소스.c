#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int* powerset;    //������
int answer = 0;   //�������⹰
int n;       //���� N����
int* input;  //����ڷκ��� �Է¹��� ���� ���� ������ �迭 input
int* include;   


//�հ� ���ϴ� �Լ� sum
double sum(int arr[]) {
	double total = 0.0;
	for (int i = 0; i < n; i++) {
		total += (double)arr[i];
	}
	return total;
}

//������ ���ϴ� �Լ� 
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


//�Ҽ� �Ǻ� �Լ�
int primef(double hap) {
	int prime = 1;
	for (int i = 2; i <= (int)sqrt(hap); i++) {
		if ((int)hap % i == 0) {
			prime = 0; // �Ҽ��̴�.
			break;
		}
	}
	return prime;
}


int main() {
	
	scanf("%d", &n);    //����ڷκ��� ���� ���� �Է¹���
	  
	powerset = (int*)malloc(sizeof(int) * n);   
	for (int i = 0; i < n; i++) {
		powerset[i] = 0;
	}
	input = (int*)malloc(sizeof(int) * n);
	include = (int*)malloc(sizeof(int) * n); //int�� �迭 input�� n���� ũ��� ����

	//for�� ���鼭 ����� �Է°� input�迭�� ����
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);      
	}
	 
	powerSet(0);
	printf("%d", answer-1);	

	return 0;

}