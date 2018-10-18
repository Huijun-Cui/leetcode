
def Fibonacci(n):
    if n == 0:
        return 0;
    elif n == 1:
        return 1;
    return Fibonacci(n-1) + Fibonacci(n-2)

def Fibonacci_1(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    if n > 1:
        ix_1 = 0
        ix_2 = 1
        num = 0
        for i in range(2,n+1):
            num = ix_1 + ix_2
            ix_1 = ix_2
            ix_2 = num
        return num


if __name__ == '__main__':
    print(Fibonacci_1(5))