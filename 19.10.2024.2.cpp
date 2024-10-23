#include <iostream>
#include <memory>

class smartArray {
public:
	smartArray(int size) : size_arr(0), capacity(size), Arr(new int[size]) {
		size_arr = 0;
		Arr = new int[size];
	}
	~smartArray() {
		delete[] Arr;
	}

	void push(int value, int size) {
		if (size_arr < size) { Arr[size_arr] = value; size_arr++; }
		else std::cout << "Array is overloaded, not enough space";
	}
	void setElement(int index, int value, int size) {
		if (index >= 0 && index < size) {
			Arr[index] = value;
		}
		else {
			std::cout << "index is out of range array: ";
		}
	}
	void printElement(int index) {
		std::cout << "Array[" << index << "] = " << Arr[index] << std::endl;
	}
	void erazeElement(int size) {
		for (int i = 0; i < size; i++) {
			Arr[i] = 0;
			size_arr--;
		}
	}
	int ejectElement(int index, int size) {
		if (index < size) return Arr[index];
		else std::cout << "Out of range in func ejectElement, returned -1" << std::endl;
		return -1;
	}

	smartArray& operator=(const smartArray& other) {
		if (this != &other) {
			delete[] Arr;
			capacity = other.capacity;
			size_arr = other.size_arr;
			Arr = new int[capacity];
			for (int i = 0; i < size_arr; ++i) {
				Arr[i] = other.Arr[i];
			}
		}
		return *this;
	}

	smartArray(const smartArray &other) {
		capacity = other.capacity;
		size_arr = other.size_arr;
		Arr = new int[capacity];
		for (int i = 0; i < size_arr; ++i) {
			Arr[i] = other.Arr[i];
		}
	}

private:
	int* Arr;
	int size_arr;
	int capacity;
};



/*void copyElement(smartArray& sa, smartArray& sa1, int size, int size1) {
	sa1.erazeElement(size1);
	int el;
	for (int i = 0; (i < size) && (i < size1); i++) {
		el = sa.ejectElement(i,size);
		//sa1.setElement(i, el, size1);
		sa1.push(el, size);
	}
}*/

void create_arr(int size, int size1) {
	smartArray sa(size);
	int value;
	for (int i = 0; i < size; i++) {
		std::cout << "Please insert value of array" << std::endl;
		std::cin >> value;
		//sa.setElement(i, value, size);
		sa.push(value, size);
	}
	for (int j = 0; j < size; j++) { sa.printElement(j); }

	smartArray sa1(size1);
	int value1;
	for (int i = 0; i < size1; i++) {
		std::cout << "Please insert value of array" << std::endl;
		std::cin >> value1;
		//sa1.setElement(i, value1, size1);
		sa1.push(value1, size);
	}
	for (int j = 0; j < size1; j++) { sa1.printElement(j); }
	//copyElement(sa, sa1, size, size1);
	sa1 = sa;
	for (int j = 0; j < size1; j++) { sa1.printElement(j); }
	smartArray a1(sa);
	for (int j = 0; j < size1; j++) { a1.printElement(j); }
}

int main()
{
	int s;
	std::cout << "Please insert size of array:" << std::endl;
	std::cin >> s;

	int s1;
	std::cout << "Please insert size of array1:" << std::endl;
	std::cin >> s1;
	create_arr(s,s1);

	return 0;
}