﻿#include "ArrayList.h"



ArrayList::ArrayList(const ArrayList& list)
{
	count = list.count;
	
	capacity = list.count;
	data = list.data; 
	data = new int [count] ;
	for (int i = 0; i < count; i++)
	{
		data[i] = list.data[i];
	}
	str = nullptr; 
}

ArrayList::~ArrayList()
{
	if (data !=nullptr)
		{
			delete[] data;
		}
	if (str != nullptr)
	{
		delete[] str; 
	}
}
bool ArrayList::indexValid(int index)
{
	return (index >= 0 && index < count);
}

void ArrayList::expand(int addedlength)
{
	int newCapacity = capacity + (addedlength < 1 ? capacity : addedlength); 
	int* p = new int[capacity * 2];
	for (int i = 0; i < count; i++)
	{
		p[i] = data[i];

	}
	delete[] data;
	data = p;
	capacity *= 2;
}

int ArrayList::numLength(int number)
{

	
	if (number < 0)
	{
		return 1 + numLength(-number); 
	}
	int length = 1;
	if (number > 0)
	{
		for (;number > 9;)
		{
			number /= 10;
			length++;
		}
	}
	return length;
}

void ArrayList::addToStr(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addToStr(int& index, int number)
{
	int length = numLength(number);
	int p = 0;
	if (number < 0)
	{
		length++;
		number = -number;
		p = 1;
	}
	for (int i = 0; i < length; i++)
	{
		int digit = number % 10;
		str[index + length - i - 1] = '0' + digit;
		number /= 10;

	}
	if (p == 1)
	{
		str[index] = '-';
	}
	index += length;

}

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	data[count] = element;
	count++; 
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (!indexValid(index))
	{
		return false;
	}
	if (count == capacity)
	{
		expand();
	}
	if (index == count)
	{
		return add(element);
	}

	if (index < count)
	{
		for (int i = count + index; i > index; i--)
		{

			data[i] = data[i - 1];
		}
	}
	data[index] = element;
	count++;
	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	for (int i = 0; i < list.count; i++)
	{
		add(list.data[i]);
	}
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	for (int i = list.count-1; i >= 0; i--)
	{
		add(index, list.data[i]);
	}

	return false;
}

void ArrayList::clear()
{
	count = 0;
}

bool ArrayList::contains(int element)
{
	int p = 0;
	for (int i = 0; i < count;i++)
	{
		if (element == data[i])
		{
			p++;
		}

	}
	if (p > 0)
	{
		return true;
	}
	return false;

}
bool indexincorrect(int count, int index)
{
	return (index < 0) || (index >= count);
}
int ArrayList::get(int index)
{

	return data[index];
}

bool ArrayList::set(int index, int element)
{
	if (index >= count)
	{
		return false; 
	}
	data[index] = element;

	return true;
}

int ArrayList::indexOf(int element)
{
	for (int i = 0; i < count; i++)
	{
		if (data[i] == element)
		{
			return i;
		}

	}
	return 0;
}

bool ArrayList::isEmpty()
{

	if (count == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

char* ArrayList::toString()
{
	int len = (length()) * 5 + 9;
	str = new char[len];
	int index = 0;
	addToStr(index, '[');
	addToStr(index, count);
	addToStr(index, '/');
	addToStr(index, length());
	addToStr(index, ']');
	addToStr(index, ' ');
	addToStr(index, '{');
	for (int i = 0; i < length(); i++)
	{

		addToStr(index, data[i]);
		if (i == length() - 1)
		{

		}
		else
		{
			addToStr(index, ',');
		}
	}
	addToStr(index, '}');
	addToStr(index, '\0');;

	return str;
}

bool ArrayList::remove(int index)
{
	if (indexincorrect(length(), index))
	{
		return false;
	}
	else
	{
		for (;index < count - 1;index++)
		{
			data[index] = data[index + 1];

		}
		count--;
		return true;
	};

}

bool ArrayList::swap(int index1, int index2)
{
	int p = 0;
	p = data[index1];
	data[index1] = data[index2];
	data[index2] = p;
	return false;
}
int ArrayList::length()
{

	return count;
}

void ArrayList::operator+=(int item)
{
	add(item); 
}

void ArrayList::operator-=(int item)
{

	if (contains(item))
	{for (int i = count; i > 0; i--)
		{
			if (data[i] == item)
			{
				remove(i);
			}
		}
	}
}

ArrayList& ArrayList::operator=(const ArrayList& list)
{
	if (&list != this)
	{
		if (data != nullptr)
		{
			delete[] data; 
		}
		if (str != nullptr)
		{

			delete[] data;
			str = nullptr;
		}
		count = list.count;
		capacity = list.capacity;
		data = new int[count];
		for (int i = 0; i < count;data[i] = list.data[i], i++);
	}

	return *this; 
	// TODO: вставьте здесь оператор return
}


ArrayList operator+(const ArrayList& list, int item)
{
	ArrayList result(list);
	//result = list;
	result.add(item);
	return result;
}

ArrayList operator+(int item, const ArrayList& list)
{
	ArrayList result(list);
	result.add(0, item);
	
    return result;
}

ArrayList operator+(const ArrayList& list1, const ArrayList& list2)
{
	ArrayList result(list2);
	for (int i = 0; i < list1.count; i++)
	{
		result.add(list1.data[i]);
	}

	

    return result;
}

ArrayList operator-(const ArrayList& list, int item)
{
	int index = -1;
	for (int i = 0; i <= list.count;i++)
	{
		if (list.data[i] == item)
		{
			index = i;
		}
	}
	if (index == -1)
	{
		return ArrayList(); 
	}
	ArrayList result(list);
	result.remove(index);
	return ArrayList();
}

ArrayList operator-(int item, const ArrayList& list)
{
	int index = -1;
	for (int i = list.count; i >= 0;i--)
	{
		if (list.data[i] == item)
		{
			index = i;
		}
	}
	ArrayList result(list);
	result.remove(index);
	return ArrayList();
}

std::ostream& operator<<(std::ostream& stream, const ArrayList& list)
{
	stream << "[" << list.count << "/" << list.capacity << "] {";
	if (list.count == 0)
	{
		stream << "EMPTY";

	}
	for (int i = 0;i < list.count;i++)
	{
		stream << list.data[i];
		if (i != list.count - 1)
		{
			stream << ",";
		}
	}
	stream << "}";
	return stream; 
}
