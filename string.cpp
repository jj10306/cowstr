#include "string.h"
#include <string.h>
#include <algorithm>

String::String() {
  m_capacity = DEFAULT_CAPACITY;
  m_data = new char[m_capacity];
  m_size = 0;
}

String::String(const char *data) {
  m_size = strlen(data);
  m_capacity = m_size  * 2;
  m_data = new char[m_capacity];
  memcpy(m_data, data, m_size);
}

String::String(size_t capacity) {
  m_capacity = capacity;
  m_data = new char[m_capacity];
  m_size = 0;
}

String::String(const String &s) {
  m_size = s.size();
  m_capacity = s.capacity();
  m_data = new char[m_capacity];
  memcpy(m_data, s.as_ptr(), m_size);
  std::cout << "copying: " << s << std::endl;
}

size_t String::size() const {
  return m_size;
}

size_t String::capacity() const {
  return m_capacity;
}

char *String::as_ptr() const {
  return m_data;
}

void String::append(const String &s) {
  size_t new_size = s.size() + m_size;
  if (new_size > m_capacity) {
    std::cout << "resizing from ";
    std::cout << m_capacity << " to ";
    m_capacity = std::max(new_size * 2, m_capacity * 2);
    std::cout << m_capacity << std::endl;
    m_data = static_cast<char *>(realloc(m_data, m_capacity));
  }
  memcpy(m_data + m_size, s.as_ptr(), s.size());
  m_size = new_size;
}

String::~String() {
  std::cout << "destroying: " << *this << std::endl;
  delete []m_data;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
  const char *data = s.as_ptr();
  for (int i = 0; i < s.size(); i++) {
    os << data[i];
  }
  return os;
}
