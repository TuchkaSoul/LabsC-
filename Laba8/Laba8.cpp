#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
using namespace std;

struct Information
{
	char carrier[255]; //Носитель
	char volume[255]; //Объём
	char title[255]; //Название
	char author[255]; //Автор
};

char file_start[] = "test_start.txt";
int n;


void createFile()
{
	FILE* file;

	if ((file = fopen(file_start, "wb")) == NULL)
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		Information information1;
		cin.get();
		cout << " * Введите носитель: ";
		cin.getline(information1.carrier, 255);
		cout << " * Введите объём: ";
		cin.getline(information1.volume, 255);
		cout << " * Введите название: ";
		cin.getline(information1.title, 255);
		cout << " * Введите автора: ";
		cin.get(information1.author, 255);

		cout << endl;

		fwrite(&information1, sizeof(Information), 1, file);
	}
	fclose(file);
	return;
}

void WriteFile()
{
	FILE* file;

	if ((file = fopen(file_start, "rb")) == NULL)
	{
		cout << "Ошибка открытия файла";
		return;
	}

	cout << "Вывод файла: " << endl;
	for(int i = 1; i <= n and !feof(file); i++)
	{
		Information information;
		fread(&information, sizeof(Information), 1, file);

		cout << " < Носитель: " << information.carrier << endl;
		cout << " < Объем: " << information.volume << endl;
		cout << " < Название: " << information.title << endl;
		cout << " < Адрес: " << information.author << endl;
		
		cout << endl;
	}
	fclose(file);
	return;
}


int deleteElement()
{
	FILE* file1;
	FILE* file2;
	int delElement = 0;
	string delVolume;
	cout << "Введите объем информации для удаления: ";
	cin >> delVolume;
	cout << endl;

	char file_temp[] = "test_temp.txt";

	if ((file1 = fopen(file_start, "rb")) == NULL)
	{
		cout << "Ошибка открытия файла";
		return 0;
	}

	if ((file2 = fopen(file_temp, "wb")) == NULL)
	{
		cout << "Ошибка открытия файла";
		return 0;
	}

	for (int i = 1; i <= n and !feof(file1); i++)
	{
		Information information;
		fread(&information, sizeof(Information), 1, file1);

		if (information.volume != delVolume or delElement>=1)
		{
			fwrite(&information, sizeof(Information), 1, file2);
		}
		else
		{
			delElement += 1;
		}
	}
	
	fclose(file1);
	fclose(file2);

	remove(file_start);
	rename(file_temp, file_start);
	return delElement;
}

int addElement()
{
	FILE* file1;
	FILE* file2;

	int addElement = 0;
	int addNum;
	cout << "Введите номер элемента, перед которым хотите добавить информацию : ";
	cin >> addNum;
	cout << endl;
	
	char file_temp[] = "test_temp.txt";

	if ((file1 = fopen(file_start, "rb")) == NULL)
	{
		cout << "Ошибка открытия файла";
		return 0;
	}

	if ((file2 = fopen(file_temp, "wb+")) == NULL)
	{
		cout << "Ошибка открытия файла";
		return 0;
	}
	for (int i = 1; i < n+1; i++)
	{
		Information information;
		fread(&information, sizeof(Information), 1, file1);
		if (i == addNum) {
			Information new_information;
			cin.get();
			cout << " * Введите носитель: ";
			cin.getline(new_information.carrier, 255);
			cout << " * Введите объём: ";
			cin.getline(new_information.volume, 255);
			cout << " * Введите название: ";
			cin.getline(new_information.title, 255);
			cout << " * Введите автора: ";
			cin.get(new_information.author, 255);
			cout << endl;

			fwrite(&new_information, sizeof(Information), 1, file2);
		}fwrite(&information, sizeof(Information), 1, file2);
	}
	
	fclose(file1);
	fclose(file2);

	remove(file_start);
	rename(file_temp, file_start);

	return 1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");

	cout << "Лабораторная работа 8\nВведите количество информации: ";
	cin >> n;
	cout << endl;

	createFile();

	WriteFile();

	n-= deleteElement();
	WriteFile();

	n+= addElement();
	WriteFile();
	
	return 0;
}