#include <iostream>
#include "array.h"
#include <string>

using namespace std;

struct Result{
    double result;
    bool error;
};

Result evaluate(string input)
{
  CircularArray<int> madre(input.length()*2); 
  CircularArray<int> stack1(input.length()*2);
  CircularArray<int> stack2(input.length()*2);
  
    // 1- descomponer el input y validar
  // 2- convertir de Infijo a Postfijo  Postfijo in Stack1
      for(const char &letra : input){
          if(int(letra) == 40) stack1.push_back(int(letra));
          else if (int(letra) >= 48 && int(letra) <= 57 ) madre.push_back(int(letra));
          else if (int(letra >= 42 && int(letra) < 48)) stack1.push_back(int(letra));
          else if(int(letra) == 41){
            while(stack1.f() != 40){
              cout<<(char)stack1.f()<<endl;
              madre.push_back(stack1.f());
              stack1.pop_front();
            }
            stack1.pop_front();
          }
      }
    string validacion;
    // 3- resolver la expresion
      auto a= madre.begin();
      while(a != madre.end()){
        validacion += *a;
        cout<<(char)*a;
        if (*a >= 48 && *a <= 57  ){
          stack2.push_back(*a);
        }
        if(*a >= 42 && *a <48){
          int  temp1 = char(stack2.f())-'0';
          stack2.pop_front();
          int  temp2 = char(stack2.f())-'0';
          stack2.pop_front();
          if(*a == 42){
            stack2.push_back(temp1 * temp2);
          }
          else if(*a == 43){
            stack2.push_back(temp1 + temp2);
          }
          else if(*a == 45){
            stack2.push_back(temp1 - temp2);
          }
          else if(*a == 47){
            stack2.push_back(temp1 / temp2);
          }
        }
        ++a;
      }
  Result rs;
    if (validacion == input){
      rs.error=true;
    }else{
        rs.error = false;    
    }
    //* Si no cumple la validacion retornar Result.error = true;
  
  rs.result = stack2.f();
  
    return rs;
}
