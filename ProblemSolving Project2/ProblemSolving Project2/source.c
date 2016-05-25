#include <stdio.h>

void setWL(char (* Team)[20],int W,int L)
{
	Team[W][L] = 'W';
	Team[L][W] = 'L';
}
void setTie(char(*Team)[20], int a, int b)
{
	Team[a][b] = 'T';
	Team[b][a] = 'T';
}
void calPoint(char(*Team)[20],int * point, int W, int L, int T)
{
	int i, j,sum;
	for (i = 0; i < 20; i++)
	{
		sum = 0;
		for (j = 0; j < 20; j++)
		{
			if (i == j)continue;
			else if (Team[i][j] == 'W')
			{
				sum += W;
			}
			else if (Team[i][j] == 'L')
			{
				sum += L;
			}
			else
			{
				sum += T;
			}
		}
		point[i] = sum;
	}
}
int main(void)
{
	char team[20][20];
}