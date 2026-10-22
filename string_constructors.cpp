#include "mystring.h"

String::String(){
    size_ = 0;
    capacity_= 1;
    data_ = new char[capacity_+1];
    data_[0] = '\0';
}

String::String(const char* str){
    if(str == nullptr)
    {
        data_ = new char[2];
        size_ = 0;
        capacity_ = 1;
        data_[0] = '\0';
    }
    else
    {  
        size_t i = 0;
        while(str[i]!='\0'){
            i++;
        }
        size_ = i;
        capacity_ = i+1;
        data_ = new char[capacity_+1];

        for(size_t j = 0; j<i; j++){
            data_[j] = str[j];
        }
        data_[size_] = '\0';
    }
}

String::String(const String& str){
    if(str.capacity_ == 0){
        size_ = 0;
        capacity_ = 1;
        data_ = new char[2];
        data_[0] = '\0';
    }else{
    size_ = str.size_;
    capacity_ = str.capacity_;  
    data_ = new char[capacity_+1];
    for(size_t i =0; i < size_;  i++){
        data_[i] = str.data_[i];
    }
    data_[size_] = '\0';
    }
}

String::String(String&& str) noexcept{
    size_ = str.size_;
    capacity_ = str.capacity_;
    data_=str.data_;
    str.data_=nullptr;
    str.capacity_=0;
    str.size_=0;
}


String::~String(){
    delete[] data_;
    size_ = 0;
    capacity_ = 0;
    data_ = nullptr;
}
