#include<iostream>
// #include<cmath.h>
using namespace std;

class calculate{
    public:
    int num1,num2;

    void getnum(){
        cout<<"enter the number you want to  perform operation on"<<endl;
         cout<<" the number is "<<"   ";
         cin>>num1;
         cout<<" the second number is "<<"  ";
         cin>>num2;
    }
      void perform(){
        char operation;
        cout<<endl<<" select the operation you want tp perform '+','-','*','/'  ";
        cin>>operation;
        switch (operation)
        {
        case '+':
        cout<<num1+num2;
            break;
        case '-':
        cout<<num1-num2;
            break;
        case '/':
        cout<<num1/num2;
            break;
        case '*':
        cout<<num1*num2;
            break;
    
        
       
        }
        
        
      }
};
 

  int main(){
    calculate c;
    c.getnum();
    c.perform();
    return 0;
  }