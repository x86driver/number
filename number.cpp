#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
using namespace std;

char number[10] = {'1','2','3','4','5','6','7','8','9','0'};

unsigned int cal(char question[4], char input[4])
{
	unsigned int A = 0, B = 0;
	for (int i = 0; i < 4; ++i) {
		if (question[i] == input[i]) {
			++A;
			continue;
		}
		for (int j = 0; j < 4; ++j) {
			if (question[i] == input[j])
				++B;
		}
	}
	return (A << 16) | B;
}

int main()
{
	unsigned int ans, count = 0;
	char question[4];
	char input[4];
	srand(time(0));
	random_shuffle(&number[0], &number[9]);
	strncpy(question, number, 4);
	cout << "Answer: " << question << endl;
	do {
		cout << "Input number: ";
		cin >> input;
		ans = cal(question, input);
		cout << (ans >> 16) << "A" << (ans & 0x0FFFF) << "B" << "        ";
		cout << count++ << " times!" << endl;
	} while (ans != 0x40000);
	cout << "You are right!" << endl;
	return 0;
}

