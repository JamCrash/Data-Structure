#include "AvlNode.h"
#include<stdexcept>
#include<iostream>


AvlNode::AvlNode()
{
	Element = height = 0;
	Left = Right = nullptr;
}

void 
AvlNode::MakeEmpty(AvlTree& T)
{
	if (T) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Left);
		delete T;
	}
}

Position
AvlNode::Find(int val, AvlTree& T)
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
AvlNode::FindMin(AvlTree& T)
{
	if (T)
		if (T->Left)
			return FindMin(T->Left);
		else
			return T;
	return nullptr;
}

Position
AvlNode::FindMax(AvlTree& T)
{
	if (T)
		if (T->Right)
			return FindMax(T->Right);
		else
			return T;
	return nullptr;
}

AvlTree
AvlNode::Insert(int val, AvlTree& T)
{
	if (T == nullptr) {
		T = new AvlNode();
		if (T == nullptr)
			throw std::runtime_error("Out of space!");
		else {
			T->Element = val; T->height = 0;
			T->Left = T->Right = nullptr;
		}
	}
	else if (val < T->Element) {
		T->Left = Insert(val, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
			if (val < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
	}
	else if (val > T->Element) {
		T->Right = Insert(val, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
			if (val > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
	}
	/* Else the value is already in the AvlTree, we'll do nothing */
	T->height = MaxHeight(T->Left, T->Right) + 1;

	return T;
}

void
AvlNode::Delete(int val, AvlTree& T)
{
	if (T == nullptr)
		throw std::runtime_error("The value is not exist");
	if (val < T->Element) {
		Delete(val, T->Left);
		T->height = MaxHeight(T->Left, T->Right) + 1;
		if (Height(T->Right) - Height(T->Left) == 2)
			T = SingleRotateWithRight(T);
	}
	else if (val > T->Element) {
		Delete(val, T->Right);
		T->height = MaxHeight(T->Left, T->Right) + 1;
		if (Height(T->Left) - Height(T->Right) == 2)
			T = SingleRotateWithLeft(T);
	}
	/* Else T->Element == val, then we'll delete it */
	else {
		if (T->Left && T->Right) {
			Position TmpCell;

			if (Height(T->Left) == Height(T->Right)) {
				TmpCell = FindMax(T->Left);
				T->Element = TmpCell->Element;
				Delete(T->Element, T->Left);
			}
			else {
				if (Height(T->Left) > Height(T->Right)) {
					TmpCell = FindMax(T->Left);
					T->Element = TmpCell->Element;
					Delete(T->Element, T->Left);
				}
				else {
					TmpCell = FindMin(T->Right);
					T->Element = TmpCell->Element;
					Delete(T->Element, T->Right);
				}
				T->height -= 1;
			}
		}
		else if (T->Left || T->Right) {
			Position TmpCell;

			if (T->Left) {
				TmpCell = T->Left;
				T->Element = TmpCell->Element;
				T->height = 0;
				T->Left = nullptr;
			}
			else {
				TmpCell = T->Right;
				T->Element = TmpCell->Element;
				T->height = 0;
				T->Right = nullptr;
			}
			delete TmpCell;
		}
		else {
			delete T;
			T = nullptr;
		}	
	}
}

void
Preorder_Traversal(const AvlTree T)
{
	if (T != nullptr) {
		std::cout << T->Element << " ";
		Preorder_Traversal(T->Left);
		Preorder_Traversal(T->Right);
	}
}
