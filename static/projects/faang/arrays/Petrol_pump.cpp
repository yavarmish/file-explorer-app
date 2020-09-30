/*Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.*/

//logic
// we iterate while start!=end or cur_petrol is less than zero if start reaches end return start if cur petrol is less than  zero we 
//remove starting stations and increase the starting pointer if start reaches its initial position then ther is no configuration possible

/*
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
   //Your code here
   
   int s=0;int e=1;
   int cur=p[0].petrol-p[0].distance;
   while(s!=e||cur<0)
   {
       while(s!=e&&cur<0)
       {
           cur-=p[s].petrol-p[s].distance;
           s=(s+1)%n;
            if(s==0) return -1;   
       }
       cur+=p[e].petrol-p[e].distance;
       e=(e+1)%n;
   }
   return s;
}
