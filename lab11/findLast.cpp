#include <iostream>
#include <vector>
#include <string>

using namespace std;



vector<int> readVals();
void printVals(vector<int> v);
vector<int> valsGT16(vector<int> v);
int findLast(vector<int> v, int target);

int main(int argc, char const *argv[])
{

	vector<int> orig = readVals();
	cout << "vector: ";
	printVals(orig);
	cout << "filtered vector: ";
	printVals(valsGT16(orig));
	cout << "original vector: ";
	printVals(orig);
	cout << "The index of last 13 is "<< findLast(orig, 13) << endl;
	cout << "The index of last 19 is "<< findLast(orig, 19) << endl;
	cout << "The index of last 50 is "<< findLast(orig, 50) << endl;

	return 0;
}

vector<int> readVals()
{
	vector<int> v;
	int num;
	//string line;

	cin >> num;
	while (!cin.fail()) {
		v.push_back(num);
		cin >> num;
	}

	// while (getline(cin, line, ' ')) {
	// 	v.push_back(stoi(line));
	// }
	return v;
}
void printVals(vector<int> v){

	for (vector<int>::size_type i = 0; i < v.size(); i++){
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

int findLast(vector<int> v, int target) {
	int start = 0, end = v.size()-1, mid;
	while (start + 1 < end) {
		mid = (start + end) / 2;
		if (v[mid] <= target) {
			start = mid;
		}else {
			end = mid;
		}
	}
	if (v[end] == target) {
		return end;
	}
	if (v[start] == target) {
		return start;
	}
	return -1;
}