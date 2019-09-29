#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Building {
	int id;
	int x, y, w, d, h;
	Building() { }
	Building(int i, int x, int y, int w, int d, int h) : id(i), x(x), y(y), w(w), d(d), h(h) {}
	bool operator <(const Building b) {
		return this->x < b.x || (this->x == b.x && this->y < b.y);
	}
};
vector<Building> buildings;
int n;

bool visible(Building b) {
	vector<Building> cover;
	for (int i = 0; i < n; ++i) {
		//in front of, taller and intersect
		if (buildings[i].y < b.y && buildings[i].x < b.x + b.w && buildings[i].x + buildings[i].w > b.x && buildings[i].h>=b.h) cover.push_back(buildings[i]);
	}
	if (cover.empty()) return true;
	//calculate last covered coordinate
	int last = b.x;
	for (int j = 0; j < cover.size(); ++j) {
		if (cover[j].x > last) return true;
		if (cover[j].x + cover[j].w > last) last = cover[j].x + cover[j].w;
	}
	if (last >= b.x + b.w)return false;
	else return true;
}

int main() {
	int k = 1;
	buildings.clear();
	while (cin >> n && n != 0) {
		printf("For map #%d, the visible buildings are numbered as follows:\n", k);
		//input
		Building b;
		for (int i = 0; i < n; ++i) {
			cin >> b.x >> b.y >> b.w >> b.d >> b.h;
			b.id = i + 1;
			buildings.push_back(b);
		}
		sort(buildings.begin(), buildings.end());

		vector<int> sol;

		for (int i = 0; i < n; ++i) {
			if (visible(buildings[i])) sol.push_back(buildings[i].id);
		}
		if (!sol.empty())cout << sol[0];
		//output
		for (int i = 1; i < sol.size(); ++i) {
			cout << ' ' << sol[i];
		}
		cout << '\n';
		++k;
	}
	return 0;
}