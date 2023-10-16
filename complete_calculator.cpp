//HOW THIS CALCULATOR WORKS//
//it takes input into 2 arrays one float array and one charecter array//
//then we search the char array according to the precision order//
//if we find any operator at jth position in char array then we do the operation defined
//by the char on the integers at j and j+1 th int array position
//then store the result in jth position of int array//
//after that we perform a shifting operation to j+1th element of int array to the end//
//we also perform that shifting on the char array from j to last char element//

//EXTRA POINT: IF ANY OPERATOR IS FOUND BY SEARCHING THE CHAR ARRAY THEN AFTER THE CALCULATION AND 
//SHIFTING PROCESS WE START SEARCHING THE CHAR ARRAY FROM BEGGINING THIS IS DONE BECAUSE SOME ELEMENT
//MIGHT NOW HAVE BEEN SHIFTED TO THE FIRST POSITION IN THE CHAR ARRAY//
#include <iostream>
#include <cmath>
using namespace std;
float calculate(float a,float b,char c)
{
    if(c=='^')return pow(a,b);
    if(c=='/')return a/b;
    else if(c=='*')return a*b;
    else if(c=='+')return a+b;
    else if(c=='-')return a-b;
    return 0;
}
void shift(auto* a,auto* b)
{
    for(;a<b;a++)
    {
        *a=*(a+1);
    }
}
// void print(auto* a,auto* b)
// {
//     for(;a<b;a++)
//     {
//         cout<<*a;
//         //cout<<operators[j];
//     }
//     cout<<endl;
// }
int main()
{
    cout<<endl<<"This is a calculator which follows the precedence order ^,/,*,+,- while calculation"<<endl;
    cout<<"It can take input upto a maximum of 100 operators and 101 operands"<<endl;
    cout<<"Sample input : 2^3*5/5-1= "<<endl;
    cout<<"The \'=\' sign is mandatory after writing the required expression and then press enter"<<endl;
    while(1)
    {
        cout<<"It is an infinite loop so to exit press ctrl+c to escape"<<endl;
        float operant[101]={0};
        char operators[100]={'\0'};
        cout<<endl<<"enter the expression below"<<endl;
        int j{};
        while(1)
        {
            char c;
            float temp;
            cin>>temp;
            cin>>c;
            //cout<<c;
            operant[j]=temp;
            if(c=='=')break;
            operators[j]=c;
            j++;
        }
        // for(int j{};j<100;j++)
        // {
        //     cout<<operant[j];
        //     cout<<operators[j];
        // }
        //cout<<endl;

        char oper[5]={'^','/','*','+','-'};
        // print(&operant[0],&operant[101]);
        // print(&operators[0],&operators[100]);
        for(int i{};i<5;i++)
        {
            int j{};
            int count{};
            while(operators[j]!='\0')
            {
                
                //cout<<"in while";
                if(operators[j]==oper[i])
                {
                    count++;
                    // cout<<operant[j]<<oper[i]<<operant[j+1]<<endl;
                    operant[j]=calculate(operant[j],operant[j+1],oper[i]);
                    shift(&operant[j+1],&operant[101]);
                    shift(&operators[j],&operators[100]);
                    // print(&operant[0],&operant[101]);
                    // print(&operators[0],&operators[100]);
                    //cout<<endl<<j<<endl;
                }
                if(count!=0){j=-1;count=0;}
                j++;
            }
        }
        cout<<endl<<"Answer = "<<operant[0]<<endl<<endl;
    }

    return 0;    
}
