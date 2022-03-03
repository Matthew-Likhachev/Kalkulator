#include "iostream"
#include "conio.h"
#include "clocale"
#include "cstdlib"
#include "tchar.h"
#include "string.h"
#include "windows.h"
#include "class_calculator.h"

using namespace std;

//преобразование стрки в символы и удаление пробелов в строке
bool Convert_String_To_Char(  char *arr , int length, int  &num_bracket);
//метод запуска калькулятора и возвращение результата
void Result_Kalk();

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Result_Kalk();
    cout<<endl;
    return 0;
}

//преобразование стрки в символы и удаление пробелов в строке
bool Convert_String_To_Char(char *arr, int length, int &num_bracket )
{

    int check_bracket;
    for(int i=0; i<length; i++)
    {
        if(arr[i]=='('){
            num_bracket++;
            check_bracket++;
        }else
        if(arr[i]==')'){
            check_bracket--;
        }else

        if(arr[i]==' ')
        {
            for(int j = i; j<length;j++)
            {
                arr[j]=arr[j+1];
            }
            // чтобы не пропустить появторяющийся пробел
            i--;
        }


    }
    if(check_bracket!=0){
        cout<<"Ошибка, нарушение последовательности действий"<<endl;
        arr={0};
        return false;
    }
    return true;
}

//метод запуска калькулятора и возвращение результата
void Result_Kalk(){

    cout<<"Калькулятор \n"<<"Введите выражение: "<<endl;
    char oneChar;
    char  char_arr[20000] = {' '};
    int i = 0;
    //get array
    while(cin.get(oneChar))
    {
        if (oneChar == '\n') break;
        char_arr[i]=oneChar;
        i++;
        if(i>19999){
            cout<<"Ошибка, слишком большое выражение"<<endl;
        }
    }

    int num_bracket=0;
    if(Convert_String_To_Char(char_arr, strlen(char_arr), num_bracket ))
    {
        Class_Calculator calc;
        calc.Set_Expression(char_arr, num_bracket);
    }
}


