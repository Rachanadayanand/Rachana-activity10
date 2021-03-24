//WAP to find the sum of n fractions.

#include<stdio.h>
struct fractions
{
	int num, den;
};

int gcd(int a, int b)
{
	int gcd=1;
	for(int i=2; i <= a && i <= b; ++i)
    {
        if(a % i == 0 && b % i == 0)
            gcd = i;
    } 
    return gcd;
}

struct fractions* input(struct fractions a[], int n)
{
    for(int i = 0; i<n; i++)
    {
        printf("Enter fraction %d: ", i+1);
        scanf("%d%d", &a[i].num, &a[i].den);
    }
    
    return a;
}

void frac_addition(int n, struct fractions a[])
{
    struct fractions b;
    int res_num = 0;
    int res_den = a[0].den;
    for (int i = 1; i < n; i++) 
    {
        res_den = (((a[i].den * res_den)) / (gcd(a[i].den, res_den)));
    }
    
    for (int i = 0; i < n; i++) 
    {
        res_num = res_num + (a[i].num) * (res_den / a[i].den);
    }
    
    int GCD = gcd(res_num, res_den);
    
    b.num = res_num / GCD;
    b.den = res_den / GCD;
    
    output(a, b, n);
}

void output(struct fractions a[], struct fractions b, int n)
{
    printf("The sum of ");
    for(int i = 0; i<n ; i++)
    {
        printf("%d/%d + ", a[i].num, a[i].den);
    }
    printf(" is %d/%d \n", b.num, b.den);
}

int main()
{
    struct fractions a[100];
    int n;
    
    printf("Enter n: ");
    scanf("%d", &n);
    input(a, n);
    
    frac_addition(n, a);

    return 0;
}
