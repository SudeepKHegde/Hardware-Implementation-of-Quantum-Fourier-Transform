/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>

int main() {
    {
    	
    int i, j, k;
    int equal,qual,ual;
    float pop[2][1],C[4][1],D[4][1],E[4][1],pop2[2][1],pop3[2][1],temp[2][1];
    int b[2][1],z[2][1],m[2][1],res[10][10],res2[10][10],res3[10][10]; // (b=Q0),(Z=Q1),(M=Q2)
    int a[2][2] = {{1,1},{1,-1}}; // Hadamard Gate
    int e[2][1] = {{0},{1}}; // Qubit |1> State
    int crot9[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,100}}; // CROT P(Pi/2)
    int crot4[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,200}}; // CROT P(Pi/4)
    float tensor[4][1] = {{0},{0},{0},{0}};  // Tensor Product Matrices
    float tensor2[4][1] = {{0},{0},{0},{0}}; // Tensor Product Matrices
    float tensor3[4][1] = {{0},{0},{0},{0}};
        printf("QFT-Implementation : EC203,EC222\n");
        printf("Enter The Input Qubit (Q0):\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1 ; j++) {
                scanf("%d", & b[i][j]); // Scan User Input for Q0
            }
        }
        printf("Enter The Input Qubit (Q1):\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1 ; j++) {
                scanf("%d", & z[i][j]); // Scan User Input for Q1
            }
        }
        printf("Enter The Input Qubit (Q2):\n");
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 1 ; j++) {
                scanf("%d", & m[i][j]); // Scan User Input for Q2
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
      
      return 0;
}