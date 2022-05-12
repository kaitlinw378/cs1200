#include <iostream> 

int compute_squares(int *a,int *b, unsigned int n){
    int *p, *q; 
    q = b; 
    for (p = a; p < a + n; p++, q++){
        *q = *p * (*p);  
    }
}

int main(){
    unsigned int n = 5;
    int a[] = {1,2,3,4,5};
    int b[] = {0,0,0,0,0};

    compute_squares(a,b,n);
    for (int i = 0; i < n; i++){
        std::cout << b[i] << " "; 
    }

}
