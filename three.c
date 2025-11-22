#include <stdio.h>

toh( p, x,y,z)
int p;
char x,y,z;
{
	if (p == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", x, y);
		return;
	}
	toh(p-1, x, z, y);
	printf("\n Move disk %d from rod %c to rod %c", p, x, y);
	toh(p-1, z,y,x);

int main()
{
	int n = 4; // Number of disks
char 'A','B','C';
	toh(n, 'A', 'C', 'B');  // A, B and C are names of rods
	return 0;
}
