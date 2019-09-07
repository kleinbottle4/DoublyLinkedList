class Node
{
public:
	Node(Node *, Node *);
	Node(Node *, Node *, int);
	~Node() {}

	void recursive_delete();
	Node *safe_delete();
	
    void set_val(int val);
    int get_val() const;
    
    void set_next(Node *);
    Node *get_next() const;
    
    void set_prev(Node *);
    Node *get_prev() const;
private:
	int val;
	Node *next;
	Node *prev;
};


Node::Node(Node *prev, Node *next, int val) :
prev(prev), next(next), val(val) {}

void Node::recursive_delete()
{
	if (next != nullptr)
		next->recursive_delete();
	delete this;
}

Node *Node::safe_delete()
{
	Node *p;
	Node *q;
	if (prev == nullptr)
	{
		p = next;
		if (next != nullptr)
			next->prev = nullptr;
	} else {
		p = prev;
		prev->next = next;
		if (next != nullptr)
			next->prev = prev;
	}
	delete this;
	return p;
}

int Node::get_val() const
{
    return val;
}

void Node::set_val(int val)
{
    this->val = val;
}

Node *Node::get_next() const
{
    return next;
}

void Node::set_next(Node *next)
{
    this->next = next;
}

Node *Node::get_prev() const
{
    return prev;
}

void Node::set_prev(Node *prev)
{
    this->prev = prev;
}
