#include <stdio.h>

int soma(int n)
{
    int a=0, b=0;

    a = n % 10;
    b = (n - a)/10;

    if (b <= 0) {
        return a;
    } else {
        return a + soma(b);
    }
}

int main()
{
    int n=0, s=0;

    printf("\nInforme digitos positivos: ");
    scanf("%d", &n);

    s = soma(n);
    printf("\nA soma dos digitos eh %d.\n", s);

    return 0;
}