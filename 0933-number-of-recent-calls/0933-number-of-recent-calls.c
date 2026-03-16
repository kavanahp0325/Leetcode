
typedef struct {
    int ulHeadPtr;
    int ulTailPtr;
    int recent_t[3002];
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* rcc_ptr = (RecentCounter*)malloc (sizeof(RecentCounter));
    rcc_ptr->ulHeadPtr = 0;
    rcc_ptr->ulTailPtr = 0;
    return rcc_ptr;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->recent_t[obj->ulHeadPtr] = t;
    obj->ulHeadPtr++;
    if(obj->ulHeadPtr == 3002){
        obj->ulHeadPtr = 0;
    }
    while(obj->recent_t[obj->ulTailPtr] < (t-3000)){
        obj->ulTailPtr++;
        if(obj->ulTailPtr == 3002){
            obj->ulTailPtr = 0;
        }
    }
    return ((obj->ulHeadPtr >= obj->ulTailPtr) ?  (obj->ulHeadPtr-obj->ulTailPtr) : (obj->ulHeadPtr-obj->ulTailPtr + 3002));
}

void recentCounterFree(RecentCounter* obj) {
   free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/