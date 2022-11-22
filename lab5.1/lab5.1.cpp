#include <iostream>

using namespace std;

// конвертируем матрицу смежности в список смежности 

int main()
{
	setlocale(LC_ALL, "rus");

	int n1;
	int kol = 0;
	int sum1 = 0, sum2 = 0, sum3 = 0;
	int izol = 0;
	int konts = 0;
	int domin = 0;

	int edge = 0; // ребро

	printf_s("Введите размерность матрицы M1: ");
	cin >> n1;											// Вводим размерность квадратной матрицы M1
	cout << "\n";

	int** matrix = new int* [n1];						// Генерируем матрицу M1
	for (int i = 0; i < n1; ++i)
	{
		matrix[i] = new int[n1];
	}

	int** A = new int* [n1];
	for (int i = 0; i < n1; ++i)
	{
		A[i] = new int[n1];
	}

	srand(time(NULL));
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			A[i][j] = rand() % 100;
			if (i == j)
			{
				A[i][j] = 0;
			}
			if (A[i][j] >= 0 && A[i][j] <= 30)
			{
				A[i][j] = 0;
			}
			else if (A[i][j] >= 31 && A[i][j] < 100)
			{
				A[i][j] = 1;
			}

		}
	}


	printf_s("Матрица смежности: \n\n");

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			A[i][j] = A[j][i];
			cout << A[i][j] << " ";							// Выводим элементы матрицы M1
		}
		cout << endl;
	}

	printf_s("\n\nМатрица инцидентности: \n");

	for (int i = 0; i < n1; i++)
	{
		for (int j = i; j < n1; j++)
		{
			if (matrix[i][j] == 1)
			{
				kol++;
			}
		}
	}

	//Чтение половины матрицы смежности
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i][j] && i != j) {
				//значения матрицы инцидентности (направленное ребро) равны 1 и 1
				matrix[i][edge] = 1;
				matrix[j][edge] = 1;
				edge++;
			}
		}
	}

	//Устнановление для всех элементов, отличных от 1, значение 0
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < edge; j++)
		{
			if (matrix[i][j] != 1)
			{
				matrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n1; i++) {
		printf("\n");
		for (int j = 0; j < edge; j++) {
			printf("%d ", matrix[i][j]);					//Вывод элементов матрицы инц.
		}

	}



	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i][j] == 1) {
				//значения матрицы инцидентности (направленное ребро) равны 1 и 1
				matrix[i][edge] = 1;
				matrix[j][edge] = 1;
				kol++;
			}
		}
	}
	cout << "\n\nРазмер графа:  " << kol;

	for (int i = 0; i < n1; i++)
	{
		sum1 = 0;
		for (int j = 0; j < n1; j++)
		{
			sum1 = sum1 + A[i][j];
		}
		if (sum1 == 0)
		{
			izol++;
		}
	}
	cout << "\nКоличество изолированных вершин:  " << izol;


	for (int i = 0; i < n1; i++)
	{
		sum2 = 0;
		for (int j = 0; j < n1; j++)
		{
			sum2 = sum2 + A[i][j];
		}
		if (sum2 == 1)
		{
			konts++;
		}
	}
	cout << "\nКоличество концевых вершин:  " << konts;


	for (int i = 0; i < n1; i++)
	{
		sum3 = 0;
		for (int j = 0; j < n1; j++)
		{
			sum3 = sum3 + A[i][j];
		}
		if (sum3 == n1 - 1)
		{
			domin++;
		}
	}
	cout << "\nКоличество доминирующих вершин:  " << domin << "\n";

}

