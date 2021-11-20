#include <stddef.h>
#include <iostream>

class String {
  public:
    String();
    String(const char *data);
    String(size_t capacity);
    String(const String &s);
    ~String();
    void append(const String &s) ;
    char *as_ptr() const;
    size_t capacity() const;
    size_t size() const;


  private:
    char *m_data;
    size_t m_capacity;
    size_t m_size;
    const size_t DEFAULT_CAPACITY = 1;
};

std::ostream& operator<<(std::ostream& os, const String& s);
