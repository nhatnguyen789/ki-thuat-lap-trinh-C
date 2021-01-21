#include <stdio.h>
 
int giaiThua(int n) 
{
    if(n == 0) return 1; // dieu kien dung
    return giaiThua(n-1) * n; // loi goi chinh no
}
 
void main() {
    int n = 5;
    printf("%d! = %d",n, giaiThua(n));
   
}
