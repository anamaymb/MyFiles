#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float weights[10][100],weights_prev[10][100];
float output[10],expectedOp[10];
float input[10][100]={{0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //1                                    2
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //2
                      0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 ,       //3
                      0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //4
                      0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //5
                      0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 ,       //6
                      0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 ,       //7
                      0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 ,       //8
                      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,       //9
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },      //10

                     {0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //1                                     1
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //2
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //3
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //4
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //5
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //6
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //7
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //8
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //9
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 },      //10

                     {0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //1                                      3
                      0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 ,       //2
                      0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //3
                      0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 ,       //4
                      0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 ,       //5
                      0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 ,       //6
                      0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //7
                      0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //8
                      0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 ,       //9
                      0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 },

                     {0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //1                                    4
                      0 , 0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 ,       //2
                      0 , 0 , 0 , 0 , 1 , 0 , 1 , 0 , 0 , 0 ,       //3
                      0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 ,       //4
                      0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //5
                      0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //6
                      0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 ,       //7
                      0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //8
                      0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //9
                      0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 },      //10

                     {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //1                                     5
                      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,       //2
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //3
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //4
                      0 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //5
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //6
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //7
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //8
                      0 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //9
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },      //10

                     {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //1                                     6
                      0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //2
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //3
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //4
                      0 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //5
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //6
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //7
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //8
                      0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //9
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },      //10

                     {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //1                                     5
                      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 0 ,       //2
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 ,       //3
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //4
                      0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //5
                      0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 ,       //6
                      0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 ,       //7
                      0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 ,       //8
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //9
                      0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },      //10      //10

                     {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //1                                     0
                      0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //2
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //3
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //4
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //5
                      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,       //6
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //7
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //8
                      0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //9
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },      //10

                     {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //1                                     0
                      0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //2
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //3
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //4
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //5
                      0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,       //6
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //7
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //8
                      0 , 0 , 1 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //9
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },      //10

                     {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //1                                     0
                      0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //2
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //3
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //4
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //5
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //6
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //7
                      0 , 0 , 1 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ,       //8
                      0 , 0 , 0 , 1 , 1 , 1 , 1 , 0 , 0 , 0 ,       //9
                      0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 },      //10
                      };

float calculateOp(int j,float h,int nthWeight, int nthRow)
{
    float op=0;
    for (int k=0;k<100;k++)
    {
        op=op+input[nthRow][k]*(weights[j][k]+h*(k==nthWeight && j==nthRow));
    }
    
    return op;
}


float sumOfSquares(int nthWeight, float offset, int nthRow)
{
    float sum=0;
    for(int i=0;i<10;i++)
    {
        sum=sum+(expectedOp[i]-calculateOp(i,offset,nthWeight,nthRow))*(expectedOp[i]-calculateOp(i,offset,nthWeight,nthRow));
    }
    return sum;
}


float calculateOpPrev(int j,float h,int nthWeight,int nthRow)
{
    float op=0;
    for (int k=0;k<100;k++)
    {
        op=op+input[nthRow][k]*(weights_prev[j][k]+h*(k==nthWeight && j==nthRow));
    }

    return op;
}


float sumOfPrevSquares(int nthWeight, float h, int nthRow)
{
    float sum=0;
    for(int i=0;i<10;i++)
    {
        sum=sum+(expectedOp[i]-calculateOpPrev(i,h,nthWeight,nthRow))*(expectedOp[i]-calculateOpPrev(i,h,nthWeight,nthRow));
    }
    return sum;
}



int main()
{

for(int number=0; number<9;number++)
{
    for(int i=0;i<10;i++)
    {
        output[i]=0;expectedOp[i]=0;
        if(i==number)
            expectedOp[i]=11;
        
            
    }
    for(int j=0;j<100;j++)
    {
        weights[number][j]=0;weights_prev[number][j]=0;
    }

    // for(int j=0;j<10;j++)
    // {
    //     for (int i=0;i<100;i++)
    //     {
    //         output[1]=output[1]+input[i]*weights[1][i];
    //     }
    //     printf("Sum of %d : %f \n",j,output[j]);
    // }
    // printf("Sum %f \n",a);
    // for(int i=0;i<10;i++)
    // {
    //     output[i]=1/(1+exp(-output[i]));
    //     printf("a[%d] : %f & ",i,output[i]);
    //     printf("expectedOp[%d] : %f \n",i,expectedOp[i]);
    // }
    
    float kp=0.002, h=0.01;
    for (int count=0;count<80;count++)
    {
            for(int i=0;i<100;i++)
            {

                if(sumOfPrevSquares(i,0,number)>sumOfPrevSquares(i,h,number))
                {
                    weights[number][i]=weights[number][i]+kp*abs(sumOfPrevSquares(0,0,number));
                }
                else if(sumOfPrevSquares(i,0,number)>sumOfPrevSquares(i,-h,number))
                {
                    weights[number][i]=weights[number][i]-kp*abs(sumOfPrevSquares(0,0,number));
                }
                

            }
        
        // printf("\n");
        
            for(int i=0;i<100;i++)
                weights_prev[number][i]=weights[number][i];
        
        // printf("%f \n",sumOfSquares(0,0,number));
    }


    for(int i=0;i<100;i++)
    {
        if(i%10==0)
        printf("\n\n");
        
        if(weights[number][i]!=0)
        printf("%f ",weights[number][i]);
        else
        printf("         ");
    }
printf("\n");


}

    return 0;
}