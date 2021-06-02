#ifndef NUMBERTYPE_H_INCLUDED
#define NUMBERTYPE_H_INCLUDED

typedef struct {
    char type[3];
    int nrOfOpr;
    int num;
} BizarreNumber_t;

struct stackNode {
    BizarreNumber_t data;
    struct stackNode *nextPtr;
};

extern int root;
extern int countOpr;
extern int abundance;
extern struct stackNode mainStack;
extern struct stackNode helperStack;
extern BizarreNumber_t newBizarre;
extern BizarreNumber_t recoverBizarre;
extern struct stackNode* topPtr;
extern struct stackNode* recovered_stack;
extern int isEmpty(struct stackNode* topPtr);
extern BizarreNumber_t pop(struct stackNode** topPtr);
extern void push(struct stackNode** topPtr, BizarreNumber_t info);
extern void printStack(struct stackNode* topPtr);
extern void printStackDetailed(struct stackNode* topPtr);
extern struct stackNode* reverseStack(struct stackNode* currentPtr);
extern struct stackNode* recoverCipher(struct stackNode* mainStack, struct stackNode* helperStack);
extern int isAbundantNumber(int num);
extern int isPrime(int num);
extern int isPerfectSquare(int num);

#endif // NUMBERTYPE_H_INCLUDED
