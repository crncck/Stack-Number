#include <stdio.h>
#include "numberType.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct stackNode mainStack;
struct stackNode helperStack;
struct stackNode* recovered_stack;
BizarreNumber_t newBizarre;
int root;
int countOpr;
int abundance;
struct stackNode* topPtr;
BizarreNumber_t recoverBizarre;


void push(struct stackNode** topPtr, BizarreNumber_t info){

    struct stackNode* StackNode = (struct stackNode*)malloc(sizeof(struct stackNode));
    if(StackNode == NULL){
        exit(0);
    }
    StackNode->data = info;
    StackNode->nextPtr = NULL;
    if(topPtr != NULL){
        StackNode->nextPtr = *topPtr;
    }
    *topPtr = StackNode;
}

BizarreNumber_t pop(struct stackNode** topPtr){

    if(*topPtr != NULL){
        struct stackNode* temp = *topPtr;
        BizarreNumber_t popped = temp->data;
        *topPtr = (*topPtr)->nextPtr;
        free(temp);
        return popped;
    }else
        printf("The stack is empty.\n");

}

int isEmpty(struct stackNode* topPtr){

    struct stackNode* temp = topPtr;
    int i = 0;
    while(temp != NULL){
        temp = temp->nextPtr;
        i++;
    }

    if(i == 0)
        return 1;
    else
        return 0;

}

void printStack(struct stackNode* topPtr){

    struct stackNode* current = topPtr;

        printf("TOP --> ");
        while (current->nextPtr != NULL){
            if(current->data.num == -1){
                printf("NULL --> ");
                current = current->nextPtr;
            }else{
                printf("%d --> ",current->data.num);
                current = current->nextPtr;
            }
        }

        if(current->nextPtr == NULL){
            if(current->data.num == -1)
                printf("NULL --> ");
            else
                printf("%d --> ",current->data.num);
        }


    printf("BOTTOM");

}

void printStackDetailed(struct stackNode* topPtr){

    struct stackNode* current = topPtr;
    if(current->nextPtr != NULL){
        printf("\n  **TOP**\t\n");
        do{
            printf("%3d, ",current->data.num);
            printf(" %d,",current->data.nrOfOpr);
            printf(" %c%c\n",current->data.type[0], current->data.type[1]);
            current = current->nextPtr;
        }
        while (current->nextPtr!= NULL);
    }

    if(current->nextPtr == NULL){
            printf("%d, ",current->data.num);
            printf(" %d,",current->data.nrOfOpr);
            printf(" %c%c\n",current->data.type[0], current->data.type[1]);
    }

    printf("**BOTTOM**\n");



}


struct stackNode* reverseStack(struct stackNode* currentPtr){

    struct stackNode* temp;
    int flag = 1;


    while(currentPtr){

        struct stackNode* next = currentPtr->nextPtr;
        currentPtr->nextPtr = temp;
        temp = currentPtr;
        currentPtr = next;

        if(flag == 1){
            temp->nextPtr = NULL;
            flag = 0;
        }

    }

    return temp;


}

struct stackNode* recoverCipher(struct stackNode* mainStack, struct stackNode* helperStack){

    struct stackNode* recovered_stack = topPtr;


    char typeNumber;
    char a, b;


        while (mainStack->nextPtr!= NULL){

                a = mainStack->data.type[0];
                b = helperStack->data.type[0];
                typeNumber = a;
                if(a == ' ')
                    typeNumber = b;


                switch(typeNumber){
                case 'A':

                    //the number is abundant
                    //add the abundance to number - abundance and get the original value
                    recoverBizarre.num = mainStack->data.num + helperStack->data.num;

                    recoverBizarre.nrOfOpr = 0;
                    recoverBizarre.type[0] = 'A';
                    recoverBizarre.type[1] = 'B';
                    push(&recovered_stack, recoverBizarre);
                    break;

                case 'S':

                    //the number is perfect square
                    //get the root from main stack and multiply with nrOfOpr times itself
                    recoverBizarre.num = mainStack->data.num;
                    recoverBizarre.nrOfOpr = mainStack->data.nrOfOpr;
                    recoverBizarre.type[0] = 'S';
                    recoverBizarre.type[1] = 'Q';

                    for(int i = 0; i < recoverBizarre.nrOfOpr; i++){
                        int temp;
                        temp = recoverBizarre.num;
                        temp = temp * temp;
                        recoverBizarre.num = temp;
                    }

                    push(&recovered_stack, recoverBizarre);

                    break;

                case 'D':

                    //the number is deficient
                    //get the number in helper stack
                    recoverBizarre.num = helperStack->data.num;
                    recoverBizarre.nrOfOpr = 0;
                    recoverBizarre.type[0] = 'D';
                    recoverBizarre.type[1] = 'F';
                    push(&recovered_stack, recoverBizarre);
                    break;

                case 'P':

                    typeNumber = mainStack->data.type[1];

                    switch(typeNumber){
                    case 'R':

                        //the number is prime
                        //take the square root of the number
                        recoverBizarre.num = sqrt(mainStack->data.num);
                        recoverBizarre.nrOfOpr = 0;
                        recoverBizarre.type[0] = 'P';
                        recoverBizarre.type[1] = 'R';
                        push(&recovered_stack, recoverBizarre);
                        break;

                    case 'F':

                        //the number is perfect
                        //get the original value from main stack
                        recoverBizarre.num = mainStack->data.num;
                        recoverBizarre.nrOfOpr = 0;
                        recoverBizarre.type[0] = 'P';
                        recoverBizarre.type[1] = 'F';
                        push(&recovered_stack, recoverBizarre);
                        break;

                    }
                }

                mainStack = mainStack->nextPtr;
                helperStack = helperStack->nextPtr;

                }

