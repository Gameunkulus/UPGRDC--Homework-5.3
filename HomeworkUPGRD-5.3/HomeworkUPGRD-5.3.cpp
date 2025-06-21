// HomeworkUPGRD-5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std; 

template <class T>
class Vector{
protected:

	int actSize = 2;
	int logSize = 0;
	T *arr;

public:
    
	Vector() {
		arr = new T [actSize];
	}

	Vector(int num) {
		this->actSize = num;
        arr = new T [actSize];
	};

	T at(int index) {
		if (index < 0 || index > actSize) {
			throw exception("Ошибка, значение не может ревышать допустимое значение");
		}
		return arr[index];
	};

	T push_back(T value) {    
            if (logSize >= actSize) {
                actSize *= 2;
                int* newArr = new int[actSize];
                for (int i = 0; i < logSize; i++) {
                    newArr[i] = arr[i];
                }
                *arr = *newArr;
            }
			logSize++;
            return arr[logSize - 1] = value;			
        }
	

	int size() {
		return actSize;
	};

	int capacity() {
		int num = actSize - logSize;
		return num;
	};
};

int main()
{
	setlocale(LC_ALL, "ru");
	Vector<int> my_vec1;
	
	my_vec1.push_back(7);
	my_vec1.push_back(5);
	my_vec1.push_back(16);
	my_vec1.push_back(8);

	cout << "Элемент под первым номером: " << my_vec1.at(0) << endl;

	cout << "Элемент под не существующим номером: " << endl;
	try {
		my_vec1.at(7);
	}
	catch(exception& ex){
		cout << ex.what() << endl;
	}
	int num1 = 4;

	my_vec1.push_back(num1);
	cout << "Последнее добавленное число: " << my_vec1.at(4) << endl;

	cout << "Количество элементов в контейнере: " << my_vec1.size() << endl;
	cout << "Количество элементов, которое может вместить контейнер до нового выделения памяти: " << my_vec1.capacity() << endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
