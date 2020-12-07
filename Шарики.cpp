#include <iostream>
using namespace std;

int n = 10;

int perestanovka(int m, int n) {
	if (m > 2) {
		return (perestanovka(m - 1, n) + perestanovka(m - 2, n)) * (m - 1);
	}
	else {
		return 1;
	}
}


int main() {
	cout << perestanovka(n, n) << endl;
}
