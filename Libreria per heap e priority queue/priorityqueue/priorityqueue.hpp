
#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

/* ************************************************************************** */

#include "../heap/heap.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PriorityQueue : public Heap<Data> {

private:

  // ...

protected:

  using Heap<Data>:: size;
  using Heap<Data>:: treeVec;

  void ExactLocation (Vector <typename BinaryTreeVec<Data>:: NodeVec*>&, uint);

public:

  // Default constructor
  PriorityQueue() = default;

  // Specific constructor
  PriorityQueue (const LinearContainer<Data>&); // Construct a priority queue from a LinearContainer

  // Copy constructor
  PriorityQueue (const PriorityQueue<Data>&);

  // Move constructor
  PriorityQueue (PriorityQueue<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~PriorityQueue() = default;

  /* ************************************************************************ */

  // Copy assignment
  PriorityQueue<Data>& operator = (const PriorityQueue<Data>&);

  // Move assignment
  PriorityQueue<Data>& operator = (PriorityQueue<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator == (const PriorityQueue<Data>&) const noexcept;
  inline bool operator != (const PriorityQueue<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  using Heap<Data>::Root;

  const Data& Tip() const; // (might throw std::length_error)
  void RemoveTip(); // (might throw std::length_error)
  Data TipNRemove(); // (might throw std::length_error)
  void Insert (const Data&); // Copy of the value
  void Insert (Data&&) noexcept; // Move of the value

  void ChangePriority (typename BinaryTreeVec<Data>:: NodeVec&, const Data&); // Change priority of a Node (Copy of the value)
  void ChangePriority (typename BinaryTreeVec<Data>:: NodeVec&, Data&&) noexcept; // Change priority of a Node (Move of the value)

};

/* ************************************************************************** */

#include "priorityqueue.cpp"

}

#endif
