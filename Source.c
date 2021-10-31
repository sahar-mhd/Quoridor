#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void colorizedText() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int k = 1; k < 255; k++)
	{
		SetConsoleTextAttribute(hConsole, k);
		printf("%d I want to be nice today!\n", k);
	}
}
void printMap() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
	for (int i = 0; i <= 18; i++) {
		for (int j = 0; j <= 18; j++) {
			if (i == 0) {
				if (j == 0) {
					printf("%c", 218);
				}
				else if (j == 18) {
					printf("%c", 191);
				}
				else if (j % 2 == 0) {
					printf("%c", 194);
				}
				else {
					printf("%c", 196);
				}
			}
			else if (i == 18) {
				if (j == 0) {
					printf("%c", 192);
				}
				else if (j == 18) {
					printf("%c", 217);
				}
				else if (j % 2 == 0) {
					printf("%c", 193);
				}
				else {
					printf("%c", 196);
				}
			}
			else if (i > 0 && i < 18) {
				if (i % 2 == 0) {
					if (j == 0) {
						printf("%c", 195);
					}
					else if (j == 18) {
						printf("%c", 180);
					}
					else if (j % 2 == 0) {
						printf("%c", 197);
					}
					else if(i==2 && j==5) {
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, 199);
						printf("%c", 196);
						hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, 7);
					}
					else printf("%c", 196);
				}
				else {
					if (j % 2 == 0) {
						printf("%c", 179);
					}
					else {
						printf(" ");
					}
				}
			}
		}
		printf("\n");
	}
}
//Use 233 As Player Charchter
int main() {
	printMap();
	int n;
	scanf("%d", &n);
	return 0;
}