// PRN : 240840141026
// Name : Mukund PW



#include <stdio.h>

int main() {
    int a[5], b[5], c[5];
    
    printf("Enter elements for array a:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Enter elements for array b:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &b[i]);
    }
    
    for (int i = 0,*ptr1=a,*ptr2=b,*ptr3=c; i < 5; i++,ptr1++,ptr2++,ptr3++) {
            *ptr3  = *ptr1 + *ptr2;
    }
    
    printf("Resultant array :\n");
    for (int i = 0,*ptr3=c; i < 5; i++,ptr3++) {
        printf("%d ",*ptr3);
    }
    
    return 0;
}
