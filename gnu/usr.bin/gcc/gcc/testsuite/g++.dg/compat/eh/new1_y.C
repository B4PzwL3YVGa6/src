#include <new>

extern int ret;

void *ptr;
void * operator new[] (size_t s) throw (std::bad_alloc)
{
  ptr = operator new (s);
  return ptr;
}

void operator delete[] (void *p) throw ()
{
  if (p == ptr)
    ret = 0;
  operator delete (p);
}

