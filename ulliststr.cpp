#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
using namespace std;

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

/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  string* ULListStr::getValAtLoc(size_t loc) const {
    if (loc<0 || loc>=size_ || size_==0){
      return NULL;
    }
    else if (loc==0){
      return (head_->val)+(head_->first);
    }
    Item* temp = head_;
    size_t counter=0;
    while(temp!=nullptr){
      for(int i=temp->first; i<temp->last; i++){
        if (counter==loc && temp->val[i]!=""){
          return (temp->val)+i;
        }
        counter++;
      }
      temp = temp->next;
    }
  }

// WRITE YOUR CODE HERE
  // case 1) head_ is null
  // 1) create new Item
  // 2) set val[last] = value
  // 3) last++
  // 4) Update tail to point to the same as head
  // Case 2) tail node is full (last == size of array)
  // 1) Create new node
  // 2) Make tail point to new node
  // 3) Make new node previous to point to tail
  // 4) Update the tail
  // Case 3) Tail still has space at the end
  void ULListStr::push_back(const std::string& val) {
    if (head_==nullptr){
      Item* node = new Item;
      node->val[node->last] = val;
      node->last++;
      head_ = node;
      tail_ = node;
      size_++;
    }
    else {
      if (tail_->last == ARRSIZE){ 
        Item* node = new Item;
        node->val[node->last] = val;
        node->last++;
        tail_->next = node;
        node->prev = tail_;
        tail_ = node;
        size_++;
      }
      else {
        tail_->val[tail_->last] = val;
        tail_->last++;
        size_++;
      }
    }
  }

  // push_front (in all cases size_++)
  // Case 1) head_ is empty 
  // Case 2) there's free space before first (first!=0) -> update first (val[first-1]) -> first = first--;
  // Case 3) head is completely full (first==0) -> create new head (set is as head_, update next and prev)
  void ULListStr::push_front(const string& val) {
    if(head_==nullptr){
      Item* node = new Item;
      node->val[node->first] = val;
      node->last++;
      head_ = node;
      tail_ = node;
      size_++;
    }
    else {
      if (head_->first!=0){
        head_->val[head_->first-1] = val;
        head_->first--;
        size_++;
      }
      else {
        Item* node = new Item;
        node->val[node->first] = val;
        node->last++;
        head_->prev = node;
        node->next = head_;
        head_ = node;
        size_++;
      }
    }
  }

  
  string const & ULListStr::front() const{
    string* ptr = getValAtLoc(0);
    return *ptr;
  }

  string const & ULListStr::back() const {
    string* ptr = getValAtLoc(size_-1);
    return *ptr;
  }

  // 4 cases to consider
  // case 1) head is empty
  // case 2) head has more than 1 element (normal case)
  // case 3) head that has only 1 element but there are nodes after head
  // case 4) head with 1 element and no nodes after
  void ULListStr::pop_front() {
    // case 1
    if (head_==nullptr){
      return;
    }
    // case 2
    if (head_->last!=(head_->first)+1){
      head_->val[head_->first] = "";
      head_->first++;
      size_--;
    }
    else {
      // case 3
      if (tail_!=head_){
        Item* temp = head_;
        head_->next->prev = nullptr;
        head_ = head_->next;
        delete temp;
        size_--;
      }
      // case 4
      else {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
        size_--;
      }
    }
  }

  // 4 cases as well
  // case 1) head is empty
  // case 2) tail has more than 1 element (normal case)
  // case 3) tail has 1 element and is not same as head
  // case 4) tail has 1 element and it's same as head
  void ULListStr::pop_back() {
    // case 1
    if (head_==nullptr){
      return;
    }
    // case 2
    if (tail_->last!=(tail_->first)+1){
      tail_->val[tail_->last-1] = "";
      tail_->last--;
      size_--;
    }
    else {
      // case 3
      if (tail_!=head_){
        Item* temp = tail_;
        tail_->prev->next = nullptr;
        tail_ = tail_->prev;
        delete temp;
        size_--;
      }
      // case 4
      else {
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
        size_--;
      }
    }
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
