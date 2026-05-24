#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 20;
const int ROWS = 20;
const int COLS = 20;

// ---------- Робота з масивом ----------

void getArray(string filename, int arr[], int &n)
{
    ifstream fin(filename);

    fin >> n;

    for (int i = 0; i < n; i++)
    {
        fin >> arr[i];
    }

    fin.close();
}

void showArray(string filename, int arr[], int n)
{
    ofstream fout(filename);

    fout << n << endl;

    for (int i = 0; i < n; i++)
    {
        fout << arr[i] << " ";
    }

    fout.close();
}

// Видалення від’ємних елементів
void transformArray(int arr[], int &n)
{
    for (int i = 0; i < n;)
    {
        if (arr[i] < 0)
        {
            for (int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }

            n--;
        }
        else
        {
            i++;
        }
    }
}

// Сортування вставками
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// ---------- Робота з матрицею ----------

void getMatrix(string filename, int mx[][COLS], int &m, int &n)
{
    ifstream fin(filename);

    fin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> mx[i][j];
        }
    }

    fin.close();
}

void showMatrixResult(string filename, int result)
{
    ofstream fout(filename, ios::app);

    fout << endl;
    fout << "Count = " << result << endl;

    fout.close();
}

// Кількість стовпців,
// у яких всі елементи різні
int countDifferentColumns(int mx[][COLS], int m, int n)
{
    int count = 0;

    for (int j = 0; j < n; j++)
    {
        bool allDifferent = true;

        for (int i = 0; i < m; i++)
        {
            for (int k = i + 1; k < m; k++)
            {
                if (mx[i][j] == mx[k][j])
                {
                    allDifferent = false;
                }
            }
        }

        if (allDifferent)
        {
            count++;
        }
    }

    return count;
}

// ---------- Завдання 1 ----------

void task1()
{
    int arr[MAX];
    int n;

    string inFile, outFile;

    cout << "Input array file: ";
    cin >> inFile;

    cout << "Output array file: ";
    cin >> outFile;

    getArray(inFile, arr, n);

    transformArray(arr, n);

    showArray(outFile, arr, n);

    cout << "Task 1 completed!" << endl;
}

// ---------- Завдання 2 ----------

void task2()
{
    int mx[ROWS][COLS];
    int m, n;

    string filename;

    cout << "Input matrix file: ";
    cin >> filename;

    getMatrix(filename, mx, m, n);

    int result = countDifferentColumns(mx, m, n);

    showMatrixResult(filename, result);

    cout << "Result = " << result << endl;
}

// ---------- Завдання 3 ----------

void task3()
{
    int arr[MAX];
    int n;

    string inFile, outFile;

    cout << "Input sort file: ";
    cin >> inFile;

    cout << "Output sort file: ";
    cin >> outFile;

    getArray(inFile, arr, n);

    insertionSort(arr, n);

    showArray(outFile, arr, n);

    cout << "Sorting completed!" << endl;
}

// ---------- main ----------

int main()
{
    task1();

    task2();

    task3();

    return 0;
}
