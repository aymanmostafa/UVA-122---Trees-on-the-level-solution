//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// UVA 122 - Trees on the level
	string s;
	vector<pair<string, int>> v;
	map<string, int> m;
	bool res = true;
	while (cin >> s) {
		if (s == "()") {
			int con = 0;
			sort(all(v), [] (pair<string,int> a,pair<string,int> b) {
				if(a.first.size()==b.first.size())
				return a.first<b.first;
				else return a.first.size()<b.first.size();
			});
			for (auto i : v) {
				if (con) {
					if (m[i.first.substr(0, i.first.size() - 1)] > 0)
						m[i.first]++;
					else {
						res = false;
						break;
					}
				} else {
					if (i.first == "")
						m[i.first]++;
					else {
						res = false;
						break;
					}
					++con;
				}
			}
			if (!res)
				cout << "not complete";
			else
				for (int i = 0; i < v.size(); i++) {
					cout << v[i].second;
					if (i != v.size() - 1)
						cout << " ";
				}
			cout << endl;
			m.clear();
			v.clear();
			res = true;
		} else {
			string ss = "", t = "";
			int x;
			bool yea = false;
			for (int i = 1; i < s.size() - 1; i++) {
				if (s[i] == ',') {
					yea = true;
					continue;
				}
				if (yea)
					ss += s[i];
				else
					t += s[i];
			}
			for (int i = 0; i < v.size(); i++)
				if (v[i].first == ss)
					res = false;
			stringstream(t) >> x;
			v.push_back( { ss, x });
		}
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
