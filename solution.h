#include <iostream>
#include "array.h"
#include <cstring>

using namespace std;

struct Result{
    double result;
    bool error;
};


bool evaluate(string input)
{
  CircularArray<int> madre(input.length()*2); 
  CircularArray<int> stack1(input.length()*2);
  CircularArray<int> stack2(input.length()*2);
  
    // 1- descomponer el input y validar
  // 2- convertir de Infijo a Postfijo  Postfijo in Stack1
      for(const char &letra : input){
          if(int(letra) == 40) stack1.push_back(int(letra));
          else if (int(letra) >= 48 && int(letra) <= 57 ) madre.push_back(int(letra));
          else if (int(letra >= 42 && int(letra) <= 47)) stack1.push_back(int(letra));
          else if(int(letra) == 41){
            while(stack1.f() != 40){
              madre.push_back(stack1.f());
              stack1.pop_front();
            }
            stack1.pop_front();
          }
      }
    
    // 3- resolver la expresion
      

  
    //* Si no cumple la validacion retornar Result.error = true;

    return false;
}
