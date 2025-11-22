def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def list_primes(n1, n2):
    primes = [num for num in range(n1, n2 + 1) if is_prime(num)]
    return primes
n1 = int(input("Enter the lower range (n1): "))
n2 = int(input("Enter the upper range (n2): "))

prime_numbers = list_primes(n1, n2)
print(f"Prime numbers between {n1} and {n2}: {prime_numbers}")
