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
	queue(int s) { // �����������
		maxSize = s;
		queArray = new int[maxSize];
		front = 0;
		rear = -1;
		nItems = 0;
	}
	// ������� �������� � ����� �������
	void insert(int j) {
		if (rear == maxSize - 1) {
			rear = -1;
			nItems = 0;
		}
		queArray[++rear] = j;
		nItems++;
	}
	// ���������� �������� � ������ ������� 
	int remove() {
		int temp = queArray[front++];
		if (front == maxSize)
			front = 0;
		nItems--;
		return temp;
	}
	// ������ �������� � ������ �������
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

	void swap(int &firstElement, int &secondElement) {
		int temp = firstElement;
		firstElement = secondElement;
		secondElement = temp;
	}
	void shakerSort() {
		bool swapped = 1;
		int start = 0;
		int end = nItems - 1;
		while (swapped) {
			swapped = 0;
			for (int i = start; i < end; i++) {
				if (queArray[i] > queArray[i + 1]) {
					swap(queArray[i], queArray[i + 1]);
					swapped = 1;
				}
			}
			if (!swapped)
				break;
			--end;
			swapped = 0;
			for (int i = end - 1; i >= start; --i) {
				if (queArray[i] > queArray[i + 1]) {
					swap(queArray[i], queArray[i + 1]);
					swapped = 1;
				}
			}
			++start;
		}
	}


};

void main() {
	setlocale(LC_ALL, "Russian");
	int choice = 1;
	int number;
	cout << "������� ���������� ��������� �������: ";
	cin >> number;
	queue TheQueue(number);
	cout << "1 - �������� �������\n2 - ������� ������� �� ������\n3 - ������� ������� �� �����\n4 - ���������� ��������������\n-1 - �����\n";
	while (choice != -1) {
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "�������: ";
			cin >> number;
			TheQueue.insert(number);
			break;
		case 2:
			TheQueue.remove();
			break;
		case 3:
			TheQueue.printQueue();
			break;
		case 4:
			TheQueue.shakerSort();
			break;
		case -1:
			break;
		}
	}
	system("pause");

}