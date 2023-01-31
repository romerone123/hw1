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
void ULListStr::push_back(const std::string& val)
{
  if(size_ == 0)
  {
    Item* temp = new Item; //if there is no linked list
    temp->val[0] = val;
		temp->first = 0;
    temp->last = 1;
		head_ = temp;
    tail_ = temp;
		size_++;
  }
	else if(size_ != 0)
	{
		if(tail_->last > 9) //if the last node is full
		{
			Item* temp_ = new Item;
			tail_->next = temp_;
			temp_->prev = tail_;
			tail_ = temp_;
			temp_->first = 0;
			temp_->last = 1;
			temp_->val[0] = val;
			size_++;
		}
		else
		{
			tail_->val[tail_->last] = val; //if the last node isn't full yet
			tail_->last++;
			size_++;
		}
	}
}

void ULListStr::pop_back()
{
	if(tail_->last == 1)
	{
		if(head_ == tail_) //If there is only one item in the entire linked list(only one node)
		{
			delete head_;  
			head_=NULL;
			tail_=NULL;
			size_--;
		}
		else
		{
		Item* temp = tail_;
		tail_ = tail_->prev; //If there is only one item in the last Node
		delete temp;
		size_--;
		}
	}
	else
	{
		tail_->last--;
		size_--;
	}
}

void ULListStr::push_front(const std::string& val)
{
	if(size_ == 0)
	{
		push_back(val);  //if there is no linked list
	}
	else
	{
		if(head_->first == 0)//if there is no more room at the front of the node
		{
			Item* temp = new Item;
			head_->prev = temp;
			temp->next = head_;
			head_ = temp;
			head_->last = 10;
			head_->first = 9;
			head_->val[head_->first] = val;
			size_++;
		}
		else
		{
			head_->first--;
			head_->val[head_->first] = val;
			size_++;
		}
	}
	
}

void ULListStr::pop_front()
{
	if(head_->first == 9)
	{
		if(head_ != tail_)
		{
			Item* temp = head_;
			head_ = head_->next;
			delete temp;
			size_--;
		}
		else
		{
			delete head_;
			size_--;
		}
	}
	else
	{
		head_->first++;
		size_--;
		if(head_->first == head_->last)
		{
			delete head_;
		}
	}
}

std::string const & ULListStr::back() const
{
	return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
	return head_->val[head_->first];
}


//private
std::string* ULListStr::getValAtLoc(size_t loc) const
{
	Item* temphead = head_;
	temphead->first_temp = temphead->first;
	if(loc > size_-1)
	{
		return NULL;
	}
	for(size_t i = 0; i <= loc; i++)
	{
		if(i == loc)
		{
			return &temphead->val[temphead->first_temp];
		}
		else if(temphead->first_temp == 9)
		{
			temphead = temphead->next;
			temphead->first_temp = -1;
		}
		temphead->first_temp++;
	}
}




////////////////////////////////////////////////////////
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
