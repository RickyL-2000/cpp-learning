#include <iostream>

int main ()
{
	char choice;
	int n, i;
	int result = 1;

	scanf("%c %d", &choice, &n);

	for (i=1; i<=n; i=i+1) {
		if ( choice=='u' ) {
			result = result - i/2;
		}
		else if ( choice=='v' ) {
			result = result + i*5;
		}
		else {
			printf("Welcome to ECE 120! ");
		}
	}
	printf("result=%d\n", result);

	return 0;
}