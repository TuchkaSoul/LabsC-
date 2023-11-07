// Laba7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <math.h>
#include <iostream>
    
double GetDoubleValue(const char* message1="", const char* message2 = "Вы вводите вещественное число...") {
    char text[255];
    double resalt=1;
    std::cout << message2 <<"\nВвод "<<message1<<":";
    fgets(text, sizeof(text), stdin);
    while (sscanf_s(text, "%lf", &resalt)!=1)
    {
        std::cout << "Error. Повторите попытку ввода.\n"<<message2<<"\nВвод:";
        fgets(text, sizeof(text), stdin);
    }
    std::cout << "Полученная переменная " << message1 << ":" << resalt << std::endl;
    return resalt;
}

double SubtractionFractions(double x1, double x2)
{
    double result = x1 - x2;
    return result;
}
float SubtractionFractions(float x1, float x2) 
{
    float result = x1 - x2;
    return result;
}
double SubtractionFractions(float x1, double x2)
{
    double result = x1 - x2;
    return result;
}
double SubtractionFractions(double x1, float x2)
{
    double result = x1 - x2;
    return result;
}
double SubtractionFractions(int num1, int demon1, int num2, int demon2)
{
    int numr = num1 * demon2 - num2 * demon1;
    int demonr = demon1 * demon2;
    double result = (double)numr / double(demonr);
    return result;
}
double SubtractionFractions(double num1, double demon1, double num2, double demon2)
{
    std::cout << "Входные данные будут округлены до целой части";

    double numr = trunc(num1) * trunc(demon2) - trunc(num2) * trunc(demon1);
    double demonr = trunc(demon1) * trunc(demon2);
    double result = numr / demonr;
    return result;
}
double SubtractionFractions(double num1, int demon1, double num2, int demon2)
{
    std::cout << "Входные данные будут округлены до целой части";

    double numr = trunc(num1) * trunc(demon2) - trunc(num2) * trunc(demon1);
    double demonr = trunc(demon1) * trunc(demon2);
    double result = numr / demonr;
    return result;
}
double SubtractionFractions(int num1, double demon1, int num2, double demon2)
{
    std::cout << "Входные данные будут округлены до целой части";

    double numr = trunc(num1) * trunc(demon2) - trunc(num2) * trunc(demon1);
    double demonr = trunc(demon1) * trunc(demon2);
    double result = numr / demonr;
    return result;
}
double SubtractionFractions(double num1, double demon1, double num2, int demon2)
{
    std::cout << "Входные данные будут округлены до целой части";

    double numr = trunc(num1) * trunc(demon2) - trunc(num2) * trunc(demon1);
    double demonr = trunc(demon1) * trunc(demon2);
    double result = numr / demonr;
    return result;
}
double SubtractionFractions(double num1, double demon1, int num2, double demon2)
{
    std::cout << "Входные данные будут округлены до целой части";

    double numr = trunc(num1) * trunc(demon2) - trunc(num2) * trunc(demon1);
    double demonr = trunc(demon1) * trunc(demon2);
    double result = numr / demonr;
    return result;
}
double SubtractionFractions(double num1, double demon1, int num2, int demon2)
{
    std::cout << "Входные данные будут округлены до целой части";

    double numr = trunc(num1) * trunc(demon2) - trunc(num2) * trunc(demon1);
    double demonr = trunc(demon1) * trunc(demon2);
    double result = numr / demonr;
    return result;
}
double SubtractionFractions(double num1, int demon1, double num2, double demon2)
{
    std::cout << "Входные данные будут округлены до целой части";

    double numr = trunc(num1) * trunc(demon2) - trunc(num2) * trunc(demon1);
    double demonr = trunc(demon1) * trunc(demon2);
    double result = numr / demonr;
    return result;
}
double SubtractionFractions(double num1, int demon1, double num2, int demon2)
{
    std::cout << "Входные данные будут округлены до целой части";

    double numr = trunc(num1) * trunc(demon2) - trunc(num2) * trunc(demon1);
    double demonr = trunc(demon1) * trunc(demon2);
    double result = numr / demonr;
    return result;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    std::cout << "Hello World!\n";
    double x1 = GetDoubleValue("x1");
    double x2 = GetDoubleValue("x2");
    float x3 = 0.48345;
    float x4 = 0.255154;
    double y1 = SubtractionFractions(x1,x2);
    double y2 = SubtractionFractions(x3, 54.4);
    double y3 = SubtractionFractions(y1,y2);
    float y4 = SubtractionFractions(x4, x3);
    std::cout <<  SubtractionFractions(25, 27, 23, 33);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
