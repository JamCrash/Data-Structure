#include"AvlNode.h"
#include<stdexcept>

int
AvlNode::MaxHeight(AvlTree TreeOne, AvlTree TreeSecond)
{
	int H1 = Height(TreeOne);
	int H2 = Height(TreeSecond);
	return H1 >= H2 ? H1 : H2;
}

int
AvlNode::Height(Position P)
{
	if (P)
		return P->height;
	else
		return -1;
}

Position
AvlNode::SingleRotateWithLeft(Position P2)
{
	Position P1;

	P1 = P2->Left;
	P2->Left = P1->Right;
	P1->Right = P2;

	P2->height = AvlNode::MaxHeight(P2->Left, P2->Right) + 1;

	P1->height = AvlNode::MaxHeight(P1->Left, P1->Right) + 1;

	return P1;	/* new root */
}

Position
AvlNode::SingleRotateWithRight(Position P2)
{
	Position P1;

	P1 = P2->Right;
	P2->Right = P1->Left;
	P1->Left = P2;

	P2->height = AvlNode::MaxHeight(P2->Left, P2->Right) + 1;

	P1->height = AvlNode::MaxHeight(P1->Left, P1->Right) + 1;

	return P1;	/* new root */
}

Position
AvlNode::DoubleRotateWithLeft(Position P3)
{
	/* Rotate between P1 and P2 */
	P3->Left = SingleRotateWithRight(P3->Left);

	/* Rotate between P2 and P3 */
	return SingleRotateWithLeft(P3);
}

Position
AvlNode::DoubleRotateWithRight(Position P3)
{
	/* Rotate between P1 and P2 */
	P3->Right = SingleRotateWithLeft(P3->Right);

	/* Rotate between P2 and P3 */
	return SingleRotateWithRight(P3);
}

