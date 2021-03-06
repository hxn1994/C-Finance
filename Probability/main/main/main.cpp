// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "DiscRandVar.h"
#include "DiscRandVar.cpp"


int main()
{
	Uniform P(10);

	cout << P.PMF(0) << endl;

	Binomial bi(2);
	cin >> bi;

	cout << "Show the expected value: \n";
	cout << bi.Exp() << endl;

	Degenerate de(10);
	cin >> de;

	cout << "Show the expected value: \n";
	cout << de.Exp();
	cout << endl;

	cout << de.PMF(cin.get()) << endl;

    return 0;
}

