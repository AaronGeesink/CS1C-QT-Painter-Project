#ifndef VECTOR_H
#define VECTOR_H

#endif // VECTOR_H
// vector.h - class specification
// a vector which approximates the stl vector

template<class T>
class vector
{
private:
	int size_v; // the size
	T* elem; // a pointer to the elements
	int space; // size+free_space

public:
	vector(); // default constructor
	explicit vector(int s); // alternate constructor
	vector(const vector&); // copy constructor
	vector& operator=(const vector&); // copy assignment
	vector(const vector&&); // move constructor
	vector& operator=(const vector&&); // move assignment
	~vector(); // destructor
	T& operator[] (int n); // access: return reference

	//next function seems deprecated. will ask Kath about it.
	//const T& operator[] (int n); // access: return reference

	int size() const; // the current size
	int capacity() const; // current available space
	void resize(int newsize); // grow
	void push_back(T val); // add element
	void reserve(int newalloc); // get more space

	using iterator = T*;
	using const_iterator = const T*;
	iterator begin(); // points to first element
	const_iterator begin() const;
	iterator end(); // points to one beyond the last element
	const_iterator end() const;
	iterator insert(iterator p, const T& v);// insert a new element v before p
	iterator erase(iterator p); // remove element pointed to by p
};
