#ifndef CLASS_CALCULATOR_H
#define CLASS_CALCULATOR_H


class Class_Calculator
{
private:
    int Calculate(int x, char oper, int y);
public:
    void Set_Expression(char arr [],int num_bracket );
private: void Cut_Brackets(char arr[]);

};

#endif // CLASS_CALCULATOR_H
