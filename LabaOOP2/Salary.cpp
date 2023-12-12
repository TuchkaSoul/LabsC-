#include <iostream>
#include <string>
#include "Salary.h"
using namespace std;

Salary::Salary() {
	cout << "����� ������������ ��� ����������" << '\n';
	name = "";
	reward = 0;
	percent = 0;
}

Salary::Salary(string s, double d, int i) {
	cout << "����� ������������ � �����������" << '\n';
	name = s; reward = d; percent = i;
}

Salary::Salary(const Salary& t) {
	cout << "����� ������������ �����������" << '\n';
	name = t.name;
	reward = t.reward;
	percent = t.percent;
}

Salary::~Salary() {
	cout << "����� �����������" << '\n';
}

void Salary::setName(string name) {
	this->name = name;
}

void Salary::setReward(double reward) {
	this->reward = reward;
}

void Salary::setPercent(int percent) {
	percent = percent;
}

string Salary::getName() {
	return name;
}

double Salary::getReward() {
	return reward;
}

int Salary::getPercent() {
	return percent;
}

void Salary::show() {
	cout << "Name: " << name << '\n';
	cout << "Reward: " << reward << '\n';
	cout << "Percent: " << percent << '\n';
}