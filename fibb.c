
long fib_it(int x) {

    long f0, f1, tmp, i;
    
    f0 = 0;
    f1 = 1;
    
    for (i=2; i<=x; ++i) {
        tmp = f1;
        f1 = f0 + f1;
        f0 = tmp;
        
    }
    
    return f1;

}


int fib_rec(int x) {
    
    if (x <= 1) {
        
      return x;
    
    } else return  fib_rec(x-1) + fib_rec(x-2);
}


int main(int argc, char* argv[]) {

    
    int result = fib_rec(4);
    printf("Fibo at position 4: %d\n", result);
    return 0;

}



//0 1 1 2 3 5 8 13
