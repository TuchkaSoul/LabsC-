#include <iostream>

unsigned int n, m;

int InputData(const char* mes="Введите число: ", const char* mesError="!!ERROR!!") //Ввод неотрицательного числа
{
    setlocale(0, "rus");

    std::string str;
    bool isInt = true;
    std::cout << mes<<"\n";
    std::cin >> str;
    for (int i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            isInt = false;
            std::cout << mesError<<"\n";
            InputData(mes,mesError);
            break;
        }
    }
    if (isInt) {
        int resalt = atoi(str.c_str());
        return resalt;
    }
    else return 0;
}
int** CreateArray() {
    srand(time(NULL));
    n = InputData("Введите число строк в матрице: ", "Введено некорректное значение. Повторите попытку ввода.(Это должно быть неотрицательное число)");
    m = InputData("Введите число столбцов в матрице: ", "Введено некорректное значение. Повторите попытку ввода.(Это должно быть неотрицательное число)");
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}
bool WriteArray(int** matrix) 
{
    bool isEmpty = matrix == nullptr;
    if (!isEmpty) 
    {
        std::cout << "___________________\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                std::cout << matrix[i][j] << "\t";
            std::cout << std::endl;
        }
        std::cout << "___________________\n";
    }
    else
    {
        std::cout << "\n{ }\n"; 
    }
    
    return !isEmpty;
}
int** MinorMatrix(int** originMatrix)
{
    int str = InputData("Введите номер строки в матрице для удаления: ", "Введено некорректное значение. Повторите попытку ввода.(Это должно быть неотрицательное число)");
    while(--str>n)
    {
        std::cout << "\n\nВведите число не превышающее размер Матрицы{" << n + 1 << ":" << m + 1 << "}\n";
        int str = InputData("Введите номер строки в матрице для удаления: ", "Введено некорректное значение. Повторите попытку ввода.(Это должно быть неотрицательное число)");
    }
    int col = InputData("Введите число столбцов в матрице: ", "Введено некорректное значение. Повторите попытку ввода.(Это должно быть неотрицательное число)");
    while (--col > m)
    {
        std::cout << "\n\nВведите число не превышающее размер Матрицы{" << n + 1 << ":" << m + 1 << "}\n";
        int str = InputData("Введите номер строки в матрице для удаления: ", "Введено некорректное значение. Повторите попытку ввода.(Это должно быть неотрицательное число)");
    }
    int** matrix1 = new int* [n-1];
    int im=-1; 
    for (int i = 0; i < n; i++)
    {
        if (i == str) {
                continue;
        }
        matrix1[++im] = new int[m-1];
        int jm = 0;
        for (int j = 0; j < m; j++)
        {
            if (j == col)continue;
            matrix1[im][jm++] = originMatrix[i][j];
        }
    }
    n--; m--;
    return matrix1;
}
int main()
{
    setlocale(0, "rus");
    std::cout << "Лабораторная работа 6.\n";
    int** arrayTwo =CreateArray();
    WriteArray(arrayTwo);
    int** arrayFinal=MinorMatrix(arrayTwo);
    WriteArray(arrayFinal);
    for (int i = 0; i < n + 1; i++)
        delete[] arrayTwo[i];
    delete[] arrayTwo;
    for (int i = 0; i < n; i++)
        delete[] arrayTwo[i];
    delete[] arrayFinal;
}