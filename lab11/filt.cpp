#include <iostream>
#include <vector>
#include <string>

using namespace std;



vector<int> readVals();
void printVals(vector<int> v);
vector<int> valsGT16(vector<int> v);

int main(int argc, char const *argv[])
{


	cout << "vector: ";
	vector<int> orig = readVals();
	printVals(orig);
	cout << "filtered vector: ";
	printVals(valsGT16(orig));
	cout << "original vector: ";
	printVals(orig);


	return 0;
}

vector<int> readVals()
{
	vector<int> v;
	//int num;
	string line;

	// while (cin >> num) 
	// {
	// 	v.push_back(num);
	// }

	while (getline(cin, line, ' ')) 
	{
		v.push_back(stoi(line));
	}
	return v;
}
void printVals(vector<int> v)
{
	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

// returns a vector of values from v that are greater than 0
// these values are in the same relative order as they are in v.
vector<int> valsGT16(vector<int> v) {
	vector<int> vec;
	for (auto i : v) {
		if (i >= 16) {
			vec.push_back(i);
		}
	}
	return vec;
}