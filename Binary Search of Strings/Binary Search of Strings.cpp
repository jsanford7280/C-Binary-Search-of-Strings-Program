#include <iostream>
#include <vector>
using namespace std;

void SSort(vector<string>& input) {
	int n = input.size();
	//Move boundary of unsorted sub part one by one
	for (int i = 0; i < n - 1; i++) {
		//Find the smallest element in the unsorted vector
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (input[j] < input[min_idx])
				min_idx = j;
		//Change the smallest element found with the first element
		string t = input[min_idx];
		input[min_idx] = input[i];
		input[i] = t;
	}
}


int BS(vector<string> input, string x) {

	int left = 0, right = input.size() - 1;
	while (left <= right) {
		int m = left + (right - left) / 2;

		//Verify if x is present in mid
		if (input[m] == x)
			return m;

		//If x is greater, then ignore left half  
		if (input[m] < x)
			left = m + 1;

		//If x is smaller, then ignore right half
		else
			right = m - 1;
	}

	//If we are here, then, the element was not present
	return -1;
}

/* Function to print a vector */
void print(vector<string> input) {
	for (int i = 0; i < input.size(); i++)
		cout << input[i] << endl;
}


//Program to test the above functions
int main()
{
	vector<string> input;
	input.push_back("hello");
	input.push_back("it");
	input.push_back("is");
	input.push_back("fun");
	input.push_back("to");
	input.push_back("code");
	input.push_back("strings");
	input.push_back("and");
	input.push_back("search");
	SSort(input);
	cout << "Vector Sorted: \n";
	print(input);
	while (true) {
		string key;
		cout << "Enter a string from above to search: (type quit to exit)";
		cin >> key;
		if (key == "quit") {
			break;
		}
		int index = BS(input, key);

		if (index == -1)
			cout << key << " This is not in the vector" << endl;
		else
			cout << key << " The location is at " << index << " in the vector" << endl;
	}
	return 0;
}
