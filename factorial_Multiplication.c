#include <stdio.h>
void multiplication_table();
int multiply(int x, int a[], int size)
{
    int carry = 0, i, p;

    for (i = 0; i < size; ++i)
    {
        p = a[i] * x + carry;
        a[i] = p % 10;
        carry = p / 10;
    }

    while (carry != 0)
    {
        a[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}

int main()
{
    int n, a[1000], i, size = 1;
    a[0] = 1;

    printf("Enter any large number:");
    scanf("%d", &n);

    for (i = 2; i <= n; ++i)
    {
        size = multiply(i, a, size);
    }

    for (i = size - 1; i >= 0; --i)
    {
        printf("%d", a[i]);
    }
    multiplication_table();
    return 0;
}

void multiplication_table()
{
    int n, i;
    printf("\nEnter an integer: ");
    scanf("%d", &n);
    for (i = 1; i <= 10; ++i)
    {
        printf("%d * %d = %d \n", n, i, n * i);
    }
}