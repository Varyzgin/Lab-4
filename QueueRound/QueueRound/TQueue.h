#pragma once
#include <iostream>
#include <string>

template <class T>
class TQueue
{
private:
	T* mas;
	int MaxSize;
	int count;
	int head, tail;

public:
	TQueue(int _MaxSize = 100);
	TQueue(const TQueue<T>& TQ);
	~TQueue();
	TQueue<T>& operator=(const TQueue<T>& TQ);

	bool operator==(const TQueue<T>& TQ) const;
	bool operator!=(const TQueue<T>& TQ) const;

	int GetMaxSize();
	int GetCount();
	int GetHead();

	bool Empty();
	bool Full();

	void Push(T el);
	T Pop();

	void Clear();

	friend std::ostream& operator<<(std::ostream& out, const TQueue& q)
	{
		out << "[ ";
		for (int tCount = q.count, i = q.head; tCount > 0; tCount--) {
			i++;
			out << q.mas[i] << ' ';
			i %= q.MaxSize;
		}
		out << "]";
		return out;
	}
};

template <class T>
TQueue<T>::TQueue(int _MaxSize)
{
	if (_MaxSize <= 1) throw "Queue MaxSize cannot be < 2";
	
	MaxSize = _MaxSize;
	mas = new T[MaxSize];

	count = 0;
	tail = -1, head = 0;
}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& TQ)
{
	MaxSize = TQ.MaxSize;
	mas = new T[MaxSize];

	count = TQ.count;
	tail = TQ.tail, head = TQ.head;
	int h = head;
	for (int i = count; i > 0; i--) {
		mas[h] = TQ.mas[h];
		h++;
		h %= MaxSize;
	}
}

template <class T>
TQueue<T>::~TQueue()
{
	delete[] mas;
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& TQ)
{
	if (this == &TQ)
		return *this;

	if (MaxSize != TQ.MaxSize) {
		MaxSize = TQ.MaxSize;
		delete[] mas;
		mas = new T[MaxSize];
	}
	count = TQ.count;
	tail = TQ.tail, head = TQ.head;
	int h = head;
	for (int i = count; i > 0; i--) {
		mas[h] = TQ.mas[h];
		h++;
		h %= MaxSize;
	}
	return *this;
}

template <class T>
bool TQueue<T>::operator==(const TQueue<T>& TQ) const
{
	if (MaxSize != TQ.MaxSize) return false;
	if (count != TQ.count) return false;
	if (head != TQ.head) return false;
	if (tail != TQ.tail) return false;
	int h = head;
	for (int i = count; i > 0; i--) {
		if (mas[h] != TQ.mas[h]) return false;
		h++;
		h %= MaxSize;
	}
	return true;
}

template <class T>
bool TQueue<T>::operator!=(const TQueue<T>& TQ) const
{
	return !operator==(TQ);
}

template<class T>
int TQueue<T>::GetMaxSize()
{
	return MaxSize;
}

template<class T>
int TQueue<T>::GetCount()
{
	return count;
}

template<class T>
int TQueue<T>::GetHead()
{
	return head;
}

template <class T>
bool TQueue<T>::Empty()
{
	return (count == 0);
}

template <class T>
bool TQueue<T>::Full()
{
	return (count == MaxSize);
}

template <class T>
void TQueue<T>::Push(T el)
{
	if (Full()) throw "Can't push to a full queue";
	tail++;
	tail %= MaxSize;
	mas[tail] = el;
	count++;
}

template <class T>
T TQueue<T>::Pop()
{
	if (Empty()) throw "Can't pop from an empty queue";
	T temp = mas[head];
	head++;
	head %= MaxSize;
	count--;
	return temp;
}

template <class T>
void TQueue<T>::Clear()
{
	count = 0;
	tail = -1, head = 0;
}