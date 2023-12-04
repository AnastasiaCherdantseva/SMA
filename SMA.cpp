#include <iostream>
#include <deque>
#include <iterator>
#include <time.h>


using namespace std;

template<class T>
void algSMA(deque<T>& p, deque<T>& SMA, const int k)
{	
	for (int i = 0; i < k-1; i++)
	{
		SMA.push_back(0);
	}
	for (int n = k-1,i=0; n < p.size(); n++,i++)
	{
		T summ = 0;
		auto it = next(p.begin(), i);
		for (int j = 0;j<k; it++,j++)
		{
			summ += *it;
		}
		SMA.push_back(summ/T(k));
	}
}


int main()
{
	deque<double> p;
	deque<double> pSMA;
	int k = 8;
	cout << "LIST" << endl;
	for (int i = 0; i < 1000000; i++)
	{
		p.push_back(double(rand() % 100000) / double(rand() % 100+1));
	}
	algSMA(p, pSMA, k);

	cout << clock() / double(CLOCKS_PER_SEC);
}
