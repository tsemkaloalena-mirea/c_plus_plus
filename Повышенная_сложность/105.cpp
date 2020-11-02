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
}

int common_teacher(vector <int> teachers1, vector <int> teachers2) {
	for (int i = 0; i < teachers1.size(); i++) {
		for (int j = 0; j < teachers2.size(); j++) {
			if (teachers1[i] == teachers2[j]) {
				return teachers1[i];
			}
		}
	}
	return 0;
}

int main() {
	setlocale(0, "");
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
				cout << t << " - не монах" << endl;
			}
			else {
				cout << t << " - монах, его учителя ";
				for (int k = 0; k < teachers.size(); k++) {
					cout << teachers[k];
					if (k < teachers.size() - 1) {
						cout << ", ";
					}
				}
				cout << endl;
			}
		}
		else {
			int t1, t2;
			data >> t1 >> t2;
			vector <int> teachers1, teachers2;
			teachers1 = teachers_of_friars(friars, t1, teachers1);
			teachers2 = teachers_of_friars(friars, t2, teachers2);
			if (teachers1.size() == 0 and teachers2.size() == 0) {
				cout << t1 << " и " << t2 << " - не монахи" << endl;
			}
			else if (teachers1.size() == 0) {
				cout << t1 << " - не монах" << endl;
			}
			else if (teachers2.size() == 0) {
				cout << t2 << " - не монах" << endl;
			}
			else {
				int common = common_teacher(teachers1, teachers2);
				cout << t1 << " и " << t2 << " - оба монахи";
				if (common == 0) {
					cout << ", общего учителя нет" << endl;
				}
				else {
					cout << ", и их общий учитель " << common << endl;
				}
				
			}
		} 
	}
	data.close();
	return 0;
}
