#include "AvlNode.h"
#include<stdexcept>


AvlNode::AvlNode()
{
	Element = height = 0;
	Left = Right = nullptr;
}

void 
AvlNode::MakeEmpty(AvlTree T)
{
	if (T) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Left);
		delete T;
	}
}

Position
AvlNode::Find(int val, AvlTree T)
{
	if (T == nullptr)
		return nullptr;
	else if (val < T->Element)
		return Find(val, T->Left);
	else if (val > T->Element)
		return Find(val, T->Right);
	/* else the value is found */
	else
		return T;
}

Position
AvlNode::FindMin(AvlTree T)
{
	if (T == nullptr)
		throw std::runtime_error("Empty AvlTree");
	else if (T->Left)
		FindMin(T->Left);
	else
		return T;
}

Position
AvlNode::FindMax(AvlTree T)
{
	if (T == nullptr)
		throw std::runtime_error("Empty Avltree");
	else if (T->Right)
		FindMax(T->Right);
	else
		return T;
}

AvlTree
AvlNode::Insert(int val, AvlTree T)
{
	if (T == nullptr) {
		T = new AvlNode();
		if (T == nullptr)
			throw std::runtime_error("Out of space!");
	}
	else if (val < T->Element) {
		T->Left = Insert(val, T->Left);
		if (T->Left->height - T->Right->height == 2)
			if (val < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
	}
	else if (val > T->Element) {
		T->Right = Insert(val, T->Right);
		if (T->Right->height - T->Left->Element == 2)
			if (val > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
	}
	/* Else the value is already in the AvlTree, we'll do nothing */
	T->height = MaxHeight(T->Left, T->Right) + 1;

	return T;
}

AvlTree
AvlNode::Delete(int val, AvlTree T)
{
	if (T == nullptr)
		throw std::runtime_error("Empty AvlTree");
	else if(val < T)
}
