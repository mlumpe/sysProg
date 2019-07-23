int nthPrime(int number) {
    int count = 1;
    
    if(number == 1) return 2;
    
    for (int i = 3;; i+=2) {
        if (isPrime(i)) {
            count++;
            if (count == number) {
                return i;
            }
        }
    }
    
    return -1;
}

