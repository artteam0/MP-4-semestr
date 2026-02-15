#include <iostream>
#include <ctime>

using namespace std;

char* randomString(int size) {
	char* str = (char*)malloc(sizeof(char) * size);

	for (int i = 0; i < size; i++) {
		str[i] = rand() % 26 + 'a';
	}
	return str;
}

int main()
{
	setlocale(LC_ALL, "ru");

	char* str1 = randomString(300);
	cout << "S1: ";

	for (int i = 0; i < 300; i++) {
		if (i % 50 == 0) {
			cout << endl;
		}
		cout << str1[i];
	}

	cout << endl;

	char* str2 = randomString(200);
	cout << "S2: ";

	for (int i = 0; i < 200; i++) {
		if (i % 50 == 0) {
			cout << endl;
		}
		cout << str2[i];
	}
}
