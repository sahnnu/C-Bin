

#include<type_traits>
#include<memory>
#include<iostream>

class abc {};
template <typename T>
class Node {

public:
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;
	T cdata;


	
    template<typename U = T>
        requires std::is_fundamental_v<U>
    Node()
    {
        std::cout << "Fundamental\n";
    }

    template<typename U = T>
        requires (!std::is_fundamental_v<U>)
    Node()
    {
        std::cout << "Non-fundamental\n";
    }

};
template<typename type>
void add(int value,Node<type>* root)
{
    
    if (root == nullptr)
    {
        std::cout << "Unallocated node" << std::endl;
        Node<type>* temp = new  Node<type>();
        temp->cdata = value;
        root = temp;
        temp = nullptr;
        return;
    }

    if (value > static_cast<type>(root->cdata) && root->right == nullptr)
    {
        Node<type> *temp = new  Node<type>();
        temp->cdata = value;
        temp->left = nullptr;
        temp->right = nullptr;
        root->right.reset(temp);
        temp = nullptr;
       
       
    }

    else if (value < static_cast<type>(root->cdata) && root->left == nullptr)
    {
        Node<type>* temp = new Node<type>();
        temp->cdata = value;
        temp->left = nullptr;
        temp->right = nullptr;
        root->left.reset(temp);
        temp = nullptr;
        
        
    }
    else
    {
        Node<type>* n = root;
       
            if (n->left != nullptr)
                return add(value,n->left.get());
            return add(value,n->right.get());
        
        //return;
        //Traverse the tree

    }
    std::cout << static_cast<type>(root->cdata) << std::endl;
}

int main()
{
	Node<int> root = Node<int>();

	Node<abc> root1 = Node<abc>();
    
    add(5,&root);
    add(15, &root);
    add(25, &root);
    add(35, &root);
    add(05, &root);
    add(45, &root);
    add(55, &root);

   // print(&root);
}

/*template<typename U = T,
         std::enable_if_t<std::is_fundamental_v<U>, int> = 0>
Node();

template<typename U = T,
         std::enable_if_t<!std::is_fundamental_v<U>, int> = 0>
Node();*/