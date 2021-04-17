//q1 bits shit
/*#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int tests, N, Q;
	scanf("%d", &tests);
	for (size_t i = 0; i < tests; i++) {
		vector<int> values;
		scanf("%d", &N);
		scanf("%d", &Q);
		int temp;
		for (size_t j = 0; j < N; j++) {
			scanf("%d", &temp);
			values.push_back(temp % 256);
		}
		for (size_t j = 0; j < Q; j++) {
			scanf("%d", &temp);
			int max = 0;
			for (size_t k = 0; k < N; k++) {
				if (max < temp & values[k])
					max = temp & values[k];
				if (max == temp)
					break;
			}
			cout << max << endl;
		}
	}
}*/

//q2 multiset
/*#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int tests, num_adds, num_gets;
	scanf("%d", &tests);
	for (size_t i = 0; i < tests; i++) {
		multiset<int> ms;
		multiset<int>::iterator msIt;
		ms.insert(2000000001);
		int  gets = 0;
		vector<int> num_to_add;
		int currget;
		scanf("%d", &num_adds);
		scanf("%d", &num_gets);
		for (size_t j = 0; j < num_adds; j++) {
			scanf("%d", &currget);
			num_to_add.push_back(currget);
		}
		int k = 0;
		msIt = ms.begin();
		for (size_t j = 0; j < num_gets; j++) {
			scanf("%d", &currget);
			for (; k < currget; k++) {
				ms.insert(num_to_add[k]);
				if (num_to_add[k] < *msIt)
					--msIt;
			}
			cout << *msIt << endl;
			gets++;
			++msIt;
		}
		if (i < tests - 1)
			cout << endl;
	}
}*/

//q3 min heap
/*#include <cstdio>
#include <queue>
using namespace std;
#define MAXN 100009
#include <iostream>
typedef long long ll;

ll huffman(ll* a, ll n) {
	ll ans = 0, u, v;
	priority_queue<ll> pq;
	for (ll i = 0; i < n; i++)
		pq.push(-a[i]);
	while (pq.size() != 1) {
		u = pq.top();
		pq.pop();
		v = pq.top();
		pq.pop();
		pq.push(u + v);
		ans -= (u + v);
	}
	return ans;
}

int main()
{
	ll T, N;
	cin >> T;
	for (ll j = 0; j < T; j++)
	{
		ll a[MAXN];
		cin >> N;
		for (ll i = 0; i < N; i++)
			cin >> a[i];
		cout << huffman(a, N);
		if (j < T - 1) {
			cout << endl;
		}
	}
	return 0;
}*/

//q4 union-find
/*#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct unionfind
{
	vector<int> rank;
	vector<int> parent;
	unionfind(int size)
	{
		rank = vector<int>(size, 1);
		parent = vector<int>(size);
		for (int i = 0; i < size; i++)
			parent[i] = i;
	}

	int find(int x) {
		int tmp = x;
		while (x != parent[x]) x = parent[x];
		while (tmp != x)//for log*, not needed most of the time
		{
			int remember = parent[tmp];
			parent[tmp] = x;
			tmp = remember;
		}
		return x;
	}
	void Union(int p, int q) {
		p = find(p);
		q = find(q);
		if (q == p)
			return;
		if (rank[p] < rank[q]) {
			parent[p] = q;
			rank[q] += rank[p];
		}
		else {
			parent[q] = p;
			rank[p] += rank[q];
		}
		//if (rank[p] == rank[q])
			//rank[p]++;
	}
};

int main()
{
	int tests, friendships;
	scanf("%d", &tests);
	for (size_t i = 0; i < tests; i++) {
		scanf("%d", &friendships);
		unionfind uf(friendships * 2);
		map<string, int> map1;
		string friend1, friend2;
		for (size_t j = 0; j < friendships * 2; j += 2) {
			cin >> friend1;
			cin >> friend2;
			if (map1[friend1] == 0)
				map1[friend1] = j + 1;
			if (map1[friend2] == 0)
				map1[friend2] = j + 2;
			uf.Union(map1[friend1]-1, map1[friend2]-1);
			int max;
			if (uf.rank[map1[friend1]-1] > uf.rank[map1[friend2]-1])
				max = uf.rank[uf.find(map1[friend1]-1)];
			else
				max = uf.rank[uf.find(map1[friend2]-1)];
			cout << max << endl;
		}
		if (i < tests - 1)
			cout << endl;
	}
}*/
