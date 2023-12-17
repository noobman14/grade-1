#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int flagx = 0; int flagx1 = 0;
int passengerup(int a, int n) {
	
	if (n== 1) { return a; }
	else if (n == 2) { flagx++; return 0;  }
	else {
		return passengerup(a, n - 1) + passengerup(a, n - 2);
	}
}
int passengerup1(int a, int n) {

	if (n == 1) { return a; }
	else if (n == 2) { flagx1++; return 0; }
	else {
		return passengerup1(a, n - 1) + passengerup1(a, n - 2);
	}
}
int passengerdown(int a, int n) {
	
	if (n == 1) { return 0; }
	else if (n == 2) { flagx1++; return 0; }
	else {
		return passengerup1(a, n - 1);
	}
}
int main() {
	int a, n, m, x;
	scanf("%d %d %d %d", &a, &n, &m, &x);
	int upsum = 0;
	for (int i = 1; i < n; i++) {
		upsum += passengerup(a, i);
	}
	int downsum = 0;
	for (int i = 1; i < n; i++) {
		downsum += passengerdown(a, i);
	}
	int p = (m-(upsum - downsum))/abs(flagx-flagx1);
	downsum = 0; upsum = 0; flagx = 0; flagx1 = 0;
	for (int i = 1; i <= x; i++) {
		downsum += passengerdown(a, i);
		upsum += passengerup(a, i);
	}
	x = upsum - downsum + p * abs((flagx1 - flagx));
	printf("%d\n", x);
	return 0;
}