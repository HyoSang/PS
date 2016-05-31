#define _CRT_SECURE_NO_WARNINGS
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
void Print(char(*Team)[20])
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			printf("%c", Team[i][j]);
		}
		printf("\n");
	}
}
int setResult(char tok, char(*Team)[20], int a, int b)
{
	if (Team[a][b] != 0||Team[b][a]!=0)return 0;
	if (a == b)
	{
		Team[a][b] = 'X';
		return 0;
	}
	if (tok == 'w')
	{
		setWL(Team, a, b);
	}
	else if (tok == 'l')
	{
		setWL(Team, b, a);
	}
	else
	{
		setTie(Team, a, b);
	}
	return 1;
}
int main(void)
{
	char team[20][20];
	int win, lose, draw, rank, tok,i,j;
	char ranka[3];
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			team[i][j] = 0;
		}
	}
	scanf("%d %d %d %d %d", &win, &draw, &lose, &rank, &tok);
	if (win == lose && lose == draw)
	{
		for (i = 0; i < 20; i++)
		{
			for (j = 0; j < 20; j++)
			{
				if(i==j)team[i][j] = 'X';
				else team[i][j] = 'T';
			}
		}
		Print(team);
		return;
	}
	if (win > lose)
	{
		if (win > draw)
		{
			if (lose > draw)
			{
				ranka[0] = 'w';
				ranka[1] = 'l';
				ranka[2] = 'd';
			}
			else
			{
				ranka[0] = 'w';
				ranka[1] = 'd';
				ranka[2] = 'l';
			}

		}
		else
		{
			ranka[0] = 'd';
			ranka[1] = 'w';
			ranka[2] = 'l';
		}
	}
	else
	{
		if (lose > draw)
		{
			if (win > draw)
			{
				ranka[0] = 'l';
				ranka[1] = 'w';
				ranka[2] = 'd';
			}
			else
			{
				ranka[0] = 'l';
				ranka[1] = 'd';
				ranka[2] = 'w';
			}
		}
		else
		{
			ranka[0] = 'd';
			ranka[1] = 'l';
			ranka[2] = 'w';
		}
	}
	if (tok == 0)
	{
		if ((win>=lose && lose<draw)|| (lose >= win && win<draw))
		{
			if (win > lose)
			{
				for (i = 0; i < rank - 1; i++)
				{
					for (j = rank - 1; j < 20; j++)
					{
						setResult('w', team, i, j);
					}
				}
				for (i = 0; i < rank - 1; i++)
				{
					for (j = 0; j < rank - 1; j++)
					{
						setResult('w', team, i, j);
					}
				}
			}
			else
			{
				for (i = 0; i < rank - 1; i++)
				{
					for (j = rank - 1; j < 20; j++)
					{
						setResult('l', team, i, j);
					}
				}
				for (i = 0; i < rank - 1; i++)
				{
					for (j = 0; j < rank - 1; j++)
					{
						setResult('l', team, i, j);
					}
				}
			}
		}
		else
		{
			for (i = 0; i < 20; i++)
			{
				for (j = 0; j < 20; j++)
				{
					setResult('t', team, i, j);
				}
			}
		}
		if (win >= lose)
		{
			if (((20-rank) / 2) * win<(20-rank)*draw)
			{
				for (i = rank-1; i < 20; i++)
				{
					tok = 0;
					for (j = rank-1; j < 20; j++)
					{
						tok += setResult('w', team, i, j);
						if (tok == ((20-rank) / 2))break;
					}
				}
				for (i = rank-1; i < 20; i++)
				{
					for (j = rank-1; j < 20; j++)
					{
						setResult('w', team, i, j);
					}
				}
			}
			else
			{
				for (i = rank-1; i<20; i++)
				{
					for (j = rank-1; j < 20; j++)
					{
						setResult('t', team, i, j);
					}
				}
			}
		}
		else
		{
			if (((20 - rank) / 2) * lose<(20 - rank)*draw)
			{
				for (i = rank-1; i < 20; i++)
				{
					tok = 0;
					for (j = rank-1; j < 20; j++)
					{
						tok += setResult('l', team, i, j);
						if (tok == ((20 - rank) / 2))break;
					}
				}
				for (i = rank-1; i < 20; i++)
				{
					for (j = rank-1; j < 20; j++)
					{
						setResult('l', team, i, j);
					}
				}
			}
			else
			{
				for (i = rank-1; i<20; i++)
				{
					for (j = rank-1; j < 20; j++)
					{
						setResult('t', team, i, j);
					}
				}
			}

		}
	}
	else
	{
		for (i = 0; i<rank; i++)
		{
			for (j = rank; j<20; j++)
			{
				setResult(ranka[0], team, i, j);
			}
		}
		for (i = rank; i<20; i++)
		{
			for (j = rank; j < 20; j++)
			{
				setResult('t', team, i, j);
			}
		}
		

		if (win >= lose)
		{
			if (((rank - 1) / 2) * win>(rank - 1)*draw)
			{
				for (i = 0; i < rank; i++)
				{
					tok = 0;
					for (j = 0; j < rank; j++)
					{
						tok += setResult('w', team, i, j);
						if (tok == ((rank - 1) / 2))break;
					}
				}
				for (i = 0; i < rank; i++)
				{
					for (j = 0; j < rank; j++)
					{
						setResult('w', team, i, j);
					}
				}
			}
			else
			{
				for (i = 0; i<rank; i++)
				{
					for (j = 0; j < rank; j++)
					{
						setResult('t', team, i, j);
					}
				}
			}
		}
		else
		{
			if (((rank - 1) / 2) * lose>(rank - 1)*draw)
			{
					for (i = 0; i < rank; i++)
					{
						tok = 0;
						for (j = 0; j < rank; j++)
						{
							tok += setResult('l', team, i, j);
							if (tok == ((rank - 1) / 2))break;
						}
					}
					for (i = 0; i < rank; i++)
					{
						for (j = 0; j < rank; j++)
						{
							setResult('l', team, i, j);
						}
					}
			}
			else
			{
				for (i = 0; i < rank; i++)
				{
					for (j = 0; j < rank; j++)
					{
						setResult('t', team, i, j);
					}
				}
			}
		}
	}
	Print(team);

}