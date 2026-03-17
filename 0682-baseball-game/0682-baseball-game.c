int calPoints(char ** operations, int operationsSize){
    
    int* arry = (int*) calloc(operationsSize,sizeof(int));
    int curr = 0;
    int sum = 0;
    
    for(int i = 0; i < operationsSize; ++i)
    {
        switch(*(*(operations+i)))
        {
            case 'C':
                *(arry + (--curr)) = 0;
                break;
            case 'D':
                *(arry + (curr++)) = *(arry + curr - 1) * 2;
                break;
            case '+':
                *(arry + (curr++)) = *(arry + curr - 1) + *(arry + curr - 2);
                break;
            default:
                *(arry + (curr++)) = atoi(*(operations+i));
                break;
        }
    }
    
    for(int i = 0; i < operationsSize; ++i)
    {
        sum += arry[i];
    }
    
    free(arry);
    return sum;
}