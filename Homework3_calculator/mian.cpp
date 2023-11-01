#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Header.h"

using namespace std;

int main()
{
	//string infixExpression = "3.1 * ( 1.2 + 3.5 )";
	//queue<string> postfixExpression = ConvertToPostfix(infixExpression);
	///*while (!postfixExpression.empty())
	//{ 
	//	string c = postfixExpression.front();
	//	cout << c << ' ';
	//	postfixExpression.pop();
	//}*/
	//double ans = calculatePostfix(postfixExpression);
	//cout << ans << endl;
	

	ifstream inputFile("input.txt");
	if (!inputFile.is_open())
	{
		cout << "Cannot open the file." << endl;
		return 1;
	}

	ofstream outputFile("output.txt");

	string inputExpression;

	while (getline(inputFile, inputExpression))
	{
		try
		{
			queue<string> postfixExpression = ConvertToPostfix(inputExpression);
			double ans = calculatePostfix(postfixExpression);
			outputFile << "The answer is :" << ans << endl;
		}
		catch(const exception& e)
		{
			outputFile << "Error." << e.what() << endl;
		}

		inputFile.clear();
	
	}
	
	inputFile.close();
	outputFile.close();
	return 0;
}
