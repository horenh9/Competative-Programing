//q1
/*#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    string str;

    while (1)
    {
        getline(cin, str);
        if (str == "DONE")
            break;
        for (int i = 0, len = str.size(); i < len; i++) {
            if (ispunct(str[i])) {
                str.erase(i--, 1);
                len = str.size();
            }
        }
        for_each(str.begin(), str.end(), [](char &c) {
            c = ::toupper(c);
        });
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
        str.erase(end_pos, str.end());
        int size_line = str.size();
        for (int i = 0; i < size_line/2 + 2; ++i) {
            if(i == size_line/2 + 1)
                printf("You won't be eaten!\n");
            if(str[i]!=str[size_line-1-i]) {
                printf("Uh oh..\n");
                break;
            }
        }
    }
    return 0;
}*/

//q2
/*#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    int tests;
    scanf("%d", &tests);
    for (int i = 0; i < tests; ++i) {
        int num, temp;
        scanf("%d", &num);
        int min = 100, max = 0;
        for (int j = 0; j < num; ++j) {
            scanf("%d", &temp);
            if (temp < min)
                min = temp;
            if (temp > max)
                max = temp;
        }

        cout << (max - min) * 2 << endl;
    }
    return 0;
}*/

//q3
/*#include <iostream>
#include <string>
using namespace std;
int main()
{
	int  H = -1, D, F;
	double U;
	while (1)
	{
		scanf("%d", &H);
		scanf("%lf", &U);
		scanf("%d", &D);
		scanf("%d", &F);
		if (H == 0)
			break;
		double curr = 0;
		double tired = U * (double(F) / 100);
		int days = 0;
		while (curr <= H) {
			days++;
			if (U > 0)
				curr += U;
			if (curr > H) {
				cout << "success on day " << days << endl;
				break;
			}
			curr -= D;
			U -= tired;
			if (curr < 0) {
				cout << "failure on day " << days << endl;
				break;
			}
		}
	}
	return 0;
}*/

//q4
/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;
int main()
{
	vector<string> words;
	vector<string> map;
	string temp;
	while (cin >> temp) {
		if (temp == "#")
			break;
		words.push_back(temp);
	}
	sort(words.begin(), words.end());
	for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
		temp = *it;
		transform(temp.begin(), temp.end(), temp.begin(),
			[](unsigned char c) { return std::tolower(c); });
		sort(temp.begin(), temp.end());
		map.push_back(temp);
	}
	sort(map.begin(), map.end());
	for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
		temp = *it;
		transform(temp.begin(), temp.end(), temp.begin(),
			[](unsigned char c) { return std::tolower(c); });
		sort(temp.begin(), temp.end());
		auto del = std::find(map.begin(), map.end(), temp);
		iter_swap(del, map.end() - 1);
		map.erase(map.end() - 1);
		if (find(map.begin(), map.end(), temp) == map.end())
			cout << *it << endl;
		else {
			map.push_back(temp);
			sort(map.begin(), map.end());
		}
	}
	return 0;
}*/