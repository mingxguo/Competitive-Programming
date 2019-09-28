#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <string>


using namespace std;


template <typename T>
class bintree {
public:
	// ¨¢rbol vac¨ªo
	bintree() : root_(nullptr) {}

	// ¨¢rbol hoja
	bintree(T const& e) :
		root_(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}

	// ¨¢rbol con dos hijos
	bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		root_(std::make_shared<TreeNode>(l.root_, e, r.root_)) {}

	// constructora por copia, operador de asignaci¨®n y destructora por defecto

	// consultar si el ¨¢rbol est¨¢ vac¨ªo
	bool empty() const { return root_ == nullptr; }

	// consultar la ra¨ªz
	T const& root() const {
		if (empty()) throw std::domain_error("El ¨¢rbol vac¨ªo no tiene ra¨ªz.");
		else return root_->elem_;
	}

	// consultar el hijo izquierdo
	bintree<T> left() const {
		if (empty()) throw std::domain_error("El ¨¢rbol vac¨ªo no tiene hijo izquierdo.");
		else return bintree<T>(root_->left_);
	}

	// consultar el hijo derecho
	bintree<T> right() const {
		if (empty()) throw std::domain_error("El ¨¢rbol vac¨ªo no tiene hijo derecho.");
		else return bintree(root_->right_);
	}

protected:
	/*
	Nodo que almacena internamente el elemento (de tipo T),
	y punteros al hijo izquierdo y derecho, que pueden ser
	nullptr si el hijo es vac¨ªo (no existe).
	*/
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r) : left_(l), elem_(e), right_(r) {};
		T elem_;
		Link left_, right_;
	};

	// constructora privada
	bintree(Link const& r) : root_(r) {}

	// puntero a la ra¨ªz del ¨¢rbol
	Link root_;

public:
	vector<T> postorder() {
		std::vector<T> post;
		postorder(root_, post);
		return post;
	}

protected:
	void postorder(Link a, std::vector<T> & post) {
		if (a != nullptr) {
			postorder(a->left_, post);
			postorder(a->right_, post);
			post.push_back(a->elem_);
		}
	}
};

bool operador(char c){
	return c == '+' || c == '-' || c == '/' || c == '*';
}

bintree<char> leerArbol(string const& str, int & i) {
	char c = str[i];
	--i;
	if (operador(c)) {
		auto iz = leerArbol(str, i);
		auto dr = leerArbol(str, i);
		return{ iz, c, dr };
	}
	else {
		return{ c };
	}
}

bool resolve(){

	string str;
	cin >> str;
	if (!cin)
		return false;
	int i = str.size()-1;
	bintree<char> bt = leerArbol(str, i);

	vector<char> v = bt.postorder();
	for (auto c : v) cout << c;
	cout << '\n';
	return true;
}

int main(){
	while (resolve());
	return 0;
}
