
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
long int factorial(long int n);
int get_rowcount(int argc, char* argv[]);
bool pascalstriangle_create(long int* pt[], int rowcount);
void pascalstriangle_populate(long int* pt[], int rowcount);
void pascalstriangle_print_left(long int* pt[], int rowcount);
void pascalstriangle_print_centre(long int* pt[], int rowcount);
void pascalstriangle_free(long int* pt[], int rowcount);

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(int argc, char* argv[])
{
    puts("---------------------");
    puts("| codedrome.com     |");
    puts("| Pascal's Triangle |");
    puts("---------------------");

    int rowcount = get_rowcount(argc, argv);

    if(rowcount > 0)
    {
        long int* pt[rowcount];

        if(pascalstriangle_create(pt, rowcount))
        {
            pascalstriangle_populate(pt, rowcount);

            pascalstriangle_print_left(pt, rowcount);

            pascalstriangle_print_centre(pt, rowcount);

            pascalstriangle_free(pt, rowcount);
        }
    }
    else
    {
        printf("Error - row count must be specified as argument\n");

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

//--------------------------------------------------------
// FUNCTION get_rowcount
//--------------------------------------------------------
int get_rowcount(int argc, char* argv[])
{
    if(argc == 2)
    {
        return atoi(argv[1]);
    }
    else
    {
        return 0;
    }
}

//--------------------------------------------------------
// FUNCTION pascalstriangle_create
//--------------------------------------------------------
bool pascalstriangle_create(long int* pt[], int rowcount)
{
    int columncount = 1;

    for(int row = 0; row < rowcount; row++)
    {
        pt[row] = malloc(sizeof(long int) * columncount);

        if(pt[row] == NULL)
        {
            return false;
        }

        columncount++;
    }

    return true;
}

//--------------------------------------------------------
// FUNCTION pascalstriangle_populate
//--------------------------------------------------------
void pascalstriangle_populate(long int* pt[], int rowcount)
{
    int columncount = 1;
    int column;

    for(int row = 0; row < rowcount; row++)
    {
        for(column = 0; column < columncount; column++)
        {
            pt[row][column] = factorial(row) / (factorial(column) * factorial(row - column));
        }

        columncount++;
    }
}

//--------------------------------------------------------
// FUNCTION pascalstriangle_print_left
//--------------------------------------------------------
void pascalstriangle_print_left(long int* pt[], int rowcount)
{
    int columncount = 1;
    int column;

    for(int row = 0; row < rowcount; row++)
    {
        for(column = 0; column < columncount; column++)
        {
            printf("%-4ld", pt[row][column]);
        }

        printf("\n");

        columncount++;
    }

    printf("\n");
}

//--------------------------------------------------------
// FUNCTION pascalstriangle_print_centre
//--------------------------------------------------------
void pascalstriangle_print_centre(long int* pt[], int rowcount)
{
    int columncount = 1;
    int column;

    int inset = (int)((((rowcount * 2) - 1) / 2) * 3);
    int insetindex;

    for(int row = 0; row < rowcount; row++)
    {
        for(insetindex = 0; insetindex < inset; insetindex++)
        {
            printf(" ");
        }

        for(column = 0; column < columncount; column++)
        {
            printf("%-3ld   ", pt[row][column]);
        }

        printf("\n");

        columncount++;

        inset-= 3;
    }
}

//--------------------------------------------------------
// FUNCTION pascalstriangle_print_free
//--------------------------------------------------------
void pascalstriangle_free(long int* pt[], int rowcount)
{
    for(int row = 0; row < rowcount; row++)
    {
        free(pt[row]);
    }
}

//--------------------------------------------------------
// FUNCTION factorial
//--------------------------------------------------------
long int factorial(long int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        long int f = n;

        for(int i = n - 1; i > 1; i--)
        {
            f*= i;
        }

        return f;
    }
}
