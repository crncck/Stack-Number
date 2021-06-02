#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "numberType.h"
#include <conio.h>

int main(){

    struct stackNode mainStack;
    struct stackNode helperStack;
    BizarreNumber_t newBizarre;

    int number;
    int flag = 1;
    int type_number;


    mainStack.nextPtr = NULL;
    helperStack.nextPtr = NULL;

    for(; flag == 1;){

        printf("Enter an integer number to push(Press -1 to end):\n");
        scanf("%d", &number);

        if(number == -1){
            flag = 0;
            system("cls");
            break;
        }

        type_number = isPrime(number);

        switch(type_number){
        case 1:
        {

            //the number is prime

            //push nothing to helper stack
            newBizarre.type[0] = ' ';
            newBizarre.num = -1;
            newBizarre.nrOfOpr = 0;
            push(&helperStack.nextPtr, newBizarre);

            //push the square of the prime number to main stack
            newBizarre.type[0] = 'P';
            newBizarre.type[1] = 'R';
            newBizarre.nrOfOpr = 0;
            newBizarre.num = number * number;
            push(&mainStack.nextPtr, newBizarre);

            break;
        }
        case 0:
        {


            //the number is not prime

            type_number = isPerfectSquare(number);


            switch(type_number){
            case 1:
            {

                //the number is perfect square

                //push nothing to helper stack
                newBizarre.type[0] = ' ';
                newBizarre.num = -1;
                newBizarre.nrOfOpr = 0;
                push(&helperStack.nextPtr, newBizarre);

                //last num to main stack
                newBizarre.type[0] = 'S';
                newBizarre.type[1] = 'Q';
                newBizarre.num = root;
                newBizarre.nrOfOpr = countOpr;
                push(&mainStack.nextPtr, newBizarre);
                break;
            }
            case 0:
            {

                //the number is not perfect square
                type_number = isAbundantNumber(number);


                switch(type_number){
                case 0:
                {
                    //the number is abundant

                    //push abundance to helper stack
                    newBizarre.type[0] = 'A';
                    newBizarre.type[1] = 'B';
                    newBizarre.nrOfOpr = 0;
                    newBizarre.num = abundance;
                    push(&helperStack.nextPtr, newBizarre);

                    //push the number - abundance to main stack
                     newBizarre.type[0] = 'A';
                    newBizarre.type[1] = 'B';
                    newBizarre.nrOfOpr = 0;
                    newBizarre.num = number - abundance;
                    push(&mainStack.nextPtr, newBizarre);


                    break;
                }
                case 1:
                {


                    //the number is perfect number

                    //push nothing to helper stack
                    newBizarre.type[0] = ' ';
                    newBizarre.nrOfOpr = 0;
                    newBizarre.num =  -1;
                    push(&helperStack.nextPtr, newBizarre);

                    //push the number to the main stack
                    newBizarre.type[0] = 'P';
                    newBizarre.type[1] = 'F';
                    newBizarre.nrOfOpr = 0;
                    newBizarre.num = number;
                    push(&mainStack.nextPtr, newBizarre);
                    break;
                }
                case 2:
                {


                    //the number is deficient number

                    //push nothing to the stack
                    newBizarre.type[0] = ' ';
                    newBizarre.nrOfOpr = 0;
                    newBizarre.num = -1;
                    push(&mainStack.nextPtr, newBizarre);


                    //push the number to the helper stack
                    newBizarre.type[0] = 'D';
                    newBizarre.type[1] = 'F';
                    newBizarre.num = number;
                    push(&helperStack.nextPtr, newBizarre);

                    break;
                }
                }
            }
            }
            break;
        }
        }

        /*
        if(!((number = getchar()) != EOF)){
                flag = 0;
                system("cls");
                break;
            }

        */
        }


        //A few codes have been tried to catch EOF but failed every time to clear the screen after it. Then it was decided to end the program with -1
        /*while(flag == 1){
            if(!((number = getchar()) != EOF)){
                flag = 0;
                system("cls");
                break;
            }
        }

        */



        printf("The main stack is:\n");
        printStack(mainStack.nextPtr);

        printf("\n\nThe helper stack is:\n");
        printStack(helperStack.nextPtr);

        printf("\n\nRecovered stack is:");
        printStackDetailed(recoverCipher(&mainStack, &helperStack));


    return 0;


}
