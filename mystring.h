#pragma once
#include <cstddef>
#include <utility>
#include <ostream>

class String {
public:
    String();
    String(const char* str);
    String(const String& str);
    String(String&& str) noexcept;
    ~String();
    size_t size() const;
    const char* data() const;
    String& operator=(String other);
    void push_back(char c);
    void append(const char* str);
    void swap(String& other);
    void String::print(std::ostream& os) const;
    size_t String::find(const char* str);

private:
    char* data_;
    size_t size_;
    size_t capacity_;
};