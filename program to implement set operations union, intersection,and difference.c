/*Program to implement set operations union, intersection
, and difference*/
#define MAX 30
#include <stdio.h>
#include <conio.h>
void sort(int set[]);
void create(int set[]);
void Union(int set1[], int set2[], int set3[]);
void intersection(int set1[], int set2[], int set3[]);
void difference(int set1[], int set2[], int set3[]);
int member(int set[], int x);
void display(int set[]);

int main()
{
	int set1[MAX], set2[MAX], set3[MAX];
	int x, op, i;

	set1[0] = set2[0] = set3[0] = 0;

	printf("\nCreating First set*******");
	create(set1);
	printf("\nMembers of the set: ");
	display(set1);
	printf("\nCreating Second set******");
	create(set2);
	printf("\nMembers of the set: ");
	display(set2);

	// calculate union and stored in set 3
	Union(set1, set2, set3);
	printf("Union of the sets: ");
	display(set3);

	// calculate intersections and stored in set 3
	intersection(set1, set2, set3);
	printf("Intersection: ");
	display(set3);

	// calculate difference and stored in set3
	difference(set1, set2, set3);
	printf("Difference: ");
	display(set3);

	return 0;
}
// create set[] with inital elements

void create(int set[])
{
	int n, i, x;
	set[0] = 0; // make it a null set
	printf("\n Number of elements in the set: ");
	scanf("%d", &n);
	printf("\nEnter set elements: ");
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &set[i]);
	}
	set[0] = n; // number of elements
}
void display(int set[])
{
	int i, n;
	n = set[0];
	sort(set);
	printf("{ ");
	for (i = 1; i <= n; i++)
	{
		if (i == n)
		{
			printf("%d ", set[i]);
			break;
		}
		printf("%d, ", set[i]);
	}
	printf("}\n");
}

// union stored in set3
void Union(int set1[], int set2[], int set3[])
{
	int i, n;
	// copy set1 to set 3
	set3[0] = 0; // make set 3 a null set
	n = set1[0]; // number of elements in the set

	// Union of set1,set2=set1 + (set2-set1)
	for (i = 0; i <= n; i++)
		set3[i] = set1[i];

	n = set2[0];
	for (i = 1; i <= n; i++)
		if (!member(set3, set2[i]))
			set3[++set3[0]] = set2[i]; // insert and increment no of elements
}
// function returns 1 or 0 depending on whether x belongs to set[] or not
int member(int set[], int x)
{
	int i, n;
	n = set[0]; // number of elements in the set
	for (i = 1; i <= n; i++)
		if (x == set[i])
			return 1;
	return 0;
}
// intersection of the set1[] and set2[] is stored in set3[]
void intersection(int set1[], int set2[], int set3[])
{
	int i, n;
	set3[0] = 0; // make a null set
	n = set1[0]; // number of elements in the set
	for (i = 1; i <= n; i++)
		if (member(set2, set1[i]))	   // all common elements are inserted in set3[]
			set3[++set3[0]] = set1[i]; // insert and increment the number of elements
}

// difference of set1 and set2
void difference(int set1[], int set2[], int set3[])
{
	int i, n;
	n = set1[0]; // number if elements in the set
	set3[i] = 0; // make it a null set
	for (i = 1; i <= n; i++)
		if (!member(set2, set1[i]))
			set3[++set3[0]] = set1[i]; // insert as increment the number of elements
}
void sort(int set[])
{
	int n, i, j, temp;
	n = set[0];
	for (i = 1; i <= n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			if (set[i] > set[j])
			{
				temp = set[i];
				set[i] = set[j];
				set[j] = temp;
			}
		}
	}
}
