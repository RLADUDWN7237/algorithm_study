#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//����ڷκ��� �� �Ժ��ޱ����� �迭
int* A;
int* B;
int sum = 0;   //���������
int index;     //�ִ��� index ����ϱ� ����
int n;

//�������� �������ִ� �Լ�
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

//�ִ� ã���ִ� �Լ�
int findMax(int arr[]) {
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] >= max) {
			max = arr[i];
			index = i;  //�ִ񰪿� �ش��ϴ� index ����Ŵ
		}   
	}
	arr[index] = 0;   //�ִ񰪿� �ش�Ǵ� �� 0���� ����(���� �ִ� ã���� ��� ���ϱ� ����)
	return max;
}



int main() {

	//�迭 ũ��
	scanf("%d", &n);

	//�迭 �Ҵ�
	A = (int*)malloc(sizeof(int) * n);
	B = (int*)malloc(sizeof(int) * n);

	//�迭�� �� �Ҵ�
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}

	
	//�迭 A �������� ����
	sort(A);

	
	//�迭 A���� ������ * �迭 B���� ū�� ���ؼ� �����ؼ� sum�� �����ֱ�
	for (int i = 0; i < n; i++) {
			sum+=A[i]*findMax(B);
	}

	//����� ���
	printf("%d", sum);
}