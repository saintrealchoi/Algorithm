void RedBlackTree::reconstructionAfterDeletion(Node* child, Node* parent)
{
	while (nullptr != parent)
	{
		bool left = parent->_left == child;
		Node* sibling = left ? parent->_right : parent->_left;
		if (RED == parent->_color)
		{
			if (BLACK == sibling->_left->_color && BLACK == sibling->_right->_color)
			{
				// case 1
				// parent : red, sibling : black, sibling left : black, sibling right : black
				sibling->_color = RED;
				parent->_color = BLACK;
				break;
			}
		}
		else if (BLACK == sibling->_left->_color && BLACK == sibling->_right->_color)
		{
			if (BLACK == sibling->_color)
			{
				// case 4
				// parent : black, sibling : black, sibling left : black, sibling right : black
				sibling->_color = RED;
				child = parent;
				parent = parent->_parent;
				continue;
			}
			else // RED == sibling->_color
			{
				// case 5
				// parent : black, sibling : red, sibling left : black, sibling right : black
				parent->_color = RED;
				sibling->_color = BLACK;
				if (left)
				{
					leftRotate(parent);
					sibling = parent->_right;
				}
				else
				{
					rightRotate(parent);
					sibling = parent->_left;
				}
				continue;
			}
		}

		if (BLACK == sibling->_color &&
			((left && RED == sibling->_left->_color && BLACK == sibling->_right->_color)
				|| (!left && BLACK == sibling->_left->_color && RED == sibling->_right->_color)))
		{
			// case 3
			// parent : all, sibling : black, sibling left : red, sibling right : black
			if (left)
			{
				rightRotate(sibling);
				parent->_right->_color = BLACK;
				parent->_right->_right->_color = RED;
				sibling = parent->_right;
			}
			else
			{
				leftRotate(sibling);
				parent->_left->_color = BLACK;
				parent->_left->_left->_color = RED;
				sibling->_parent->_left;
			}
		}

		if (BLACK == sibling->_color && ((left && RED == sibling->_right->_color) || (!left && RED == sibling->_left->_color)))
		{
			// case 2
			// parent : all, sibling : black, sibling left : all, sibling right : red
			left ? leftRotate(parent) : rightRotate(parent);
			NODE_COLOR temp = parent->_color;
			parent->_color = sibling->_color;
			sibling->_color = temp;
			left ? sibling->_right->_color = BLACK : sibling->_left->_color = BLACK;
			break;
		}
	}
}