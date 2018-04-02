// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
class tree_t
{
private:
	
	struct node_t {
		node_t * left;
		node_t * right;
		int value;
		node_t() {
			left = nullptr;
			right = nullptr;
			value = 0;

	    }
		~node_t() {
			if (left != nullptr) {
				delete left;
			}
			if (right != nullptr) {
				delete right;
			}

		}
		void insertrec(int value) {
			if (this->value < value) {
				if (this->left != nullptr) {
					this->left->insertrec(value);
				}
				else {
					this->left = new node_t();
					this->left->value = value;
				}
			}
			if (this->value > this->value) {
				if (this->right != nullptr) {
					this->right->insertrec( value);
				}
				else {
					this->right = new node_t();
					this->right->value = value;
				}
			}
			return;
		}
		void printrec(std::ostream & stream,int minus_num) const  {
			
			if (this->right != nullptr) {
				this->right->printrec(stream,minus_num+4);
			}
			for (int i = 0; i < minus_num+4; i++) {
				stream << '-';
			}
			stream << value<< '\n';
			if (this->left != nullptr) {
				this->left->printrec(stream,minus_num+4);
			}
		
			return;
		}
	};
private:
	node_t * root_;
	
public:
	tree_t() {
		root_ = new node_t();
	}
	~tree_t() {
		delete root_;
	}
	void insert(int value);
	bool find(int value) const;
	void print(std::ostream & stream) const ;
};
void tree_t::insert(int value) {
	if (root_ == 0) {
		root_->value = value;
		return;
	}
	root_->insertrec( value);
	return;
}
void tree_t::print(std::ostream & stream) const {
	root_->printrec(stream,0);
	return;
}

int main()
{
	tree_t tree ;
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.print(std::cout);
	system("pause");
    return 0;
}

