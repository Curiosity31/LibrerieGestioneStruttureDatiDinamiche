
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : public  Stack<Data> ,  protected List<Data> {

private:



protected:



public:

  // Default constructor
  StackLst();

  // Copy constructor
  StackLst (const StackLst&);

  // Move constructor
  StackLst (StackLst&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst& operator = (const StackLst&);

  // Move assignment
  StackLst& operator = (StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
   inline bool operator == (const StackLst&) const noexcept;
   inline bool operator != (const StackLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  inline Data& Top() const override; // Override Stack member (might throw std::length_error)
  inline void Pop() override; // Override Stack member (might throw std::length_error)
  inline Data TopNPop() override; // Override Stack member (might throw std::length_error)
  inline void Push (const Data&) override; // Override Stack member
  inline void Push (Data&&) noexcept override; // Override Stack member

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline void Clear() override; // Override Container member

};

/* ************************************************************************** */

#include "stacklst.cpp"

}

#endif
