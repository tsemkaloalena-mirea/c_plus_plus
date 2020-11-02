#include <iostream>
using namespace std;

int step = 0;
int n_columns = 5;
void replace(int from, int to, int n) {
	int temp;
	if ((from == 1 or to == 1) and (from == 3 or to == 3)) {
		temp = 2;
	}
	else if ((from == 1 or to == 1) and (from == 2 or to == 2)) {
		temp = 3;
	}
	else {
		temp = 1;
	}
	if (n == 1) {
		cout << from << " => " << to << " | ";
		if (++step % n_columns == 0) cout << endl;
	}
	else {
		replace(from, temp, n - 1);
		cout << from << " => " << to << " | ";
		if (++step % n_columns == 0) cout << endl;
		replace(temp, to, n - 1);
	}
}

int main() {
	setlocale(0, "");
	int n = 5;
	if (pow(2, n - 1) < 8) {
		n_columns = pow(2, n) - 1;
	}
	cout << "n = " << n << endl;
	replace(1, 3, n);
	cout << endl;
	cout << "Общее число перемещений " << step << endl;

	return 0;
}
