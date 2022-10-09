
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <stdexcept>
#include <functional>

namespace lasd {

/* ************************************************************************** */

class Container {

private:


protected:

ulong size = 0;

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator = (const Container&) = delete;

  // Move assignment
  Container& operator = (Container&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Container&) const noexcept = delete;
  bool operator != (const Container&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual inline bool Empty() const noexcept;

  virtual inline ulong Size() const noexcept;

  virtual void Clear() = 0;

};

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public Container {

private:

protected:

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator = (const LinearContainer&) = delete;

  // Move assignment
  LinearContainer& operator = (const LinearContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const LinearContainer&) const noexcept = delete;
  bool operator != (const LinearContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& Front() const = 0;
  virtual Data& Back() const = 0;

  virtual Data& operator [] (const ulong) = 0;
  virtual Data& operator [] (const ulong) const = 0;

};

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container {

private:

protected:

public:

  // Destructor
   virtual ~TestableContainer() = default ;

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer& operator = (const TestableContainer&) = delete;

  // Move assignment
  TestableContainer& operator = (TestableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
    bool operator == (const TestableContainer&) const noexcept = delete;
    bool operator != (const TestableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Exists (const Data&) const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class SearchableContainer : virtual public TestableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~SearchableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
    SearchableContainer& operator = (const SearchableContainer&) = delete;

    // Move assignment
    SearchableContainer& operator = (SearchableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const SearchableContainer&) const noexcept = delete;
  bool operator != (const SearchableContainer&) const noexcept= delete;


  /* ************************************************************************ */

  // Specific member functions

  typedef std::function<void(Data&, void *)> MapFunctor;
  virtual void MapPreOrder (MapFunctor, void *) = 0;
  virtual void MapPostOrder (MapFunctor, void *) = 0;

  typedef std::function<void(const Data&, const void *, void *) noexcept> FoldFunctor;
  virtual void FoldPreOrder (FoldFunctor, const void *, void * ) const = 0;
  virtual void FoldPostOrder (FoldFunctor, const void *, void *) const = 0;

  virtual bool Exists (const Data&) const noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthSearchableContainer : virtual public SearchableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~BreadthSearchableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthSearchableContainer& operator = (const BreadthSearchableContainer&) = delete;

  // Move assignment
  BreadthSearchableContainer& operator = (BreadthSearchableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const BreadthSearchableContainer&) const noexcept = delete;
  bool operator != (const BreadthSearchableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  using typename SearchableContainer<Data>::MapFunctor;
  virtual void MapBreadth (MapFunctor, void*) = 0;

  using typename SearchableContainer<Data>::FoldFunctor;
  virtual void FoldBreadth (FoldFunctor, const void * , void *) const = 0;

};

/* ************************************************************************** */

#include "container.cpp"

}

#endif
