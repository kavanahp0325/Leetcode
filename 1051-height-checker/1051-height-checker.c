

int heightChecker(int* heights, int heightsSize){
int i,j,x,temp[heightsSize];
    for(i=0;i<heightsSize;i++)
    {
        temp[i]=heights[i];
        
    }
    for(i=0;i<heightsSize;i++)
    {
        j=i-1;
        x=heights[i];
        while(j>=0 && heights[j]>x)
        {
            heights[j+1]=heights[j];
            j--;
        }
        heights[j+1]=x;
    }
    int c=0;
    for(i=0;i<heightsSize;i++)
    {
        if(temp[i]!=heights[i])
            c++;
    }
    return c;
}