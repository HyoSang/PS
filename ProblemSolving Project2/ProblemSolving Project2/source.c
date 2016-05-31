#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void setWL(char (* Team)[20],int W,int L)//set Win and lose
{
	Team[W][L] = 'W';
	Team[L][W] = 'L';
}
void setTie(char(*Team)[20], int a, int b)//set Tie
{
	Team[a][b] = 'T';
	Team[b][a] = 'T';
}
void Print(char(*Team)[20])
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			printf("%c", Team[i][j]); //print team result
		}
		printf("\n");
	}
}
int setResult(char tok, char(*Team)[20], int a, int b)//set Win,lose,Tie for no violation rule
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
	char team[20][20];//result array
	int win, lose, draw, rank, tok,i,j;//win,lose,draw : each case point repository, rank : save rank tok : max or min
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			team[i][j] = 0; //initialize team array
		}
	}
	scanf("%d %d %d %d %d", &win, &draw, &lose, &rank, &tok);//get input
	if (win == lose && lose == draw)//if three points are same, all team must get same point. so set tie all team.
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
	if (tok == 0)//case min
	{
		if ((win>=lose && lose<draw)|| (lose >= win && win<draw))//case that draw isn't smallest 
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
				}//set result above input rank team highest
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
				}//set result above input rank team highest
			}
		}
		else // draw is smallest, set all result by tie
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
			if (((20-rank) / 2) * win<(20-rank)*draw)//We set result 20-rank result by each team so compare case
			{
				if (rank - 1 % 2 != 0)
				{
					if (win > draw)
					{
						for (i = rank - 1; i < 19; i++)
						{
							setResult('t', team, i, i + 1);
						}
					}
				}
				for (i = rank-1; i < 20; i++)//if we choose win or lose, win or lose can be setted 20-rank times.
				{
					tok = 0;
					for (j = rank-1; j < 20; j++)
					{
						tok += setResult('w', team, i, j);
						if (tok == ((20-rank) / 2))break;//so count case win or lose. 
					}
				}
				for (i = rank-1; i < 20; i++) // if we set result 20 - rank times, last results are setted by opposite value.
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
				if (rank - 1 % 2 != 0)
				{
					if (lose > draw)
					{
						for (i = rank - 1; i < 19; i++)
						{
							setResult('t', team, i, i + 1);
						}
					}
				}
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
						tok += setResult('l', team, i, j);
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
		if ((win >= lose && (win>draw) || (lose >= win && lose > draw)))
		{
			if (win > lose)
			{
				for (i = 0; i < rank; i++)
				{
					for (j = rank; j < 20; j++)
					{
						setResult('w', team, i, j);
					}
				}
			}
			else
			{
				for (i = 0; i < rank; i++)
				{
					for (j = rank; j < 20; j++)
					{
						setResult('l', team, i, j);
					}
				}
			}
		}
		else
		{
			for (i = 0; i < rank; i++)
			{
				for (j = rank; j < 20; j++)
				{
					setResult('t', team, i, j);
				}
			}
		}
		for (i = rank; i < 20; i++)
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