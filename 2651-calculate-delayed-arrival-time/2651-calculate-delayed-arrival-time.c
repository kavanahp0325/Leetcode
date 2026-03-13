int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
     int c=arrivalTime+delayedTime;
    if(c>24){
        return c=c-24;
    }
    if(arrivalTime+delayedTime==24){
        return 0;
    }
    else{
        return arrivalTime+delayedTime;
    }
}