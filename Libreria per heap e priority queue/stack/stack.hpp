
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack : virtual public Container {

private:



protected:



public:

  // Destructor
  virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
  Stack<Data>& operator = (const Stack<Data>&) = delete;

  // Move assignment
  Stack<Data>& operator = (Stack<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Stack<Data>&) const noexcept = delete;
  bool operator != (const Stack<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& Top() const = 0; // (might throw std::length_error)
  virtual void Pop() = 0; // (might throw std::length_error)
  virtual Data TopNPop() = 0; // (might throw std::length_error)
  virtual void Push (const Data&) = 0; // Copy of the value
  virtual void Push (Data&&) noexcept = 0; // Move of the value

};

/* ************************************************************************** */

}

#endif