                if(mainStack->nextPtr == NULL){

                    a = mainStack->data.type[0];
                    b = helperStack->data.type[0];
                    typeNumber = a;
                    if(a == ' ')
                        typeNumber = b;

                switch(typeNumber){
                case 'A':

                    //the number is abundant
                    //add the abundance to number - abundance and get the original value
                    recoverBizarre.num = mainStack->data.num + helperStack->data.num;

                    recoverBizarre.nrOfOpr = 0;
                    recoverBizarre.type[0] = 'A';
                    recoverBizarre.type[1] = 'B';
                    push(&recovered_stack, recoverBizarre);
                    break;

                case 'S':

                    //the number is perfect square
                    //get the root from main stack and multiply with nrOfOpr times itself
                    recoverBizarre.num = mainStack->data.num;
                    recoverBizarre.nrOfOpr = mainStack->data.nrOfOpr;
                    recoverBizarre.type[0] = 'S';
                    recoverBizarre.type[1] = 'Q';

                    for(int i = 0; i < recoverBizarre.nrOfOpr; i++){
                        int temp;
                        temp = recoverBizarre.num;
                        temp = temp * temp;
                        recoverBizarre.num = temp;
                    }

                    push(&recovered_stack, recoverBizarre);

                    break;

                case 'D':

                    //the number is deficient
                    //get the number in helper stack
                    recoverBizarre.num = helperStack->data.num;
                    recoverBizarre.nrOfOpr = 0;
                    recoverBizarre.type[0] = 'D';
                    recoverBizarre.type[1] = 'F';
                    push(&recovered_stack, recoverBizarre);
                    break;

                case 'P':

                    typeNumber = mainStack->data.type[1];

                    switch(typeNumber){
                    case 'R':

                        //the number is prime
                        //take the square root of the number
                        recoverBizarre.num = sqrt(mainStack->data.num);
                        recoverBizarre.nrOfOpr = 0;
                        recoverBizarre.type[0] = 'P';
                        recoverBizarre.type[1] = 'R';
                        push(&recovered_stack, recoverBizarre);
                        break;

                    case 'F':

                        //the number is perfect
                        //get the original value from main stack
                        recoverBizarre.num = mainStack->data.num;
                        recoverBizarre.nrOfOpr = 0;
                        recoverBizarre.type[0] = 'P';
                        recoverBizarre.type[1] = 'F';
                        push(&recovered_stack, recoverBizarre);
                        break;

                    }

                }

                }

                return reverseStack(recovered_stack);
}

int isAbundantNumber(int num){



    int i, j = 0;

    for(i = 1; i < num; ++i){

        if(num % i == 0)
            j = j + i;
    }

    abundance = j - num;

    if(abundance > 0){
        //Abundant number
        return 0;
    }
    else if(abundance == 0)
        //Perfect number
        return 1;
    else
        //Deficient number
        return 2;

}


int isPrime(int num){

    int i, flag = 0;

    for(i = 2; i <= num / 2; ++i){

        if(num % i == 0){

            flag = 1;
            break;
        }
    }

    if(num == 2)
        //prime
        return 1;
    else{
        //prime
        if(flag == 0)
            return 1;
        else
            //not prime
            return 0;
    }
}

int isPerfectSquare(int num){

    int a;
    float b;
    int flag = 1;
    countOpr = 0;

    b = sqrt((double)num);
    a = b;
    if(a == b)
      countOpr++;
    while(flag == 1){

      b = sqrt((double)a);
      a = b;
      if(a == b){
        //perfect square
        countOpr++;
        flag = 1;
        root = a;
        return 1;
      }else{
        //not perfect square
        flag = 0;
        return 0;
      }

    }

}
