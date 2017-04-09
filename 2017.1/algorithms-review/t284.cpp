// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
  Iterator * pre;
  Iterator * cur;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
    pre = new Iterator(nums);
    cur = new Iterator(nums);
	}
	int peek() {
    int var = cur->next();
    delete cur;
    cur = new Iterator(*pre);
    return var;
	}
	int next() {
    pre->next();
    return cur->next();
	}
	bool hasNext() const {
    return pre->hasNext();
	}
};
