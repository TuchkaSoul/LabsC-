#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<Windows.h>
#include <regex> 


char F1_char[] = "F1.txt";
char F2_char[] = "F2.txt";
int numStrings = 100;
const int sizeStrings = 1003;
std::string MinWord() {
    setlocale(0, "rus");
    std::string line;
    std::ifstream in(F2_char);
    std::string minWord;
    int min = -1;
    if (in.is_open())
    {
        while (std::getline(in, line)) 
        {
            std::regex words_regex("\\b\\w+");
            auto words_begin = std::sregex_iterator(line.begin(), line.end(), words_regex);
            char* resalt = new char[distance(words_begin, std::sregex_iterator())];


            
            for (std::sregex_iterator k = words_begin; k != std::sregex_iterator(); ++k) 
            {
                std::smatch match = *k;
                std::string match_str = match.str();
                if (match_str.length() < min or min == -1) 
                {
                    min = match_str.length();
                    minWord = match_str;
                }
            }
        }
    }
    in.close();
    std::ofstream out;          
    out.open(F2_char, std::ios::app);      
    if (out.is_open())
    {
        out << "\nThe shortest word equals: " << minWord << std::endl;
    }
    out.close();
    return minWord;
}
bool CreateFile1() 
{
    FILE* F1; char mass;
	if ((F1 = fopen(F1_char, "wb")) == NULL)
	{
		std::cout << "Ошибка открытия файла" << std::endl;
		return false;
	}
    for (int i = 0; i < numStrings; i++) 
    {
        for (int i = 0; i < sizeStrings; i++)
        {
            mass = (rand() % ('z' - 'a' + 2)) + 'a' - 1;
            if (mass < 'a') mass = ' ';
            fwrite(&mass, 1, sizeof(mass), F1);
        }
        mass = '\n';
        fwrite(&mass, 1, sizeof(mass), F1);
    }
    fclose(F1);
    return true;
}
char* GetFirstCharString(char* strings) {
    std::string strg = strings;
    std::regex words_regex("\\b\\w");
    auto words_begin = std::sregex_iterator(strg.begin(), strg.end(), words_regex);
    char* resalt = new char[distance(words_begin, std::sregex_iterator())];
    int i = 0;
    for (std::sregex_iterator k = words_begin; k != std::sregex_iterator(); ++k) {
        std::smatch match = *k;
        std::string match_str = match.str();
        char* c = new char[2];
        std::copy(match_str.begin(), match_str.end(), c);
        resalt[i++] = c[0];
        delete[] c;
    }
    return resalt;
}
bool isFirstOriginal(char* str) {
    if (*str != '\0') {
        char firstChar = *str;
        bool isOriginal = true;
        str++;
        while (*str != '\0' && isOriginal) {
            isOriginal = firstChar != *str;
            str++;
        }
        return isOriginal;
    }
    else {
        return false;
    }
}
bool CreateFile2()
{
    setlocale(0, "rus");
    FILE* F1;
    FILE* F2;

    if ((F1 = fopen(F1_char, "rb")) == NULL)
    {
        std::cout << "Ошибка открытия файла" << std::endl;
        return false;
    }
    if ((F2 = fopen(F2_char, "wb")) == NULL)
    {
        std::cout << "Ошибка открытия файла" << std::endl;
        return false;
    }
    char buf[sizeStrings+1];
    while (fgets(buf, sizeStrings+1,F1) != NULL)
    {

        if (isFirstOriginal(GetFirstCharString(buf))) {
            fwrite(buf, sizeStrings, 1, F2);
            fwrite("\n", 1, 1, F2);
        }
            
    }
    fclose(F1);
    fclose(F2);
    return true;
}


int main()
{
    setlocale(0, "rus");
    std::cout << "Лабораторная работа 9\n";
    CreateFile1();
    CreateFile2();
    MinWord();
}

