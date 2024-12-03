// ----------------------------------------------------------------------------
// Copyright (C) 2014 Jose L. Hidalgo
// ref_ptr Class (Referenced holder)
// ----------------------------------------------------------------------------

#ifndef INCLUDE_UPGINE_MEMORY_SMART_POINTER_REFERENCE_CONTAINER_H_
#define INCLUDE_UPGINE_MEMORY_SMART_POINTER_REFERENCE_CONTAINER_H_

namespace Upgine::Memory::SmartPointer {
  template<class T>
  class ReferenceContainer {
   public:
    typedef T element_type;

    ReferenceContainer() :ptr_(0L) {}
    ReferenceContainer(T* t):ptr_(t) { if (ptr_) ptr_->Ref(); }
    ReferenceContainer(const ReferenceContainer& rp):ptr_(rp.ptr_)  { if (ptr_) ptr_->Ref(); }
    virtual ~ReferenceContainer() {
      if (ptr_) ptr_->Unref();
      ptr_ = 0L;
    }

    element_type* alloc() { (*this) =new T(); return ptr_; }

    template<class SubT>
    SubT* allocT() {
      SubT *i = new SubT();
      (*this) = i;
      return i;
    }

    void release() { ReferenceContainer empty; swap(empty); }

    ReferenceContainer& operator = (const ReferenceContainer& rp) {
      if (ptr_ == rp.ptr_) return *this;
      T* tmp_ptr = ptr_;
      ptr_ = rp.ptr_;
      if (ptr_) ptr_->Ref();
      if (tmp_ptr) tmp_ptr->Unref();
      return *this;
    }

    void swap(ReferenceContainer &other) {
      T* tmp = other.ptr_;
      other.ptr_ = ptr_;
      ptr_ = tmp;
    }

    // comparison operators for ReferenceContainer.
    bool operator == (const ReferenceContainer& rp) const { return (ptr_ == rp.ptr_); }
    bool operator != (const ReferenceContainer& rp) const { return (ptr_ != rp.ptr_); }
    bool operator < (const ReferenceContainer& rp) const { return (ptr_ < rp.ptr_); }
    bool operator > (const ReferenceContainer& rp) const { return (ptr_ > rp.ptr_); }

    // comparison operator for const T*.
    bool operator == (const T* ptr) const { return (ptr_ == ptr); }
    bool operator != (const T* ptr) const { return (ptr_ != ptr); }
    bool operator < (const T* ptr) const { return (ptr_ < ptr); }
    bool operator > (const T* ptr) const { return (ptr_ > ptr); }

    T& operator*() { return *ptr_; }
    const T& operator*() const { return *ptr_; }
    T* operator->() { return ptr_; }
    const T* operator->() const { return ptr_; }
    bool operator!() const { return ptr_ == 0L; }
    bool valid() const { return ptr_ != 0L; }
    T* get() { return ptr_; }
    const T* get() const { return ptr_; }

   private:
    T* ptr_;
  };

  template<class T>
  class const_ReferenceContainer {
   public:
    typedef T element_type;

    const_ReferenceContainer() :ptr_(0L) {}
    const_ReferenceContainer(const T* t):ptr_(t) { if (ptr_) const_cast<T*>(ptr_)->Ref(); }
    const_ReferenceContainer(const const_ReferenceContainer& rp):ptr_(rp.ptr_)  { if (ptr_) const_cast<T*>(ptr_)->Ref(); }
    const_ReferenceContainer(const ReferenceContainer<T>& rp): ptr_(rp.get())  { if (ptr_) const_cast<T*>(ptr_)->Ref(); }
    ~const_ReferenceContainer() {
      if (ptr_) const_cast<T*>(ptr_)->Unref();
      ptr_ = 0L;
    }

    void release() { const_ReferenceContainer empty; swap(empty); }

    const_ReferenceContainer& operator = (const const_ReferenceContainer& rp) {
      if (ptr_ == rp.ptr_) return *this;
      const T* tmp_ptr = ptr_;
      ptr_ = rp.ptr_;
      if (ptr_) const_cast<T*>(ptr_)->Ref();
      if (tmp_ptr) const_cast<T*>(tmp_ptr)->Unref();
      return *this;
    }

    void swap(const_ReferenceContainer &other) {
      const T* tmp = other.ptr_;
      other.ptr_ = ptr_;
      ptr_ = tmp;
    }

    // comparison operators for const_ReferenceContainer.
    bool operator == (const const_ReferenceContainer& rp) const { return (ptr_ == rp.ptr_); }
    bool operator != (const const_ReferenceContainer& rp) const { return (ptr_ != rp.ptr_); }
    bool operator < (const const_ReferenceContainer& rp) const { return (ptr_ < rp.ptr_); }
    bool operator > (const const_ReferenceContainer& rp) const { return (ptr_ > rp.ptr_); }

    // comparison operator for const T*.
    bool operator == (const T* ptr) const { return (ptr_ == ptr); }
    bool operator != (const T* ptr) const { return (ptr_ != ptr); }
    bool operator < (const T* ptr) const { return (ptr_ < ptr); }
    bool operator > (const T* ptr) const { return (ptr_ > ptr); }

    const T& operator*() const { return *ptr_; }
    const T* operator->() const { return ptr_; }
    bool operator!() const { return ptr_ == 0L; }
    bool valid() const { return ptr_ != 0L; }
    const T* get() const { return ptr_; }

   private:
    const T* ptr_;
  };
}

#endif //INCLUDE_UPGINE_MEMORY_SMART_POINTER_REFERENCE_CONTAINER_H_
