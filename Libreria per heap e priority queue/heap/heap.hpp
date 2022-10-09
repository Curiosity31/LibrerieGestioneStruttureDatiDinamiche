
#ifndef HEAP_HPP
#define HEAP_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Heap : virtual public SearchableContainer<Data> , protected BinaryTreeVec<Data> {

private:

  // ...

protected:


  using BinaryTreeVec<Data>:: treeVec;
  using BinaryTreeVec<Data>:: size;

  void BuildTree (const LinearContainer<Data>&, uint);

  void BuildHeap();

  void Heapify (Vector <typename BinaryTreeVec<Data>:: NodeVec*>& , uint);

  // ...

public:

  // Default constructor
  Heap() = default;

  // Specific constructor
  Heap (const LinearContainer<Data>&); // Construct a heap from a LinearContainer

  // Copy constructor
  Heap (const Heap<Data>&);

  // Move constructor
  Heap (Heap<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~Heap() = default;

  /* ************************************************************************ */

  // Copy assignment
  Heap<Data>& operator = (const Heap<Data>&);

  // Move assignment
  Heap<Data>& operator = (Heap<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator == (const Heap<Data>&) const noexcept;
  inline bool operator != (const Heap<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void Sort();

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  using typename SearchableContainer<Data>:: MapFunctor;
  void MapPreOrder (MapFunctor, void *) override; // Override SearchableContainer member
  void MapPostOrder (MapFunctor, void *) override; // Override SearchableContainer member

  using typename SearchableContainer<Data>:: FoldFunctor;
  void FoldPreOrder (FoldFunctor, const void *, void *) const override; // Override SearchableContainer member
  void FoldPostOrder (FoldFunctor, const void *, void *) const override; // Override SearchableContainer member

};

/* ************************************************************************** */

#include "heap.cpp"

}

#endif
