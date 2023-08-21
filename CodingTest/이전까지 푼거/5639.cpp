#include <iostream>
#define NULL 0
using namespace std;

template <typename T>
class Tree;
//우선 먼저 선언될 TreeNode를 위해 Treenode에서 사용될 Tree를 먼저 선언한다.
// 이는 나중에 TreeNode선언 이후 동명의 Tree를 통해 오버라이딩될것이다.

template <typename T> // 클래스 선언을 할때 미지의 변수형을 수용할수있도록 선언해주는것이다.
class TreeNode
{
    friend class Tree<T>; //TreeNode는 Tree를 통해 변경이 가능하다고 하는것이다.

private:    // friend 떄문에 Tree를 통해서는 노드 값변경이 가능하지만 이외의 접근은 불가하게한다.
    T data; //이제 data에는 어떤 변수형이 들어가도 상관없다.
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(T data = 0, TreeNode *left = NULL, TreeNode *right = NULL)
    { // 클래스명과 동일한 메소드, 생성자이다.
        //클래스의 새로운 객체가 생성될때 생성자가 실행된다.
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
class Tree
{
private:
    TreeNode<T> *root; //트리의 시작점이다. 객체에서 다이렉트로 수정해야한다.

public:
    Tree(T data = 50)
    {
        root = new TreeNode<T>(data); //Tree의 생성자이다. 최초 노드를 생성하고 시작노드를 root에 저장한다.
    }

    void building_Tree
    { //본격적으로 메소드를 생성한다.
        root->left = new TreeNode<T>(30, new TreeNode<T>(24, new TreeNode<T>(5), new TreeNode(28)), new TreeNode(45));
            root->right = new TreeNode<T>(98, new TreeNode<T>(52, NULL,new TreeNode(60));
    }
//https://jizard.tistory.com/110
}