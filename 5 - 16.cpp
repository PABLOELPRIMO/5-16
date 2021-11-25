/* 16. Дан массив ненулевых целых чисел размера N. Проверить, чередуются ли в нем
положительные и отрицательные числа.Если чередуются, то вывести 0, если нет, то
вывести номер первого элемента, нарушающего закономерность.

Я сделал программу через открытие файлов, которые находятся в папке с самой программой. Значения этих файлов можно менять, но я показал самые интересные варианты.*/

// #include "stdafx.h" (если более ранняя версия программы)
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	while (1)
	{
		cout << "Введите число: 1 - начало работы, 0 - конец работы" << endl;
		int z = _getch();
		switch (z)
		{
		case 49:
		{
			const char* arr[5] = { "data1.txt", "data2.txt", "data3.txt","data4.txt","data5.txt" };     // Здесь мы создаём массив, чтобы потом выбрать файл.
				cout << "Выберите файл: " << endl;
				int count = sizeof(arr) / sizeof(char*);
				for (int i = 0; i < count; i++)
				{
					cout << i + 1 << " файл: " << arr[i] << endl;
				}
				int num = -1;
				cout << "Введите число: ";
				cin >> num;
				fstream fin = fstream(arr[num - 1]);
				if (!fin)
				{
					cout << "Невозможно открыть файл." << endl;
					break;
				}
				int n = 0;
				fin >> n;	 // Здесь считывается первое значение файла - количество элементов в массиве.
				if (!n)
				{
					fin.close();
					cout << "Ошибка. Кол - во чисел не может быть = 0" << endl;
					break;
				}

				int* a = new int[n];   // Здесь создаётся новый массив из n числа элементов.

				int k = 0;
				cout << "Элементы массива: " << endl;
				while (!fin.eof() && k < n)    // здесь мы считываем все элементы массива и выписываем их через пробел.
				{
					fin >> a[k];
					cout << a[k++] << " ";
				}
				cout << endl;
				fin.close();

				if (k != n)
				{
					cout << "Ошибка. Объявлено " << n << " элементов, а найдено " << k << endl;
					break;
				}

				int p = 0;
				int prev = a[0];
				for (int i = 1; i < n; i++)
				{
					if (prev * a[i] < 0)
					{
						p = 1;
					}
					if (prev * a[i] > 0)
					{
						cout << "Ответ: " << a[i] << endl;
						break;
					}
					prev = a[i];

				}
				if (p == 1)
				{
					cout << "Ответ: " << 0 << endl;
				}
			cout << endl;
			continue;
		}
		case 48:
		{
			cout << "Конец работы." << endl;
			return 1;
		}

		default:
			cout << "Ошибка. Введите 1 или 0" << endl;
		}
	}
}