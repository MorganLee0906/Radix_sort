#include<iostream>
#include<queue>
#include<math.h>
#inc
#define endl '\n'
#define IO cin.tie(nullptr);ios::sync_with_stdio(0);
using namespace std;
struct bucket {
	queue<int> q;
};
int main()
{
	int n;
	while (cin >> n) {
		queue<int> que;
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			que.emplace(tmp);
			if (tmp > max)
				max = tmp;
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
	}
}
