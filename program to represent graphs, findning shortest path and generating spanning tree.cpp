#include <stdio.h>
#include <stdlib.h>

void dir_graph();
void undir_graph();
void read_graph(int adj_mat[][50], int n);

int main()
{
    int option;
    system("cls");

    do
    {
        printf("\n A Program to represent a Graph by using an ");
        printf("Adjacency Matrix method \n");
        printf("\n 1. Directed Graph ");
        printf("\n 2. Un-Directed Graph ");
        printf("\n 3. Exit");
        printf("\n\n Select a proper option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            dir_graph();
            break;
        case 2:
            undir_graph();
            break;
        case 3:
            return 0;
        default:
            printf("\nInvalid option. Try again.\n");
            break;
        }
    } while (1);

    return 0;
}

void dir_graph()
{
    int adj_mat[50][50];
    int n, in_deg, out_deg;

    printf("\n How Many Vertices?");
    scanf("%d", &n);
    read_graph(adj_mat, n);

    printf("\n Vertex \t In Degree \t Out Degree \t Total Degree");

    for (int i = 1; i <= n; i++)
    {
        in_deg = out_deg = 0;

        for (int j = 1; j <= n; j++)
        {
            if (adj_mat[j][i] == 1)
                in_deg++;
        }

        for (int j = 1; j <= n; j++)
        {
            if (adj_mat[i][j] == 1)
                out_deg++;
        }

        printf("\n %5d \t\t %d \t\t %d \t\t %d\n", i, in_deg, out_deg, in_deg + out_deg);
    }
}

void undir_graph()
{
    int adj_mat[50][50];
    int n, deg;

    printf("\n How Many Vertices ?");
    scanf("%d", &n);
    read_graph(adj_mat, n);

    printf("\n Vertex \t Degree");

    for (int i = 1; i <= n; i++)
    {
        deg = 0;

        for (int j = 1; j <= n; j++)
        {
            if (adj_mat[i][j] == 1)
                deg++;
        }

        printf("\n %5d \t\t %d\n", i, deg);
    }
}

void read_graph(int adj_mat[][50], int n)
{
    char reply;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adj_mat[i][j] = 0;
                continue;
            }

            printf("\n Vertices %d & %d are Adjacent ? (Y/N):", i, j);
            fflush(stdin);
            scanf(" %c", &reply);

            if (reply == 'y' || reply == 'Y')
                adj_mat[i][j] = 1;
            else
                adj_mat[i][j] = 0;
        }
    }
}
