typedef struct {
    int head, size; 
    //usigned capacity;
    int* stack;
} MyStack;

typedef struct {
    MyStack* stack_1;
    MyStack* stack_2;
} MyQueue;

#define MAX_STACK_SIZE 100

bool myQueueEmpty(MyQueue* obj);

MyQueue* myQueueCreate() {
    MyQueue* Stack_Q = (MyQueue*)malloc(sizeof(MyQueue));
    Stack_Q->stack_1 = (MyStack*)malloc(sizeof(MyStack));
    Stack_Q->stack_2 = (MyStack*)malloc(sizeof(MyStack));
    Stack_Q->stack_1->head = -1;
    Stack_Q->stack_1->size = 0;
    Stack_Q->stack_1->stack = (int*)malloc(sizeof(int)*MAX_STACK_SIZE);
    Stack_Q->stack_2->head = -1;
    Stack_Q->stack_2->size = 0;
    Stack_Q->stack_2->stack = (int*)malloc(sizeof(int)*MAX_STACK_SIZE);
    return Stack_Q;
}

void push_stack_122(MyQueue* obj){
    int val = obj->stack_1->stack[obj->stack_1->head--];
    obj->stack_1->size --;
    obj->stack_2->stack[++obj->stack_2->head] = val;
    obj->stack_2->size ++;
}

void push_stack_221(MyQueue* obj){
    int val = obj->stack_2->stack[obj->stack_2->head--];
    obj->stack_2->size --;
    obj->stack_1->stack[++obj->stack_1->head] = val;
    obj->stack_1->size ++;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->stack_1->size > MAX_STACK_SIZE){
        return;
    }
    if (obj->stack_1->size == 0){
        obj->stack_1->stack[++obj->stack_1->head] = x;
        obj->stack_1->size++;
        return;
    }
    
    int i,j;
    while(obj->stack_1->size != 0){
        push_stack_122(obj);
    }
    
    obj->stack_1->stack[++obj->stack_1->head] = x;
    obj->stack_1->size ++;
    
    while(obj->stack_2->size != 0){
        push_stack_221(obj);
    }
}

int myQueuePop(MyQueue* obj) {
    int rt_val = obj->stack_1->stack[obj->stack_1->head--];
    obj->stack_1->size--;
    return rt_val;
}

int myQueuePeek(MyQueue* obj) {
    return obj->stack_1->stack[obj->stack_1->head];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->stack_1->size == 0);
}

void myQueueFree(MyQueue* obj) {
    if(myQueueEmpty(obj)){
        return;
    }
    obj->stack_1->head = -1;
    obj->stack_1->size = 0;
    obj->stack_2->head = -1;
    obj->stack_2->size = 0;
    
    free(obj->stack_1->stack);
    free(obj->stack_2->stack);
    free(obj->stack_1);
    free(obj->stack_2);
    free(obj);
}