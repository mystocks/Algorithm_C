#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void getLCStr(const char* sz1, const char* sz2)
{
	if (NULL == sz1 || NULL == sz2)
	{
		return;
	}
	int** L = NULL;
	int iLen1 = strlen(sz1)+1;
	int iLen2 = strlen(sz2)+1;
	int i;
	int j;

	L = new int*[iLen1];
	for (i=0; i < iLen1; i++)
	{
		L[i] = new int[iLen2];
		for (j = 0; j < iLen2; j++)
		{
			L[i][j] = 0;
		}
	}
	printf("   ");
	for (i = 0; i < iLen2; i++)
	{
		printf("%c  ", sz2[i]);
	}
	printf("\n");
	for (i = 1; i < iLen1; i++)
	{
		printf("%c  ", sz1[i -1]);
		for (j = 1; j < iLen2; j++)
		{
			if (sz1[i-1] == sz2[j-1])
			{
				L[i][j] = L[i-1][j-1] + 1;
			}
			printf("%d  ", L[i][j]);
		}
		printf("\n");
	}
	i = 0;
	j = 0;
	int iMax = 0;
	int iIndex = 0;
	int jIndex = 0;
	for (int i = 0; i < iLen1; i ++)
	{
		for (int j = 0; j < iLen2; j ++)
		{
			if (L[i][j] > iMax)
			{
				iMax = L[i][j];
				iIndex = i;
				jIndex = j;     
			}
		}
	}
	while(iIndex > 0 && jIndex > 0)
	{
		printf("%c ", sz1[iIndex-1]);
		iIndex --;
		jIndex --;
	}
	printf("\n");
}

void getLCS()
{
	char sz1[] = "addffdefd";
	char sz2[] = "ffdaaadfliafdsedd";
	int** L = NULL;
	int iLen1 = strlen(sz1)+1;
	int iLen2 = strlen(sz2)+1;
	int i;
	int j;

	L = new int*[iLen1];
	for (i=0; i < iLen1; i++)
	{
		L[i] = new int[iLen2];
		for (j = 0; j < iLen2; j++)
		{
			L[i][j] = 0;
		}
	}
	printf("   ");
	for (i = 0; i < iLen2; i++)
	{
		printf("%c  ", sz2[i]);
	}
	printf("\n");
	for (i = 1; i < iLen1; i++)
	{
		printf("%c  ", sz1[i -1]);
		for (j = 1; j < iLen2; j++)
		{
			if (sz1[i-1] == sz2[j-1])
			{
				L[i][j] = L[i-1][j-1] + 1;
			}
			else
			{
				L[i][j] = L[i-1][j] >= L[i][j-1] ? L[i-1][j] : L[i][j-1];
			}
			printf("%d  ", L[i][j]);
		}
		printf("\n");
	}
	i = iLen1 -1;
	j = iLen2 -1;
	int indexlen = L[i][j];
	char *pTemp = new char[indexlen+1];
	while(i >0 && j > 0)
	{
		if (sz1[i-1] == sz2[j-1])
		{
			pTemp[--indexlen] = sz1[i-1];
			printf("%c\n", sz1[i-1]);
			i --;
			j --;
		}
		else if (sz1[i-1] != sz2[j-1])
		{
			if (L[i-1][j] >= L[i][j-1])
			{
				i --;
			}
			else
			{
				j --;
			}
		}
	}
	pTemp[L[iLen1-1][iLen2-1]] = '\0';
	printf("\n%s\n", pTemp);
	if (NULL != L)
	{
		for (int i = 0; i < iLen1; i++)
		{
			if (NULL != L[i])
			{
				delete []L[i];
			}
		}
		delete []L;
	}
	if (NULL != pTemp)
	{
		delete []pTemp;
	}
}
void main()
{
	char sz1[] = "addffdefd";
	char sz2[] = "ffdaaadfliaffdsedd";
	getLCS();
	getLCStr(sz1, sz2);
	system("pause");
}