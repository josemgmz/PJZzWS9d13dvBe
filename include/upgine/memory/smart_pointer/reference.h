/* -----------------------------------------------------------------------------
Copyright (c) 2017-2018 Jose L. Hidalgo (PpluX)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
----------------------------------------------------------------------------- */

#include <cassert>
#ifndef INCLUDE_UPGINE_MEMORY_SMART_POINTER_REFERENCE_H_

namespace Upgine::Memory::SmartPointer {

  class Reference {
  public:
    unsigned int RefCounter() const { return refCounter_; }
    void Ref();
    void Unref();
    void UnrefNoDelete();

  protected:
    Reference() : refCounter_(0) {}
    virtual ~Reference() {}

  private:
    unsigned int refCounter_;
    Reference(const Reference &);
    Reference& operator=(const Reference &);
  };

  inline void Reference::Ref() {
    ++refCounter_;
  }

  inline void Reference::Unref() {
    assert(refCounter_ > 0);
    --refCounter_;
    if (refCounter_ == 0) {
      delete this;
    }
  }

  inline void Reference::UnrefNoDelete() {
    assert(refCounter_ > 0);
    --refCounter_;
  }
}

#define INCLUDE_UPGINE_MEMORY_SMART_POINTER_REFERENCE_H_

#endif // INCLUDE_UPGINE_MEMORY_SMART_POINTER_REFERENCE_H_
