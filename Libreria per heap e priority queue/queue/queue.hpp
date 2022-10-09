
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue : virtual public Container {

private:


protected:


public:

  // Destructor
  virtual ~Queue() = default;

  /* ************************************************************************ */

  // Copy assignment
  Queue<Data>& operator = (const Queue<Data>&) = delete;

  // Move assignment
  Queue<Data>& operator = (Queue<Data>&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Queue<Data>&) const noexcept = delete;
  bool operator != (const Queue<Data>&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& Head() const = 0; // (might throw std::length_error)
  virtual void Dequeue() = 0; // (might throw std::length_error)
  virtual Data HeadNDequeue() = 0; // (might throw std::length_error)
  virtual void Enqueue (const Data&) = 0; // Copy of the value
  virtual void Enqueue (Data&&) noexcept = 0; // Move of the value

};

/* ************************************************************************** */

}

#endif
