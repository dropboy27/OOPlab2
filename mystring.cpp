#include <iostream>
#include "mystring.h"


String& String::operator=(String other) {
    swap(other);
    return *this;
}

void String::swap(String& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

size_t String::size() const{
    return size_;
}

const char* String::data() const{
    return data_;
}

void String::push_back(char c){
    if (size_ == capacity_){
        size_t new_cap;
        if (capacity_ == 0){
            new_cap = 1;
        }
        else{
            new_cap = capacity_ * 2;
        }
        char* new_data = new char[new_cap + 1];
        for (size_t i = 0; i < size_; i++){
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_cap;
    }
    data_[size_] = c;
    size_++;
    data_[size_] = '\0';
}

void String::append(const char* str){
    if (str == nullptr){
        return;
    }
    size_t str_len = 0;
    while(str[str_len]!='\0'){
        str_len++;
    }
    for(size_t i = 0; i < str_len; i++){
        push_back(str[i]);
    }
}

void String::print(std::ostream& os) const{
    for(size_t i = 0; i < size_; i++){
        os<<data_[i];
    }
}

size_t String::find(const char* substr){

    size_t substr_len = 0;
    while(substr[substr_len]!='\0'){
        substr_len++;
    }
    if(substr_len == 0){
        return 0;
    }
    if(substr_len >size_){
        return;
    }
    for(size_t i = 0; i < size_; i++){
        
    }
}