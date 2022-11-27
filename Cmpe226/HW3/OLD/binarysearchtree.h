/* CMPE-226 _ HW-3 _ MÇ 19244710068 */
#include <iostream>
#include <cassert>

template <typename T>
struct node{
	T info;
	node<T> *llink,*rlink;
};

template <typename T>
class BinarySearchTree{
	protected:
		node<T> *root;
	private:
		void destroy(node<T> *&p){
			if(p!=NULL){
				destroy(p->llink);
				destroy(p->rlink);
				delete p;
				p=NULL;
			}
		}
		void inordert(node<T> *p){
			if(p != NULL){
				inordert(p->llink);
				std::cout<<p->info.id<<": "<<p->info.firstname<<" "<<p->info.surname<<" - "<<p->info.grade<<" -->\n";
				inordert(p->rlink);
			}
		}
		void preordert(node<T> *p){
			if(p != NULL){
				std::cout<<p->info.id<<": "<<p->info.firstname<<" "<<p->info.surname<<" - "<<p->info.grade<<" -->\n";
				preordert(p->llink);
				preordert(p->rlink);
			}
		}
		void postordert(node<T> *p){
			if(p != NULL){
				postordert(p->llink);
				postordert(p->rlink);
				std::cout<<p->info.id<<": "<<p->info.firstname<<" "<<p->info.surname<<" - "<<p->info.grade<<" -->\n";
			}
		}
		void height(node<T> *p){
			if(p == NULL)
				return 0;
			else
				return 1+max(height(p->llink),height(p->rlink));
		}
		void max(int x, int y){
			if(x>=y) return x;
			else return y;
		}
		void nodecount(node<T> *p){
			if(p==NULL)
			return 0;
			else
			return 1+nodecount(p->llink)+nodecount(p->rlink);
		}
		void leafcount(node<T> *p){
			if(p==NULL)
			return 0;
			else if((p->llink == NULL) && (p->rlink==NULL))
			return 1;
			else
			return leafcount(p->llink)+leafcount(p->rlink);
		}
	public:
		BinarySearchTree(){
			root == NULL;
		}
		~BinarySearchTree(){
			destroy(root);
		}
		bool isEmpty(){
			return root==NULL;
		}
		void inorder(){
			inordert(root);
		}
		void preorder(){
			preordert(root);
		}
		void postorder(){
			postordert(root);
		}
		int treeheight(){
			return height(root);
		}
		int countnodes(){
			return nodecount(root);
		}
		int countleaf(){
			return leafcount(root);
		}
		//insert implementation for binaryTree
		void insert(T &item){
			node<T> *p,*q,*r;
			r = new node<T>;
			
			r->info.grade = item.grade;
			r->info.firstname = item.firstname;
			r->info.surname = item.surname;
			r->info.id = item.id;
			r->llink = r->rlink = NULL;
			
			if(root == NULL) root = r;
			else{
				//checking item
				node<T> *result = search(item);
				if(result != NULL){
					std::cout<<"The insert item is already in the list, duplicates are not allowed."<<item.id<<": "<<item.firstname<<" "<<item.surname<<" - "<<item.grade<<" -->\n\n";
					return;
				}
				
				p=root;
				while(p!=NULL){
					q=p;
					if(item.grade < p->info.grade)
						p=p->llink;
					else
						p=p->rlink;
				}
				if(item.grade < q->info.grade)
					q->llink = r;
				else
					q->rlink = r;
			}
		}
		//search implementation for binaryTree
		node<T> *search(T &item){
			node<T> *p;
			bool found = false;
			if(root == NULL) return NULL;
			else{
				p = root;
				while(p!=NULL && !found){
					if(p->info.grade==item.grade)
						found=true;
					else if(item.grade < p->info.grade){
						p=p->llink;
					}else{
						p=p->rlink;
					}
				}
				if(found)
					return p;
				else
					return NULL;
			}
		}
};
