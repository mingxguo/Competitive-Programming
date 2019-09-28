#include <iostream>
#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>


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
	vector<T> preorder(T vacio) {
		vector<T> pre;
		preorder(root_, pre, vacio);
		return pre;
	}

	bintree<T> operator + (bintree<T> const& that){
		if (empty())
			return that;
		else if (that.empty())
			return *this;
		else{
			return bintree<T>(left() + that.left(), root() + that.root(), right() + that.right());
		}
	}


protected:
	void preorder(Link a, std::vector<T> & pre, T vacio) {
		if (a != nullptr) {
			pre.push_back(a->elem_);
			preorder(a->left_, pre,vacio);
			preorder(a->right_, pre,vacio);
		}
		else pre.push_back(vacio);
	}
};


// lee un ¨¢rbol binario de la entrada est¨¢ndar, dado su preorden
template <class T>
bintree<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un ¨¢rbol vac¨ªo
		return{};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return{ iz, raiz, dr };
	}
}

bool resolve(){
	bintree<int> bt1 = leerArbol(-1), bt2 = leerArbol(-1);
	if (bt1.empty() && bt2.empty())
		return false;
	bintree<int> bt = bt1 + bt2;
	vector<int> v = bt.preorder(-1);
	if (!v.empty())
		cout << v[0];
	for (int i = 1; i < v.size(); ++i)
		cout << ' ' << v[i];
	cout << '\n';
	return true;
}

int main(){
	while (resolve());
	return 0;
}
