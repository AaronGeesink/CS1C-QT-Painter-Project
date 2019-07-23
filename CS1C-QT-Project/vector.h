#ifndef VECTOR_H
#define VECTOR_H

// vector.h - class specification
// a vector which approximates the stl vector

//! vector class
/*!
  An array-based vector which approximates the STL vector. The size of the array increases in size as needed when data is added
*/

#include <algorithm>
using std::move;
using std::swap;
using std::exit;

namespace project
{

template<class T>
class vector
{
private:
    int size_v; // the size
    int space; // size + free_space
    T* elem; // a pointer to the elements

public:
    //! vector class default constructor
    /*!
      Initializes an empty vector class object with size_v = 0, space = 0, and elem = new T[0]
    */
    vector(); // default constructor

    //! vector class destructor
    /*!

    */
    ~vector(); // destructor

    //! vector class alternate constructor
    /*!
      \param s an integer amount
      Initializes an empty vector class object with size_v = s, space = 0, and elem = new T[s]
    */
    explicit vector(int s); // alternate constructor

    //! vector class copy constructor
    /*!
      \param source a vector vector argument
      Initializes a vector class object as a copy of source
    */
    vector(const vector& source); // copy constructor

    //! vector class copy assignment
    /*!
      Deletes the existing data in the invoking vector and then copies over all data from the source vector to the invoking vector
    */
    vector& operator=(const vector& source); // copy assignment

    //! vector class move constructor
    /*!

    */
    vector(const vector&&source); // move constructor

    //! vector class move assignment
    /*!

    */
    vector& operator=(const vector&& source); // move assignment

    //! Overloaded vector subscript operator []
    /*!

    */
    T& operator[] (int n); // access: return reference

    //! Overloaded const vector subscript operator []
    /*!

    */
    const T& operator[] (int n) const; // access: const return reference

    int size() const; // the current size
    int capacity() const; // current available space
    void resize(int newsize); // grow
    void push_back(T val); // add element
    void reserve(int newalloc); // get more space

    using iterator = T * ;
    using const_iterator = const T *;
    iterator begin(); // points to first element
    const_iterator begin() const;
    iterator end(); // points to one beyond the last element
    const_iterator end() const;
    iterator insert(iterator p, const T& v);// insert a new element v before p
    iterator erase(iterator p); // remove element pointed to by p
};

// Default constructor
template<class T>
inline vector<T>::vector() : size_v{ 0 }, space{ 0 }, elem{new T[0]}
{}

// Destructor
template<class T>
inline vector<T>::~vector()
{
    delete [] elem;
}

// Overloaded constructor
template<class T>
inline vector<T>::vector(int s) : size_v{ 0 }, space{ s }, elem{ new T[s] }
{}

// Copy constructor
template<class T>
inline vector<T>::vector(const vector & source) : size_v{ source.size_v }, space{ source.space }, elem{ new T[source.space] }
{
    // Copy over values
    for (int i = 0; i < source.size_v; i++)
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
    T * pT = new T[space];

    // Copy over values
    for (int i = 0; i < source.size_v; i++)
    {
        elem[i] = source.elem[i];
    }
    delete[] elem;
    elem = pT;

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

// Access return reference
template<class T>
inline T & vector<T>::operator[](int n)
{
    return elem[n];
}

// Const access return reference
template<class T>
inline const T & vector<T>::operator[](int n) const
{
    return elem[n];
}

template<class T>
inline int vector<T>::size() const
{
    return size_v;
}

template<class T>
inline int vector<T>::capacity() const
{
    return space;
}

// We should probably test this one to be sure
template<class T>
inline void vector<T>::resize(int newsize)
{
    if (newsize == 0)
        newsize = 1;

    T * Tptr = new T[newsize];

    if (newsize < size_v)
        size_v = newsize;

    for (int i = 0; i < newsize; i++)
        Tptr[i] = elem[i];

    space = newsize;

    delete[] elem;
    swap(elem, Tptr);
}

template<class T>
inline void vector<T>::push_back(T val)
{
    // If vector full, multiply the size of the vector by 2
    if (size_v == space)
    {
        resize(space * 2);
    }

    // Add value to end of vector
    elem[size_v] = val;
    size_v++;
}

template<class T>
inline void vector<T>::reserve(int newalloc)
{
    if (newalloc > space)
    {
        T * Tptr = new T[newalloc];

        for (int i = 0; i < size_v; i++)
            Tptr[i] = elem[i];

        delete[] elem;
        T * temp = elem;
        elem = Tptr;
        Tptr = temp;
        delete[] Tptr;
    }
}

template<class T>
inline typename vector<T>::iterator vector<T>::begin()
{
    if (size_v == 0)
        return nullptr;
    return &elem[0];
}

template<class T>
inline typename vector<T>::const_iterator vector<T>::begin() const
{
    if (size_v == 0)
        return nullptr;
    return &elem[0];
}

template<class T>
inline typename vector<T>::iterator vector<T>::end()
{
    if (size_v == 0)
        return nullptr;
    return &elem[size_v];
}

template<class T>
inline typename vector<T>::const_iterator vector<T>::end() const
{
    if (size_v == 0)
        return nullptr;
    return &elem[size_v];
}

template<class T>
inline typename vector<T>::iterator vector<T>::insert(iterator p, const T & v)
{
    // Check if p excedes the end of the vector
    if (p > end() || p < begin())
    {
        exit(1);
    }

    // Increase size of vector if needed
    if (size_v == space)
    {
        resize(space * 2);
    }

    // Add value to the vector
    move(p, end(), p + 1)
    *p = v;
    size_v++;

    return p;
}

// This function results in a memory leak. must delete the end pointer after moving all elements.
template<class T>
inline typename vector<T>::iterator vector<T>::erase(iterator p)
{
    // Check if p excedes the end of the vector
    if (p >= end() || p < begin())
    {
        exit(1);
    }

    // Move values
    move(p + 1, end(), p);
    size_v--;

    //delete end(); // This line won't work


    return p;
}

} // End of Vector namespace

#endif // VECTOR_H
