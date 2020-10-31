#include <iostream>
#include <fstream>
using namespace std;

int friar[600][3];

int friar_check(int a[600][3]) {
	
	return 0;
}

int main() {
	setlocale(0, " ");
	fstream data;
	// Считываем исходные данные о монахах
	data.open("friars.txt", ios::in);
	int i;
	while (!data.eof()) {
		data >> i;
		i--;
		data >> friar[i][0];
		data >> friar[i][1];
		data >> friar[i][2];
	}
	data.close();
	// Считываем и выполняем задания
	data.open("task.txt", ios::in);
	int n;
	while (!data.eof()) {
		
	}
	data.close();
	return 0;
}
