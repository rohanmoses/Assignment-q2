#include <stdio.h>
void readMatrix(int firstMatrix[][10], int secondMatrix[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
int i, j;
printf("\nEnter elements of matrix 1:\n");
for(i = 0; i < rowFirst; ++i)
{
for(j = 0; j < columnFirst; ++j)
{
printf(" a[%d][%d]: ", i + 1, j + 1);
scanf("%d", &firstMatrix[i][j]);
}
}
printf("\nEnter elements of matrix 2:\n");
for(i = 0; i < rowSecond; ++i)
{
for(j = 0; j < columnSecond; ++j)
{
printf("b[%d][%d]: ", i + 1, j + 1);
scanf("%d", &secondMatrix[i][j]);
}
}
}
void printMatrix(int firstMatrix[][10], int secondMatrix[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
int i, j;
printf("\n Elements of matrix 1:\n");
for(i = 0; i < rowFirst; ++i)
{
for(j = 0; j < columnFirst; ++j)
{
printf("%d\t", firstMatrix[i][j]);
}
printf("\n");
}
printf("\n Elements of matrix 2:\n");
for(i = 0; i < rowSecond; ++i)
{
for(j = 0; j < columnSecond; ++j)
{
printf("%d\t", secondMatrix[i][j]);
}
printf("\n");
}
printf("\n");
}

void sum(int firstMatrix[][10], int secondMatrix[][10], int rowFirst, int columnFirst, int sumResult[][10])
{
    int i, j, k;

for(i = 0; i < rowFirst; ++i)
{
for(j = 0; j < columnFirst; ++j)
{
sumResult[i][j]=firstMatrix[i][j]+secondMatrix[i][j];
}
}
printf("Sum of the two matrix is : \n");
for(i = 0; i < rowFirst; ++i)
{

for(j = 0; j < columnFirst; ++j)
{
printf("%d\t", sumResult[i][j]);
}
printf("\n");
}
}

void multiplyMatrix(int firstMatrix[][10], int secondMatrix[][10], int mult[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond)
{
int i, j, k;

for(i = 0; i < rowFirst; ++i)
{
for(j = 0; j < columnSecond; ++j)
{
mult[i][j] = 0;
}
}

for(i = 0; i < rowFirst; ++i)
{
for(j = 0; j < columnSecond; ++j)
{
for(k=0; k<columnFirst; ++k)
{
mult[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
}
}
}
printf("\nMatrix After Multiplication:\n");
for(i = 0; i < rowFirst; ++i)
{
for(j = 0; j < columnSecond; ++j)
{
printf("%d  ", mult[i][j]);
if(j == columnSecond - 1)
printf("\n\n");
}
}
}

void identityCheck(int rowFirst, int columnFirst, int rowSecond, int columnSecond, int firstMatrix[][10], int secondMatrix[][10])
{
    int i, j, flag=1;
    for(i = 0; i < rowFirst; ++i)
{
for(j = 0; j < columnFirst; ++j)
{
    if(firstMatrix[i][j] != 1 && firstMatrix[j][i] !=0)
    {
        flag=0;
        break;
    }
}
}
if(flag==1)
{
    printf("The first matrix is a identity matrix \n");
}
else
{
    printf("The first matrix is not an identity matrix \n");
}

flag=1;
for(i = 0; i < rowSecond; ++i)
{
for(j = 0; j < columnSecond; ++j)
{
    if(secondMatrix[i][j] != 1 && secondMatrix[j][i] !=0)
    {
        flag=0;
        break;
    }
}
}
if(flag==1)
{
    printf("The second matrix is a identity matrix \n");
}
else
{
    printf("The second matrix is not an identity matrix \n");
}
}
int main()
{
int firstMatrix[10][10], secondMatrix[10][10], mult[10][10], sumResult[10][10] ,rowFirst, columnFirst, rowSecond, columnSecond, i, j, k;

printf("Enter rows and column for first matrix size less than 10: ");
scanf("%d %d", &rowFirst, &columnFirst);

printf("Enter rows and column for second matrix size less than 10: ");
scanf("%d %d", &rowSecond, &columnSecond);
   
    readMatrix(firstMatrix, secondMatrix,rowFirst, columnFirst, rowSecond, columnSecond );
    printMatrix(firstMatrix, secondMatrix,rowFirst, columnFirst, rowSecond, columnSecond );
    sum(firstMatrix, secondMatrix,rowFirst, columnFirst, sumResult);

if(columnFirst != rowSecond)
{
printf("Error! column of first matrix not equal to row of second.\n");
printf("Enter rows and column for first matrix: ");
scanf("%d%d", &rowFirst, &columnFirst);
printf("Enter rows and column for second matrix: ");
scanf("%d%d", &rowSecond, &columnSecond);
}
else
{
    multiplyMatrix(firstMatrix, secondMatrix, mult, rowFirst, columnFirst, rowSecond, columnSecond );
}
   
    identityCheck(rowFirst, columnFirst, rowSecond, columnSecond, firstMatrix, secondMatrix);
return 0;
}