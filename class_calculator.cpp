#include "class_calculator.h"
#include "iostream"
#include "conio.h"
#include "clocale"
#include "cstdlib"
#include "tchar.h"
#include "string.h"
#include "windows.h"
#include <stack>


using namespace std;
stack <int> double_stack;  // создаем стек чисел
stack <char> char_stack;  // создаем стек операций и скобок
int Class_Calculator::Calculate(int x, char oper, int y)
{
    switch(oper)
        {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            default:
                return 0.0;
        }
}
//useless
void Class_Calculator::Set_Expression(char arr [], int num_bracket)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Cut_Brackets(arr);

}


void Class_Calculator:: Cut_Brackets(char arr[])
{
    int number=0;
    int i = 0;
    while (i != strlen(arr))
    {
      //если попалась цифра 0-9
        if(arr[i]=='1' || arr[i]=='2' || arr[i]=='3' || arr[i]=='4' || arr[i]=='5' || arr[i]=='6' || arr[i]=='7' || arr[i]=='8' || arr[i]=='9' || arr[i]=='0' )
        {
            number = arr[i] - '0';
            //поиск чисел
            while (arr[i+1]=='1' || arr[i+1]=='2' || arr[i+1]=='3' || arr[i + 1]=='4' || arr[i + 1]=='5' || arr[i + 1]=='6' || arr[i + 1]=='7' || arr[i + 1]=='8' || arr[i + 1]=='9' || arr[i + 1]=='0')
            {
                i++;
                //увеличиваем разряд числа и прибавляем остаток
                //перевод к int дает номер числа в ASCII где '0'=48
                number=number*10 + (arr[i] - '0');
            }
            double_stack.push(number);// добавляем введенное число в стек
        }

        if(arr[i]=='(' || arr[i]==')' || arr[i]=='+' || arr[i]=='-' ||arr[i]=='*' || arr[i]=='/' )
            {
                switch(arr[i])
                {
                case('*'):
                    while(true)
                    {
                        //если стек пустой - добавляем
                        if(char_stack.empty())
                        {
                            char_stack.push(arr[i]);// добавляем введенный символ в стек
                            break;
                        }
                        //если знаки приоритета меньше - то добавляем в стек
                        if(char_stack.top()=='+' || char_stack.top()=='-' || char_stack.top()=='(')
                        {
                            char_stack.push(arr[i]);// добавляем введенный символ в стек
                            break;
                        }else                       //знаки приоритета равные
                        if(char_stack.top()=='/' || char_stack.top()=='*')
                        {
                            number=double_stack.top();
                            double_stack.pop();
                            number=Calculate(double_stack.top(),arr[i],number);
                            double_stack.pop();
                            double_stack.push(number);// добавляем полученное число в стек
                        }
                     }
                    break;
                case('/'):
                    while(true)
                    {
                        //если стек пустой - добавляем
                        if(char_stack.empty())
                        {
                            char_stack.push(arr[i]);// добавляем введенный символ в стек
                            break;
                        }else
                        //если знаки приоритета меньше - то добавляем в стек
                        if(char_stack.top()=='+' || char_stack.top()=='-' || char_stack.top()=='(')
                        {
                            char_stack.push(arr[i]);// добавляем введенный символ в стек
                            break;
                        } else                       //знаки приоритета равные
                        if(char_stack.top()=='/' || char_stack.top()=='*')
                        {
                            number=double_stack.top();
                            double_stack.pop();
                            number=Calculate(double_stack.top(),arr[i],number);
                            double_stack.pop();
                            double_stack.push(number);// добавляем полученное число в стек
                        }
                     }
                    break;
                case('-'):
                    while(true)
                    {
                        //если стек пустой - добавляем
                        if(char_stack.empty() || char_stack.top()=='(' )
                        {
                            char_stack.push(arr[i]);// добавляем введенный символ в стек
                            break;
                        }else
                        if(char_stack.top()=='+' || char_stack.top()=='-' )
                        {
                            number=double_stack.top();
                            double_stack.pop();
                            number=Calculate(double_stack.top(),arr[i],number);
                            char_stack.pop();
                            double_stack.pop();
                            double_stack.push(number);// добавляем полученное число в стек
                        }else
                        if(char_stack.top()=='/' || char_stack.top()=='*')
                        {
                            number=double_stack.top();
                            double_stack.pop();
                            number=Calculate(double_stack.top(),arr[i],number);
                            char_stack.pop();
                            double_stack.pop();
                            double_stack.push(number);// добавляем полученное число в стек
                        }
                    }

                    break;
                case('+'):
                    while(true)
                    {
                        //если стек пустой - добавляем
                        if(char_stack.empty() || char_stack.top()=='(' )
                        {
                            char_stack.push(arr[i]);// добавляем введенный символ в стек
                            break;
                        }else
                        if(char_stack.top()=='+' || char_stack.top()=='-' )
                        {
                            number=double_stack.top();
                            double_stack.pop();
                            number=Calculate(double_stack.top(),arr[i],number);
                            char_stack.pop();

                            double_stack.pop();
                            double_stack.push(number);// добавляем полученное число в стек
                        }else
                        if(char_stack.top()=='/' || char_stack.top()=='*')
                        {
                            number=double_stack.top();
                            double_stack.pop();
                            number=Calculate(double_stack.top(),arr[i],number);
                            char_stack.pop();
                            double_stack.pop();
                            double_stack.push(number);// добавляем полученное число в стек
                        }
                    }

                    break;
                case('('):
                    char_stack.push(arr[i]);// добавляем введенный символ в стек
                    break;
                case(')'):
                    while(char_stack.top()!='(')
                    {
                        number=double_stack.top();
                        double_stack.pop();
                        number=Calculate(double_stack.top(),char_stack.top(),number);
                        char_stack.pop();
                        double_stack.pop();
                        double_stack.push(number);// добавляем полученное число в стек
                    }
                    char_stack.pop();
                    break;
                }
            }
        i++;
    }

   while(!char_stack.empty())
   {
       number=double_stack.top();
       double_stack.pop();
       number=Calculate(double_stack.top(),char_stack.top(),number);
       char_stack.pop();
       double_stack.pop();
       double_stack.push(number);// добавляем полученное число в стек
   }
    cout<<"Ответ = "<<number<<endl;
}

