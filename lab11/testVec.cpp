#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> readVals();
	void printVals(vector<int> v);

	printVals(readVals());

	return 0;
}

vector<int> readVals()
{
	vector<int> v;
	int num;
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