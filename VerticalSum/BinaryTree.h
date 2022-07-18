#pragma once
typedef int BType;
class Node
{
public:
	BType data;
	Node* left, * right;


	Node* GetBinaryNode(BType data)
	{
		Node* bt;
		bt = (Node*)malloc(sizeof(Node));
		if (bt)
		{
			bt->data = data;
			bt->left = NULL;
			bt->right = NULL;
		}

		return bt;
	}

	void Inorder(Node* root)
	{
		if (root != NULL)
		{
			Inorder(root->left);
			std::cout << root->data << "->";
			Inorder(root->right);
		}
	}


};