#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int origin;
	int n, m;
	int cycle = 0;
	scanf("%d", &origin);
	n = origin;
	while (1) {
		if (n - 10 >= 0){
			m = (n % 10) * 10 + ((n / 10 + n % 10) % 10);
		}
		else {
			m = n * 10 + n;
		}
		if (m == origin) {
			cycle++;
			break;
		}
		else {

			n = m;
			cycle++;

		}
	}

	printf("%d", cycle);

}
