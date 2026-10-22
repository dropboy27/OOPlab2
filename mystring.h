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
    bool operator==(const String& other) const;
    void push_back(char c);
    void append(const char* str);
    void swap(String& other);
    void print(std::ostream& os) const;
    size_t find(const char* substr) const;
    void word_histogram(String* words, size_t* counts, size_t& out_size) const;

private:
    char* data_;
    size_t size_;
    size_t capacity_;
};