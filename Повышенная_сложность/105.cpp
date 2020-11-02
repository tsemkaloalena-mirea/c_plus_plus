#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> teachers_of_friars(int friars[600][3], int friar, vector <int> teachers) {
	int j;
	for (j = 1; j < 600; j++) {
		if (friar == friars[j][0] or friar == friars[j][1] or friar == friars[j][2]) {
			teachers.push_back(j + 1);
			return teachers, teachers_of_friars(friars, j + 1, teachers);
		}
	}
	return teachers;
	//return 0;
}

int main() {
	setlocale(0, " ");
	fstream data;
	// Считываем исходные данные о монахах
	data.open("friars.txt", ios::in);
	int i;
	int friars[600][3];
	while (!data.eof()) {
		data >> i;
		i--;
		data >> friars[i][0];
		data >> friars[i][1];
		data >> friars[i][2];
	}
	data.close();
	// Считываем и выполняем задания
	data.open("task.txt", ios::in);
	int n;
	
	while (!data.eof()) {
		data >> n;
		if (n == 1) {
			int t;
			data >> t;
			vector <int> teachers;
			teachers = teachers_of_friars(friars, t, teachers);
			if (teachers.size() == 0) {
				cout << t + 1 << " - не монах" << endl;
			}
			else {
				cout << t + 1 << " - монах, его учителя ";
				for (int k = 0; k < teachers.size(); k++) {

				}
			}
		}
		for (int k = 0; k < n; k++) {
			data >> t;
			vector <int> teachers;
			teachers = teachers_of_friars(friars, t, teachers);
			cout << "";
		} 
	}
	data.close();
	return 0;
}
