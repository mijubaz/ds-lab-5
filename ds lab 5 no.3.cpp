#include <stdio.h>
#include <stdlib.h>

long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        exp = exp >> 1; 
        base = (base * base) % mod; 
    }
    return result;
}

int isPrime(int n, int k) {
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;

    for (int i = 0; i < k; i++) {
        int a = 2 + rand() % (n - 4); 
        if (powerMod(a, n - 1, n) != 1) {
            return 0; 
        }
    }

    return 1; 
}

int main() {
    int n, k = 5;

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);

    if (isPrime(n, k)) {
        printf("%d is probably prime.\n", n);
    } else {
        printf("%d is composite.\n", n);
    }

    return 0;
}

