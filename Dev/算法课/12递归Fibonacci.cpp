 //FibonacciÊýÁÐ
#include <stdio.h>

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n, y;
    scanf("%d", &n);
    y = fib(n);
    printf(" Fibonacci(%d)=%d \n", n, y);
    return 0;
}
