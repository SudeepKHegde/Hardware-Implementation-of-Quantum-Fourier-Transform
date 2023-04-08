#include <stdio.h>

int main() {
    {
    int i, j, k;
    int equal,qual,ual;
    float pop[2][1],C[4][1],D[4][1],E[4][1],pop2[2][1],pop3[2][1],temp[2][1];
    int b[2][1],z[2][1],m[2][1],res[10][10],res2[10][10],res3[10][10];
    int a[2][2] = {{1,1},{1,-1}};
    int e[2][1] = {{0},{1}};
    int crot9[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,100}};
    int crot4[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,200}}; 
    float tensor[4][1] = {{0},{0},{0},{0}};
    float tensor2[4][1] = {{0},{0},{0},{0}};
    float tensor3[4][1] = {{0},{0},{0},{0}};
        printf("QFT-Implementation : EC203,EC222\n");
        printf("Enter The Input Qubit (Q0):\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1 ; j++) {
                scanf("%d", & b[i][j]);
            }
        }
        printf("Enter The Input Qubit (Q1):\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1 ; j++) {
                scanf("%d", & z[i][j]);
            }
        }
        printf("Enter The Input Qubit (Q2):\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1 ; j++) {
                scanf("%d", & m[i][j]);
            }
        }
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) {
                res[i][j] = 0;
                for (k = 0; k < 2; k++) {
                    res[i][j] += a[i][k] * m[k][j];
                }
            }
        }

        printf("Hadamard O/P (Stage-I): \n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) 
                printf("%f\t", 0.707 * res[i][j]);
                printf("\n");
        }

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) 
                pop[i][j] = 0.707 * res[i][j];
        }
        
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 1; j++) {
            if (e[i][j] != z[i][j]) {
                equal = 0;}
            else{
                equal = 1;
                }
            
        }
    }

    if(equal == 1){
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tensor[i*2 + j][0] = z[i][0] * pop[j][0];
        }
    }
    for (int j = 0; j < 4; j++) {
        C[0][j] = 0;
        for (int k = 0; k < 4; k++) {
            C[0][j] +=  crot9[k][j] * tensor[0][k];
        }
    }
    printf(" ");
    printf("\n");
    printf("CROT O/P (Stage-II): ");
    printf("\n");
    for (int j = 0; j < 4; j++){
    
        if(C[0][j] >= 60){
           printf("0.707i");
           printf("\n");
        }
        else{
           printf("%f\t",C[0][j]);
           printf("\n");
        }
    }
    

    }



    else{
        printf("\n");
        printf("Stage-II : No Tensor");
        printf("\n");
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 1; j++) {
            if (e[i][j] != b[i][j]) {
                qual = 0;}
            else{
                qual = 1;
                }
            
        }
    }

    if(qual == 1){
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tensor2[i*2 + j][0] = b[i][0] * pop[j][0];
        }
    }
    for (int j = 0; j < 4; j++) {
        D[0][j] = 0;
        for (int k = 0; k < 4; k++) {
            D[0][j] +=  crot4[k][j] * tensor2[0][k];
        }

    }
    printf(" ");
    printf("\n");
    printf("CROT O/P (Stage-III): ");
    printf("\n");
    for (int j = 0; j < 4; j++){
    
        if(D[0][j] >= 60){
           printf("0.707 + 0.707i");
           printf("\n");
        }
        else{
           printf("%f\t",D[0][j]);
           printf("\n");
        }
    }
    

    }

    else{
        printf("\n");
        printf("Stage-III : No Tensor");
        printf("\n");
    }
 printf("\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) {
                res2[i][j] = 0;
                for (k = 0; k < 2; k++) {
                    res2[i][j] += a[i][k] * z[k][j];
                }
            }
        }
 printf("Hadamard O/P (Stage-IV): \n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) 
                printf("%f\t", 0.707 * res2[i][j]);
                printf("\n");
        }

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) 
                pop2[i][j] = 0.707 * res2[i][j];
        }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 1; j++) {
            if (e[i][j] != b[i][j]) {
                ual = 0;}
            else{
                ual = 1;
                }
            
        }
    }

    if(ual == 1){
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tensor3[i*2 + j][0] = z[i][0] * pop2[j][0];
        }
    }

    for (int j = 0; j < 4; j++) {
        E[0][j] = 0;
        for (int k = 0; k < 4; k++) {
            E[0][j] +=  crot9[k][j] * tensor3[0][k];
        }
    }
    printf(" ");
    printf("\n");
    printf("CROT O/P (Stage-V): ");
    printf("\n");
    for (int j = 0; j < 4; j++){
    
        if(E[0][j] < 0){
           printf("-0.707i");
           printf("\n");
        }
        else{
           printf("%f\t",E[0][j]);
           printf("\n");
        }
    }
    

    }

    else{
        printf("\n");
        printf("Stage-V : No Tensor");
        printf("\n");
    }

    for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) {
                res3[i][j] = 0;
                for (k = 0; k < 2; k++) {
                    res3[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        printf("\n");
        printf("Hadamard O/P (Stage-VI): \n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) 
                printf("%f\t", 0.707 * res3[i][j]);
                printf("\n");
        }

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) 
                pop3[i][j] = 0.707 * res[i][j];
        }
             

        printf("\n");
        printf("Stage-VII : Swap(q0 and q2) : New Q0 Value = \n");
            for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) {
                printf("%f\t", 0.707 * res[i][j]);
                printf("\n");
        }
            }

        printf("Stage-VII : Swap(q0 and q2) : New Q2 Value = \n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1; j++) 
                printf("%f\t", 0.707 * res3[i][j]);
                printf("\n");

        }

         } 
}

    

        
       
  



