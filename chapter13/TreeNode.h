#include<string>
class TreeNode;
class BinStrTree{
private:
	TreeNode *root;
public:
	BinStrTree():root(nullptr){}
	BinStrTree(const BinStrTree &bt);
	BinStrTree &operator=(const BinStrTree &bt);
	~BinStrTree();
}
class TreeNode{
	friend void swap(TreeNode &,TreeNode &);
private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
public:
	TreeNode(const std::string &s = string("non-element")):value(s),count(1),left(nullptr),right(nullptr){}
	TreeNode(const TreeNode &tn);
	TreeNode &operator=(const TreeNode &tn);
	~TreeNode();
};
BinStrTree::BinStrTree(const BinStrTree &bt){
	if(bt.root)
		root=new TreeNode(*bt.root);
	else
		root=nullptr;
}
BinStrTree &BinStrTree::operator=(const BinStrTree &bt){
	if(bt.root&&root){
		auto rt=new TreeNode(*bt.root);
		delete root;
		root=rt;
	}else if(!bt.root&&root){
		delete root;
		root =nullptr;
	}else if(bt.root&&!root)
		root=new TreeNode(*bt.root);
	return *this;
}
~BinStrTree::BinStrTree(){
	if(root)
		delete root;
}
	
void swap(TreeNode &tn1,TreeNode &tn2){
	using std::swap;
	swap(tn1.value,tn2.value);
	swap(tn1.count,tn2.count);
	swap(tn1.left,tn2.left);
	swap(tn1.right,tn2.right);
}
TreeNode::TreeNode(const TreeNode &tn):value(tn.value),count(tn.count){
	if(tn.left)
		left=new TreeNode(*tn.left);
	else
		left=nullptr;
	if(tn.right)
		right=new TreeNode(*tn.right);
	else
		right=nullptr;
}
TreeNode &TreeNode::operator=(const TreeNode &tn){
	if(tn.left&&left){
		auto lt=new TreeNode(*tn.left);
		delete left;
		left=lt;
	}else if(!tn.left&&left){
		delete left;
		left=nullptr;
	}else if(tn.left&&!left)
		left=new TreeNode(*tn.left);
	
	if(tn.right&&right){
		auto lt=new TreeNode(*tn.right);
		delete right;
		right=lt;
	}else if(!tn.right&&right){
		delete right;
		right=nullptr;
	}else if(tn.right&&!right)
		right=new TreeNode(*tn.right);
	
	value=tn.value;
	count=tn.count;
	return *this;
}

~TreeNode::TreeNode(){
	if(left)
		delete left;
	if(right)
		delete right;
}