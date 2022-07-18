#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <map>
#include <vector>
#include "BinaryTree.h"

void SumUntil(Node* root, int HorizontalDistance, std::map<int, int>& map) //map is passed by refference here
{
	//for left Horizontaldistances are -1
	//for right HorizontalDistances are +1 (1 5 6 horizontal distances become 0, so they are added)
	if (root != NULL)
	{

		SumUntil(root->left, HorizontalDistance - 1, map);
		map[HorizontalDistance] += root->data; //add the data for the same horizontal distance
		SumUntil(root->right, HorizontalDistance + 1, map);

	}
}
std::vector<int> verticalSum(Node* root)
{
	//the concept of horizontal distances :)) learned something new
	std::vector<int> answer;
	std::map<int, int> mp;
	SumUntil(root, 0, mp);

	for (auto itr = mp.begin(); itr != mp.end(); itr++)
	{
		answer.push_back(itr->second);
	}

	return answer;
}

int main(void)
{

	Node* root=NULL;
	root = root->GetBinaryNode(1);
	root->right = root->GetBinaryNode(3);
	root->right->right = root->GetBinaryNode(7);
	root->right->left = root->GetBinaryNode(6);
	root->left = root->GetBinaryNode(2);
	root->left->left = root->GetBinaryNode(4);
	root->left->right = root->GetBinaryNode(5);

	root->Inorder(root);
	std::cout << "NULL" << std::endl;

	std::vector<int> answer = verticalSum(root);

	return 0;
}