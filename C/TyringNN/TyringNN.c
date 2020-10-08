#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float weights[10][100],weights_prev[10][100];
float output[10],expectedOp[10];
float input[100]={0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,       //1
                  0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 ,       //2
                  0 , 0 , 0 , 1 , 0 , 0 , 1 , 0 , 0 , 0 ,       //3
                  0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //4
                  0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ,       //5
                  0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 ,       //6
                  0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 ,       //7
                  0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 ,       //8
                  0 , 0 , 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 ,       //9
                  0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 };       //10

float calculateOp(int j,float h,int nthWeight, int nthRow)
{
    float op=0;
    for (int k=0;k<100;k++)
    {
        op=op+input[k]*(weights[j][k]+h*(k==nthWeight && j==nthRow));
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
    // printf("nthWeight %d, j %d \n",nthWeight,j);
    float op=0;
    for (int k=0;k<100;k++)
    {
        op=op+input[k]*(weights_prev[j][k]+h*(k==nthWeight && j==nthRow));
        if(k==nthWeight && j==nthRow)
        {
            // printf("CalculatePrevop %f , nthWeight %d , nthRow %d \n",weights_prev[j][k]+h,k,nthRow);
        }
    }
    // printf("Hi\n");
    
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

    for(int i=0;i<10;i++)
    {
        output[i]=0;expectedOp[i]=0;
        if(i==0)
            expectedOp[i]=16;
        for(int j=0;j<100;j++)
        {
            weights[i][j]=0;weights_prev[i][j]=0;
        }
            
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
    
    float kp=0.005, h=0.01;
    for (int count=0;count<80;count++)
    {
        for(int j=0;j<1;j++)
        {
            for(int i=0;i<100;i++)
            {
                // printf("%d : sumOfSqaures(i,0) %f  sumOfSqaures(i,h) : %f  weights : %f  weights+h %f \n",i,sumOfPrevSquares(i,0,j),sumOfPrevSquares(i,h,j),weights[j][i],weights[j][i]+h);
                if(sumOfPrevSquares(i,0,j)>sumOfPrevSquares(i,h,j))
                {
                    weights[j][i]=weights[j][i]+kp*abs(sumOfPrevSquares(0,0,j));
                    // weights[j][i]=weights[j][i]+h;
                    printf("%f \n",sumOfSquares(i,0,j));
                    
                }
                else if(sumOfPrevSquares(i,0,j)>sumOfPrevSquares(i,-h,j))
                {
                    weights[j][i]=weights[j][i]-kp*abs(sumOfPrevSquares(0,0,j));
                    printf("Hi %f \n",sumOfSquares(i,0,j));
                }
                

            }
        }
        printf("\n");
        for(int j=0;j<1;j++)
        {
            for(int i=0;i<100;i++)
                weights_prev[j][i]=weights[j][i];
        }
        printf("%f \n",sumOfSquares(0,0,0));
    }


    for(int i=0;i<100;i++)
    {
        if(i%10==0)
        printf("\n\n");
        
        if(weights[0][i]!=0)
        printf("%f ",weights[0][i]);
        else
        printf("         ");
    }
printf("\n");


    

    return 0;
}