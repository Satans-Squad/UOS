
def isPrime(n,divisor = 2):
    if n<=2:
        return n == 2
    
    if n % divisor == 0:
        return False
    
    if divisor * divisor > n:
        return True

    return isPrime(n,divisor+1)

def generatePrimeLimit(limit,current = 2):
    if current <= limit:
        if isPrime(current):
            print(current)
        generatePrimeLimit(limit,current+1)
        

limit = 7
generatePrimeLimit(limit)