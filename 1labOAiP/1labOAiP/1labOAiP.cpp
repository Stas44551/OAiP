#include <iostream>
#include <vector>
using namespace std;
int main() {
vector <int>  numbers  {1, 2, 3, 4, 5}; // создаем список чисел
int temp = numbers[0]; // сохраняем первое число
numbers[0] = numbers[numbers.size()-1]; // заменяем первое число на последнее
numbers[numbers.size()-1] = temp; // заменяем последнее число на сохраненное
for (int number : numbers) { // выводим измененный список чисел
cout << number << " ";
}
return 0;
}