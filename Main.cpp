#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// ����� ������� � �������
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

// ���������� �������
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

void type_of(int num) { std::cout << "INT\n"; }
void type_of(double num) { std::cout << "DOUBLE\n"; }
void type_of(char num) { std::cout << "CHAR\n"; }
void type_of(float num) { std::cout << "FLOAT\n"; }

int sum_AB(int A, int B) {
	if (A > B)
		std::swap(A, B);
	if (A == B)
		return A;
	return sum_AB(A, B - 1) + B;
}

template <typename T>
void middle_sort(T arr[], int length) {
	int first_index = 0, last_index = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	for (int i = length - 1; i >= first_index; i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	// ������� ����������
	/*if (first_index != last_index)
		std::sort(arr + first_index + 1, arr + last_index);*/
	//����������� ����������
	for (int i = last_index - 1; i > first_index + 1; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

template <typename T>
void move_arr(T arr[], int length, int n) {
	for (int k = 0; k < n; k++)
		for (int i = length - 1; i > 0; i--)
			std::swap(arr[i], arr[i - 1]);
}

template <typename T>
double change_arr(T arr[], int length, int n) {
	T sum = 0;
	int counter = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] > n) {
			sum += arr[i];
			counter++;
			arr[i] = 0;
		}
	return double(sum) / counter;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// ������ 1. ��� ������
	/*std::cout << "������ 1. ��� ������\n";
	std::cout << "7 - "; type_of(7);
	std::cout << "5.5 - "; type_of(5.5);
	std::cout << "'A' - "; type_of('A');
	std::cout << "5.5f - "; type_of(5.5f);*/

	// ������ 2. ����������� ����� �� N �� M
	/*std::cout << "������ 2. ����������� ����� �� N �� M\n";
	std::cout << "������� ������ ��������� -> ";
	std::cin >> n;
	std::cout << "������� ����� ��������� -> ";
	std::cin >> m;
	std::cout << "����� ����� �� " << n << " �� " << m << ": " << sum_AB(n, m) << "\n\n";*/

	// ������ 3. ���������� ��������
	/*std::cout << "������ 3. ���������� ��������\n";
	std::cout << "����������� ������:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);
	std::cout << "�������� ������:\n";
	middle_sort(arr3, size3);
	print_arr(arr3, size3);
	std::cout << std::endl;*/

	// ������ 4. ����� �������
	/*std::cout << "������ 4. ����� �������\n";
	const int size4 = 5;
	int arr4[size4]{ 1,2,3,4,5 };
	print_arr(arr4, size4);
	std::cout << "�������� ������:\n";
	std::cout << "������� ���-�� ������� -> ";
	std::cin >> n;
	move_arr(arr4, size4, n);
	print_arr(arr4, size4);
	std::cout << std::endl;*/

	// ������ 5. ������ � �����
	std::cout << "������ 5. ������ � �����\n";
	std::cout << "����������� ������:\n";
	const int size5 = 10;
	int arr5[size5];
	fill_arr(arr5, size5, -20, 21);
	print_arr(arr5, size5);
	std::cout << "������� ����� -> ";
	std::cin >> n;
	std::cout << "������� �������������� ���������, ������� " << n << ": " << change_arr(arr5, size5, n) << std::endl;
	std::cout << "�������� ������:\n";
	print_arr(arr5, size5);
	std::cout << std::endl;



	return 0;
}