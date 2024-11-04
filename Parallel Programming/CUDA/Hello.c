%%writefile Hello.cu

#include <stdio.h>
#include <cuda_runtime.h>

int main(){
    kernel<<<1,1>>> ();
    printf("Hello World");
    return 0;
}
