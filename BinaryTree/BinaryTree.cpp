#include<iostream>
#include <queue>
#include<list>
using namespace std;

template <class Type>
class BinaryTree {
private:
	struct Node {
		Node *left, *right;
		Type data;

		Node() :left(NULL), right(NULL) {}
		Node(Type item, Node *L = NULL, Node *R = NULL) :
			data(item), left(L), right(R) {}
		~Node() {}
	};
	Node *root;
public:
	BinaryTree() :root(NULL) {}
	BinaryTree(const Type&value) { root = new Node(value); }
	BinaryTree(const Node *p) { root = p; }
	~BinaryTree() { clear(); }
	Type getRoot() const { return root->data; }
	Type getLeft() const { return root->left->data; }
	Type getRight() const { return root->right->data; }

	void makeTree(const Type &x, BinaryTree &lt, BinaryTree &rt) {
		root = new Node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}
	void delLeft() {
		BinaryTree tmp = root->left;
		root->left = NULL;
		tmp.clear();
	}
	void delRight() {
		BinaryTree tmp = root->right;
		root->right = NULL;
		tmp.clear();
	}
	bool isEmpty() const {
		return root == NULL;
	}
	void clear(){
		if (root != NULL) clear(root); root = NULL;
	}
	int size() const { return size(root); }
	int height() const { return height(root); }

	void preOrder() const {
		if (root != NULL) {
			cout << "\n Pre Order:";
			preOrder(root);
		}
	}

	void midOrder() const {
		if (root != NULL) {
			cout << "\n Mid Order:";
			midOrder(root);
		}
	}

	void postOrder() const {
		if (root != NULL) {
			cout << "\n Post Order:";
			postOrder(root);
		}
	}
	void layerOrder() const {
		if (root != NULL) {
			cout << "\n Layer Order:";
			layerOrder(root);
		}
	}
	void createTree(Type flag);
	
	void isComplete() const {
		if (root != NULL) {
			cout << "\nIs Complete?1 for yes,0 for no:";
			cout<<isComplete(root);
		}
	}

private:
	int height(Node *t) const {
		if (t == NULL) return 0;
		else {
			int lt = height(t->left), rt = height(t->right);
			return 1 + ((lt > rt) ? lt : rt);
		}
	}
	void clear(Node*t) {
		if (t->left != NULL)
			clear(t->left);
		if (t->right != NULL) clear(t->right);
		delete(t);
	}

	int size(Node* t) const {
		if (t == NULL)return 0;
		return 1 + size(t->left) + size(t->right);
	}

	void preOrder(Node *t) const {
		if (t != NULL) {
			cout << t->data << ' ';
			preOrder(t->left);
			preOrder(t->right);
		}
	}
	void midOrder(Node*t) const {
		if (t != NULL) {
			midOrder(t->left);
			cout << t->data << ' ';
			midOrder(t->right);
		}
	}

	void postOrder(Node *t) const {
		if (t != NULL) {
			postOrder(t->left);
			postOrder(t->right);
			cout << t->data << ' ';
		}
	}
	
	void layerOrder(Node *t) const {

		queue<Node *> que;
		Node *tmp;
		que.push(t);
		while (!que.empty()) {
			tmp = que.front();
			que.pop();
			cout << tmp->data<<' ';
			if (tmp->left != NULL) que.push(tmp->left);
			if (tmp->right != NULL) que.push(tmp->right);
		}
	}

	bool isComplete(Node * t) const {
		queue<Node*> q;
		Node  *ptr;
		q.push(root);
		while ((ptr = q.front()) != NULL){
			q.pop();
			q.push(ptr->left);
			q.push(ptr->right);
		}
		while (!q.empty()){
			ptr = q.front();
			q.pop();
			if (NULL != ptr){
				return false;
			}
		}

		return true;
	}
	


};

template <class Type>
void BinaryTree<Type> ::createTree(Type flag) {
	Node *tmp;
	Type x, ldata, rdata;
	queue< Node *> q1;

	cout << "\n Input root node:";
	cin >> x;
	root = new Node(x);

	q1.push(root);
	while (!q1.empty()) {
		tmp = q1.front();
		q1.pop();
		cout << "\n Input" << tmp->data << "\'s sons(" << flag << " represents NULL node):";
		cin >> ldata >> rdata;
		if (ldata != flag) q1.push(tmp->left = new Node(ldata));
		if (rdata != flag) q1.push(tmp->right = new Node(rdata));
	}
	cout << "Creation done.\n";


}


int main() {
	BinaryTree <char> tree, tree1('M'), tree2;

	tree.createTree('@');

	cout << "The height is:" << tree.height() << endl;
	cout << "The size is:" << tree.size() << endl;
	tree.preOrder();
	tree.midOrder();
	tree.postOrder();
	tree.layerOrder();
	tree.isComplete();
	system("pause");
	return 0;
}