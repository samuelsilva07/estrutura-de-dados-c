#include <stdio.h>
#include <string.h>

int main() {
    char* nome1 = "Nathan";
    char* nome2 = "Nataan";

    printf("%d", strcmp(nome1, nome2));
    return 0; 
}