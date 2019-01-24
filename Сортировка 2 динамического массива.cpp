// Динамический массив с++ пример. Создание, заполнение, удаление, размер динамического массива. 

#include "pch.h"
#include <iostream>
#include <string>
#include "ctime"

using namespace std;


int rows;
int cols;
int randomMin;
int randomMAX;

void FooSort();




int main(int argc, const char * argv[]) {
	srand(time(NULL));

	setlocale(LC_ALL, "rus");


	cout << "Введите минимальное рандомное число: - > "; cin >> randomMin;
	cout << "Введите максимально рандомное число: - > "; cin >> randomMAX;
	

	cout << "Введите кол-во желаемое строк: - > "; cin >> rows;
	cout << "Введите кол-во желаемое столбцов: - > "; cin >> cols;
	if (rows*cols > randomMAX) {
		cout << "Введено некорректное значение\nПовторите попытку: " << endl;
		do {
			cout << "Введите кол-во желаемое строк: - > "; cin >> rows;
			cout << "Введите кол-во желаемое столбцов: - > "; cin >> cols;
		} while (rows*cols > randomMAX);

	}
	//randomMAX = randomMAX - randomMin;
	//    cout << "Razmer massiva ->"; cin >> size;
	int **arr = new int*[rows];

	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];

	}
	///////////////////////////////////
	int per = 0;
	int per1 = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = randomMin + rand() % randomMAX;
			for (int d = 0; d <= i; d++) {
				if ((d == i && per != 0) || (d != i && (per == 0 || per1 != 0))) {
					for (int c = 0; c <= cols; c++) {
						if ((per != 0 && c != cols) || (per1 != 0 && c != cols)) {
							if (arr[d][c] == arr[i][j]) {
								arr[i][j] = randomMin + rand() % randomMAX;
								d = 0;
								c = -1;
								continue;
							}

							else if ((i == 0 && j != c + 1) || (i != 0 && (i != d || i == d && j != c + 1))) {
								continue;
							}
							break;

						}
						else {
							break;
						}
					}
				}
			}
			per++;
		}
		per = 0;
		per1++;
	}

	cout << "Вывод неотсортированного массива:" << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << " " << arr[i][j] << "\t";
		}
		cout << endl;
	}
	/////////////////////////////////
	int max = 0;
	int x, y;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				x = i;
				y = j;
			}
		}
	}


	cout << endl;
	cout << "Max = " << max << endl;
	cout << "Строка = " << x + 1 << endl;
	cout << "Колонка = " << y + 1 << endl;
	//////////////////////////////////

	int min = randomMAX;
	//int x1, y;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] < min) {
				min = arr[i][j];
				x = i;
				y = j;
			}
		}
	}


	cout << endl;
	cout << "Min = " << min << endl;
	cout << "Строка = " << x + 1 << endl;
	cout << "Колонка = " << y + 1 << endl;
	//////////////////////////////////
	int tmp;
	int p = 0;
	for (int k = 0; k < rows*cols; k++)
	{
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols - 1; j++) {
				if (arr[i][j] > arr[i][j + 1]) {
					tmp = arr[i][j];
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = tmp;
				}
				if (i < cols - 1) {
					if (arr[i][rows - 1] > arr[i + 1][0] && i < cols - 1) {
						tmp = arr[i][rows - 1];
						arr[i][rows - 1] = arr[i + 1][0];
						arr[i + 1][0] = tmp;
					}
				}
			}
		}

	}

	/*for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] < arr[i][j - 1]) {
				int per = arr[i][j];
				arr[i][j] = arr[i][j - 1];
				arr[i][j - 1] = per;
			}
		}
	}


	cout << endl;
	cout << "Sort: " << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << " " << arr[i][j] << "\t";
		}
		cout << endl;
	}*/
	//////////////////////////////////
	// вывод отсортированного массива

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << " " << arr[i][j] << "\t";
		}
		cout << endl;
	}

	// Очистка памти динамического массива

	for (int i = 0; i < rows; i++) {
		delete[] arr[i];

	}



	delete[] arr;

	return 0;
}

void FooSort()
{
	
}
