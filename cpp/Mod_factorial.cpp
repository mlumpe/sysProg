int factorial(int a) {
    int res = 1;
    
    if(a < 0) return -1;
    
    for (int i = 1; i < a+1; i++) {
        res *= i;
    }
    
    return res;
}
