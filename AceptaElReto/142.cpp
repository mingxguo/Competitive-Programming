#include <iostream>
#include <queue>

using namespace std;

bool resuelve(){
	int n, m;
	cin >> n >> m;
	if (n == 0 && m == 0)
		return false;

	queue<int> q;
	for (int i = 0; i<n; ++i)
		q.push(i+1);

	int i = 0;
	while (q.size() > 1){
		//toca eliminar
		if ((i + 1) % (m + 1) == 0)
			q.pop();
		//se mete al final de la cola para volver a tocar
		else{
			q.push(q.front());
			q.pop();
		}
		++i;
	}
	cout << q.front() << '\n';
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelve());
	return 0;
}