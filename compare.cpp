#include<iostream>
#include<queue>
#include<math.h>
#include<time.h>
#include<algorithm>
#include<random>
#define endl '\n'
#define IO cin.tie(nullptr);ios::sync_with_stdio(0);
using namespace std;
struct bucket {
	queue<int> q;
};
int main()
{
	random_device rd;
	default_random_engine gen = std::default_random_engine(rd());
	uniform_int_distribution<int> dis(0, 1e9 + 7);
	int n;
	while (cin >> n) {
		int array[n];
		for (int i = 0; i < n; i++) {
			array[i] = dis(gen);
		}
		for (int i = 0; i < n; i++) {
			cout << array[i] << ' ';
		}
		cout << endl;
		queue<int> que;
		int max = 0;
		clock_t a, b;
		a = clock();//紀錄開始Radix sort之時間
		for (int i = 0; i < n; i++)
		{
			que.emplace(array[i]);
			if (array[i] > max)
				max = array[i];
		}
		int tmp = 0, cur = 1;
		while (tmp != max)

		{
			tmp = max % int(pow(10, cur));
			cur++;
		}
		bucket bkt[10];
		for (int i = 1; i < cur; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int nownum = que.front();
				que.pop();
				int nowdig = int(nownum / (int(pow(10, i - 1)))) % 10;

				bkt[nowdig].q.emplace(nownum);
			}
			for (int j = 0; j < 10; j++)
			{
				while (bkt[j].q.size())
				{
					que.emplace(bkt[j].q.front());
					bkt[j].q.pop();
				}
			}
		}
		while (que.size() > 1)
		{
			cout << que.front() << ' ';
			que.pop();
		}
		cout << que.front() << endl;
		que.pop();
		b = clock();//記錄完成Radix sort之時間



		//使用Quick sort 排序
		int s[n];
		clock_t e, f;
		e = clock();//記錄開始sort之時間
		for (int i = 0; i < n; i++)
			s[i] = array[i];
		sort(s, s + n);
		for (int i = 0; i < n; i++)
			cout << s[i] << ' ';
		cout << endl;
		f = clock();//記錄完成sort之時間
		clock_t c, d;
		c = clock();
		int arr[n];
		for (int i = 0; i < n; i++)
			arr[i] = array[i];
		bool sort = 0;
		while (sort == 0)
		{
			for (int i = 1; i < n; i++)
			{
				if (arr[i - 1] > arr[i])
				{
					int tmp = 0;
					tmp = arr[i - 1];
					arr[i - 1] = arr[i];
					arr[i] = tmp;
				}
			}
			for (int i = 1; i < n; i++)
			{
				if (arr[i - 1] > arr[i])
				{
					sort = 0;
					break;
				}
				else
					sort = 1;
			}
		}
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << endl;
		d = clock();
		cout << "n = " << n << " Radix sort finished in " << b - a << "ms" << endl;
		cout << "n = " << n << " Quick sort finished in " << f - e << "ms" << endl;
		cout << "n = " << n << " Bubble sort finished in " << d - c << "ms" << endl;
	}
}
