// Program to implement Boolean matrix operations result,meet,and boolean product
#include <stdio.h>
void makeMatrix(int matrix[][6], int row, int column)
{
    int i, j;
    matrix[0][0] = row;
    matrix[0][1] = column;
    printf("Enter the elements of the matrix:\n");
    for (i = 1; i <= row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void printMatrix(int matrix[][6])
{
    int i, j, m, n;
    m = matrix[0][0], n = matrix[0][1];
    for (i = 1; i <= m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void joinMatrix(int mat1[][6], int mat2[][6], int result[][6])
{
    int i, j, m, n;
    result[0][0] = m = mat1[0][0];
    result[0][1] = n = mat2[0][1];
    for (i = 1; i <= m; i++)
    {
        for (j = 0; j < n; j++)
        {
            result[i][j] = mat1[i][j] || mat2[i][j];
        }
    }
}
void meetMatrix(int mat1[][6], int mat2[][6], int result[][6])
{
    int i, j, m, n;
    m = mat1[0][0];
    n = mat2[0][1];
    for (i = 1; i <= m; i++)
    {
        for (j = 0; j < n; j++)
        {
            result[i][j] = mat1[i][j] && mat2[i][j];
        }
    }
}

void BooleanProduct(int matrix1[][6], int matrix2[][6], int result[][6], int row, int col)
{
    int i, j, k;

    for (i = 1; i <= row; i++)
    {
        for (j = 0; j < col; j++)
        {
            result[i][j] = 0;
            for (k = 1; k <= matrix1[0][1]; k++)
            {
                result[i][j] = result[i][j] || matrix1[i][k] && matrix2[k][j];
            }
        }
    }
}

int main()
{
    printf("Maximum permitted dimension is 5*5 matrix\n");
    int first[6][6], second[6][6], result[6][6], r1, c1, r2, c2;
    printf("First matrix: \n");
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &r1, &c1);
    makeMatrix(first, r1, c1);

    printf("Second matrix: \n");
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &r2, &c2);
    makeMatrix(second, r2, c2);

    if ((r1 == r2) && (c1 == c2))
    {
        joinMatrix(first, second, result);
        printf("Boolean join of the matrices:\n");
        printMatrix(result);

        meetMatrix(first, second, result);
        printf("Boolean meet of the matrices:\n");
        printMatrix(result);
    }
    else
        printf("The matrices don't have equal dimensions so Boolean join and meet are not possible!!\n");
    if (c1 == r2)
    {
        BooleanProduct(first, second, result, r1, c2);
        printf("Boolean product of the matrices:\n");
        printMatrix(result);
    }
    else
        printf("Matrix multiplication is not possible!!\n");
    return 0;
}
