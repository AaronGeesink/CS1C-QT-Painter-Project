#ifndef VECTOR_H
#define VECTOR_H

// vector.h - class specification
// a vector which approximates the stl vector

template<class T>
class vector
{
private:
    int size_v; // the size
    int space; // size + free_space
    T* elem; // a pointer to the elements

public:
    vector(); // default constructor
    explicit vector(int s); // alternate constructor
    vector(const vector& source); // copy constructor
    vector& operator=(const vector& source); // copy assignment
    vector(const vector&&source); // move constructor
    vector& operator=(const vector&& source); // move assignment
    ~vector(); // destructor
    T& operator[] (int n); // access: return reference

    //next function seems deprecated. will ask Kath about it.
    // const T& operator[] (int n); // access: return reference

    int size() const; // the current size
    int capacity() const; // current available space
    void resize(int newsize); // grow
    void push_back(T val); // add element
    void reserve(int newalloc); // get more space

    using iterator = T * ;
    using const_iterator = const T*;
    iterator begin(); // points to first element
    const_iterator begin() const;
    iterator end(); // points to one beyond the last element
    const_iterator end() const;
    iterator insert(iterator p, const T& v);// insert a new element v before p
    iterator erase(iterator p); // remove element pointed to by p
};

#endif // VECTOR_H

// Default constructor
template<class T>
inline vector<T>::vector() : size_v{ 0 }, space{ 0 }, elem{new T[0]}
{}

// Overloaded constructor
template<class T>
inline vector<T>::vector(int s) : size_v{ s }, space{ s }, elem{ new T[s] }
{}

// Copy constructor
template<class T>
inline vector<T>::vector(const vector & source) : size_v{ source.size_v }, space{ source.space }, elem{ new T[source.space] }
{
    // Copy over values
    for (int i = 0; i < source.size; i++)
    {
        elem[i] = source.elem[i];
    }
}

// Copy assignment
template<class T>
inline vector<T> & vector<T>::operator=(const vector & source)
{
    space = source.space;
    size_v = source.size_v;
    delete[] elem;
    elem = new T[space];

    // Copy over values
    for (int i = 0; i < source.size; i++)
    {
        elem[i] = source.elem[i];
    }
    return *this;
}

// Move constructor
template<class T>
inline vector<T>::vector(const vector && source) : size_v{source.size_v}, space{source.space}, elem{source.elem}
{
    source.elem = nullptr;
    source.size_v = 0;
    source.space = 0;
}

// Move assignment
template<class T>
inline vector<T> & vector<T>::operator=(const vector && source)
{
    delete[] elem;
    elem = source.elem;
    size_v = source.size_v;
    space = source.space;

    source.elem = nullptr;
    source.size_v = 0;
    source.space = 0;
    return *this;
}

// Destructor
template<class T>
inline vector<T>::~vector()
{
    delete [] elem;
}

template<class T>
inline T & vector<T>::operator[](int n)
{
    // TODO: insert return statement here
}

template<class T>
inline int vector<T>::size() const
{
    return 0;
}

template<class T>
inline int vector<T>::capacity() const
{
    return 0;
}

template<class T>
inline void vector<T>::resize(int newsize)
{
}

template<class T>
inline void vector<T>::push_back(T val)
{
}

template<class T>
inline void vector<T>::reserve(int newalloc)
{
}
