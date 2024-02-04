#include <iostream>
using namespace std;

class queue
{
private:
	int maxSize;
	int* queArray;
	int front;
	int rear;
	int nItems;

public:
	queue(int s) { // конструктор
		maxSize = s;
		queArray = new int[maxSize];
		front = 0;
		rear = -1;
		nItems = 0;
	}
	// вставка элемента в конец очереди
	void insert(int j) {
		if (rear == maxSize - 1) {
			rear = -1;
			nItems = 0;
		}
		queArray[++rear] = j;
		nItems++;
	}
	// извлечение элемента в начале очереди 
	int remove() {
		int temp = queArray[front++];
		if (front == maxSize)
			front = 0;
		nItems--;
		return temp;
	}
	// чтение элемента в начале очереди
	int peekFront() {
		return queArray[front];
	}

	bool isEmpty() {
		return (nItems == 0);
	}
	bool isFull() {
		return (nItems == maxSize);
	}
	int size() {
		return nItems;
	}
	void printQueue() {
		if (nItems == 0) {
			cout << "Queue is empty\n";
			return;
		}
		if (front > rear) {
			int j = front;
			while (j != maxSize) {
				cout << queArray[j] << endl;
				j++;
			}
			j = 0;
			while (j <= rear) {
				cout << queArray[j] << endl;
				j++;
			}
		}
		else if (front < rear) {
			for (int i = front; i <= rear; i++)
				cout << ": " << queArray[i] << endl;
		}
		else if (nItems == 1)
			cout << "1: " << queArray[front];

		cout << endl;
		return;
	}


};

void main() {
	setlocale(LC_ALL, "Russian");
	int choice = 1;
	int number;
	cout << "Введите количество элементов очереди: ";
	cin >> number;
	queue TheQueue(number);
	cout << "1 - Вставить элемент\n2 - Удалить элемент из начала\n3 - Вывести очередь на экран\n-1 - Выход\n";
	while (choice != -1) {
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Элемент: ";
			cin >> number;
			TheQueue.insert(number);
			break;
		case 2:
			TheQueue.remove();
			break;
		case 3:
			TheQueue.printQueue();
			break;
		case -1:
			break;
		}
	}
	system("pause");

}