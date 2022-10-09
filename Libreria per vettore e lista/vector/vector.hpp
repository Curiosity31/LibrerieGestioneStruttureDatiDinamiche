
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : public LinearContainer<Data> , public SearchableContainer<Data> {

private:


protected:

  using LinearContainer<Data>:: size;

  Data * elements = nullptr;

public:

  // Default constructor
  Vector() = default;

  // Specific constructor
  Vector (const ulong);

  // Copy constructor
  Vector (const Vector&);

  // Move constructor
  Vector (Vector&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator = (const Vector&);

  // Move assignment
  Vector& operator = (Vector&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Vector&) const noexcept;
  inline bool operator != (const Vector&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void Resize (const ulong);

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

   Data& Front() const override;
   Data& Back() const override;

   Data& operator[] (const ulong) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  using typename SearchableContainer<Data>::MapFunctor;
  void MapPreOrder (MapFunctor, void * ) override;
  void MapPostOrder(MapFunctor, void *) override;

  using typename SearchableContainer<Data>::FoldFunctor;
  void FoldPreOrder (FoldFunctor, const void *, void *) const override;
  void FoldPostOrder(FoldFunctor, const void *, void *) const override;

};

/* ************************************************************************** */

#include "vector.cpp"

}

#endif
