#pragma once

class AvlNode;
typedef AvlNode* Position;
typedef AvlNode* AvlTree;

class AvlNode
{
public://构造函数
	AvlNode();
	~AvlNode() = default;
public://成员操作
	void MakeEmpty(AvlTree T);
	Position Find(int val, AvlTree T);
	Position FindMin(AvlTree T);
	Position FindMax(AvlTree T);
	AvlTree Insert(int val, AvlTree T);
	AvlTree Delete(int val, AvlTree T);
	int get_val() const { return Element; }
	int get_height() const { return height; }
private://私有成员
	int Element;
	int height;
	AvlTree Left;
	AvlTree Right;
private://私有函数
	int Height(Position P) const;
	static int MaxHeight(AvlTree TreeFirst, AvlTree TreeSecond);
	static Position SingleRotateWithLeft(Position P);
	static Position SingleRotateWithRight(Position P);
	static Position DoubleRotateWithLeft(Position P);
	static Position DoubleRotateWithRight(Position P);
};
