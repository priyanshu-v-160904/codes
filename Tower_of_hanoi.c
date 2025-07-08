#include <stdio.h>


void towerOfHanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", A, B);
		return;
	}
	towerOfHanoi(n-1, A, C, B);
	printf("\n Move disk %d from rod %c to rod %c", n, A, B);
	towerOfHanoi(n-1, C, B, A);
}

int main()
{
	int n = 3; // Number of disks
	towerOfHanoi(n, 'A', 'B', 'C'); // A, B and C are names of rods
	return 0;
}