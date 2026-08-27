#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_front(const std::string& val){
  if (head_ == NULL || tail_ == NULL){  // no Item at all
    head_ = tail_ = new Item();
    head_ -> val[0] = val;
    head_ -> last++;
    size_++;
  }
  else if((head_ -> first) > 0){
    head_ -> first--;
    head_ -> val[head_ -> first] = val;
    size_++;
  }
  else{
    Item* itemPtr = new Item();
    itemPtr -> first = ARRSIZE -1; 
    itemPtr -> last = ARRSIZE;
    itemPtr -> val[itemPtr -> first] = val;
    size_++;
    itemPtr -> next = head_;
    head_ -> prev = itemPtr;
    head_ = itemPtr;

  }
}


void ULListStr::push_back(const std::string& val){
  if (head_ == NULL || tail_ == NULL){
      head_ = tail_ = new Item();
      head_ -> val[0] = val;
      head_ -> last++;
      size_++;
  }
  else if( (tail_ -> last < ARRSIZE) ){
      tail_ -> last++;
      tail_ -> val[ (tail_ -> last) -1] = val;
      size_++;
  }
  else{
      Item* itemPtr = new Item();
      itemPtr -> val[itemPtr -> first] = val;
      itemPtr -> last++;
      size_++;
      itemPtr->prev = tail_;
      tail_ -> next = itemPtr;
      tail_ = itemPtr;
  }
}


void ULListStr::pop_front(){
  if (head_ == NULL || tail_ == NULL) return;
  else if (empty()) return;
  else if (head_ -> first+1 < head_ -> last){
    head_ -> first++;
    size_--;
  }
  else{
    Item* itemPtr = head_;
    head_ = head_ -> next;
    head_ -> prev = NULL;
    delete itemPtr;
    size_--;
  }
}

void ULListStr::pop_back(){
  if (head_ == NULL || tail_ == NULL) return;
  else if (empty()) return;
  else if (tail_ -> last -1 > tail_ -> first){
    tail_ -> last--;
    size_--;
  }
  else{
    Item* itemPtr = tail_;
    tail_ = tail_ -> prev;
    tail_ -> next = NULL;
    delete itemPtr;
    size_--;
  }
}


std::string const & ULListStr::back() const{
  if (empty()) return NULL;
  return tail_ -> val[tail_ -> last - 1];
}


std::string const & ULListStr::front() const{
  if (empty()) return NULL;
  return head_ -> val[head_ -> first];
}


std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (empty()) return NULL;
  Item* itemPtr = head_;
  while (itemPtr != NULL){
    if ( loc < (itemPtr -> last - itemPtr -> first) ){// element IS here
      return &itemPtr->val[itemPtr -> first + loc];
    }
    else{// skip
      loc -= (itemPtr -> last - itemPtr -> first);
      itemPtr = itemPtr -> next;
    }
  }
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
