
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : public Queue<Data> , protected List<Data> {

private:


protected:


public:

  // Default constructor
  QueueLst();

  // Copy constructor
  QueueLst (const QueueLst&);

  // Move constructor
  QueueLst (QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst& operator = (const QueueLst&);

  // Move assignment
  QueueLst& operator = (QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator == (const QueueLst&) const noexcept;
  inline bool operator != (const QueueLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  inline Data& Head() const override; // (might throw std::length_error)
  inline void Dequeue() override; // (might throw std::length_error)
  inline Data HeadNDequeue() override; // (might throw std::length_error)
  inline void Enqueue (const Data&) override; // Copy of the value
  inline void Enqueue (Data&&) noexcept override; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline void Clear(); // Override Container member

};

/* ************************************************************************** */

#include "queuelst.cpp"

}

#endif
