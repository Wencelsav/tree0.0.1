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
			if (this->value > value) {
				if (this->left != nullptr) {
					this->left->insertrec(value);
				}
				else {
					this->left = new node_t();
					this->left->value = value;
				}
			}
			if (this->value < value) {
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
		bool findrec(int value) const {
			if (this->value > value) {
				if (this->left != nullptr) {
					return this->left->findrec(value);
				}
				return false;
			}
			if (this->value < value) {
				if (this->right != nullptr) {
					return this->right->findrec(value);
				}
				return false;
			}
			if (this->value == value) {
				return true;
			}
			 

		}
	};
private:
	node_t * root_;
	
public:
	tree_t() {
		root_ = nullptr;
	}
	~tree_t() {
		delete root_;
	}
	void insert(int value);
	bool find(int value) const;
	void print(std::ostream & stream) const ;
};
void tree_t::insert(int value) {
	if (root_ == nullptr) {
		root_ = new node_t;
		return;
		
	}
	root_->insertrec( value);
	return;
}
void tree_t::print(std::ostream & stream) const {
	
	root_->printrec(stream,0);
	return;
}
bool tree_t::find(int value) const {
	if (root_ != nullptr) {
		return root_->findrec(value);
	}
	return false;
}

int main()
{
	tree_t tree ;
	tree.insert(0);
	tree.insert(8);
	tree.insert(9);
	tree.insert(3);
	tree.insert(7);
	std::cout << tree.find(7)<<'\n';
	std::cout << tree.find(6)<<'\n';
	tree.print(std::cout);
	system("pause");
    return 0;
}

