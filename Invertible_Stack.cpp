#include <iostream>
using namespace std;

template <class T>
class stack {
	int maxsize;
	T currsize;
	T* arr;
	T front;
	T rear;
	bool flip;
public:
	stack(T s) {
		maxsize = s;
		currsize = 0;
		front = 0;
		rear = maxsize - 1;
		arr = new T[s];
		flip = false;
	}

	void flipStack() {
		if (flip == false) {
			flip = true;
		}
		else flip = false;
	}

	//2. isEmpty
	bool isEmpty() {
		if (currsize == 0) return true;
		else return false;

	}

	//3. isFull
	bool isFull() {
		if (currsize == maxsize) {
			return true;
		}
		else return false;
	}

	void capacity() {
		int x = 0;
		int storemax = 0;
		if (currsize == maxsize) {
			int storemax = maxsize - 1;
			maxsize *= 2;
			T* arr2 = new T[maxsize];
			for (int i = 0; i < front; i++) {
				arr2[i] = arr[i];
			}
			int x = maxsize - 1;
			for (int i = storemax; i > rear; i--) {
				arr2[x] = arr[i];
				x--;
			}
			delete arr;
			arr = arr2;
			rear = x;
		}
		else if (currsize < maxsize / 2) {
			int storemax = maxsize - 1;
			maxsize /= 2;
			T* arr2 = new T[maxsize];
			for (int i = 0; i < front; i++) {
				arr2[i] = arr[i];
			}
			int x = maxsize - 1;
			for (int i = storemax; i > rear; i--) {
				arr2[x] = arr[i];
				x--;
			}
			arr = arr2;
			rear = x;
		}

	}


	// 4.Pop
	void pop() {
		if (!isEmpty()) {
			if (flip == false) {
				front--;
			}
			else {
				rear++;

			}
			currsize--;
		}
	}

	// 5.Push
	void push(T val) {
		if (!isFull()) {
			if (flip == false) {
				arr[front] = val;
				front++;
			}
			else {
				arr[rear] = val;
				rear--;
			}
			currsize++;
		}
	}



	// 7. Print
	void print() {
		if (flip == false) {
			for (int i = 0; i < front; i++) {
				cout << arr[i] << " ";
			}
			for (int i = rear + 1; i < maxsize; i++) {
				cout << arr[i] << " ";
			}
		}
		else {
			for (int i = rear + 1; i < maxsize; i++) {
				cout << arr[i] << " ";
			}
			for (int i = 0; i < front; i++) {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
	}




};

int main() {
	stack <int> s1(6);
	s1.push(1);
	s1.capacity();
	s1.push(2);
	s1.capacity();
	s1.push(3);
	s1.capacity();
	s1.flipStack();
	s1.push(4);
	s1.capacity();
	s1.push(5);
	s1.capacity();
	s1.push(6);
	s1.print();

	s1.pop();
	s1.capacity();
	s1.print();
	s1.pop();
	s1.capacity();
	s1.print();
	s1.flipStack();
	s1.print();
	s1.pop();
	s1.flipStack();
	s1.capacity();
	s1.print();
	return 0;
}