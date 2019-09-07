#include "node.cpp"
class List
{
public:
	List() : head(nullptr) {}
	~List() {}
	//void insert(int index, int val);
	//void remove(int index);
	Node *get_end() const;
	void push(int val);
	int pop();
	int get(int index, int error) const;
	bool set(int index, int val);
private:
	Node *get_ptr(int index) const;
	Node *head;
};

Node *List::get_end() const
{
	if (head == nullptr)
	{
		return nullptr;
	} else {
		Node *p = head;
		while (p->get_next() != nullptr)
		{
			p = p->get_next();
		}
		return p;
	}
}

Node *List::get_ptr(int index) const
{
	Node *p = head;
	while ((index >= 0) && (p != nullptr))
	{
		if (p == nullptr)
			break;
		else
			p = p->get_next();
		index--;
	}
	return p;
}

void List::push(int val)
{
	if (get_end() == nullptr)
	{
		head = new Node(nullptr, nullptr, val);
	} else {
		Node *p = get_end();
		p->set_next(new Node(p, nullptr, val));
	}
}

int List::pop()
{
	Node *p = get_end();
	Node *q = p->get_prev();

	int val = p->get_val();
	delete p;

	q->set_next(nullptr);

	return val;
}

int List::get(int index, int error = 0) const
{
	Node *p = get_ptr(index);
	if (p == nullptr)
	{
		return error;
	} else {
		return p->get_val();
	}
}

bool List::set(int index, int val)
{
	Node *p = get_ptr(index);
	if (p == nullptr)
	{
		return true;
	} else {
		p->set_val(val);
		return false;
	}
}
