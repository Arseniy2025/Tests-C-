#include <iostream> 
using namespace std; 
 
int main() { 
    double x, y; 
    for(int i = 1; i<6; ++i) 
    { 
        switch(i) 
        { 
            case 1: 
                x = -1.5; y=0.1; 
                break; 
            case 2: 
                x = -2.5; y = 0; 
                break; 
            case 3: 
                x =-0.5; y=0.5; 
                break; 
            case 4: 
                x = -1.5; y=0.5; 
                break; 
            case 5: 
                x=0.5;  y = 1.1;
                break; 
            default: 
                cout<<"Некорректные значения"<<endl; 
                break; 
             
        } 
        x = x * x; 
        y = y * y; 
        double x0 = x, y0 = y; 
         
        if ((x+y<=1)&&(x>=0)||(y0>=-0.5*x0-1)&&(y0<=0.5*x0+1)&&(x0<0)) 
        cout << "Входит\n"; 
    else 
        cout<<"Не входит\n"; 
         
    } 
}

