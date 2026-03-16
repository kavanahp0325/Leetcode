typedef struct {
    int s[30001];
    int idx;
    int min;
} MinStack;

MinStack* minStackCreate() {
    MinStack *new = calloc(1, sizeof(MinStack));
    new->idx = 0;
    new->min = INT_MAX;
    return new;
}

void minStackPush(MinStack* obj, int val) {
    if (val <= obj->min) {
        obj->s[obj->idx++] = obj->min;
        obj->min = val;
    }
    obj->s[obj->idx++] = val;
}

void minStackPop(MinStack* obj) {
    if (obj->s[--obj->idx] == obj->min)
        obj->min = obj->s[--obj->idx];
}

int minStackTop(MinStack* obj) {
    return obj->s[obj->idx - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min;     
}

void minStackFree(MinStack* obj) {
    free(obj); 
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/