#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string>

template<typename T>
class Pair1
{
	T m_first;
	T m_second;

public:

	Pair1(const T& first, const T& second):
		m_first{first}, m_second{second}
	{}

	const T& first() const { return m_first; }
	const T& second() const { return m_second; }

};

template<typename T, typename S>
class Pair
{
	T m_first;
	S m_second;

public:

	Pair(const T& first, const S& second) :
		m_first{ first }, m_second{ second }
	{}

	const T& first() const { return m_first; }
	const S& second() const { return m_second; }

};

template<typename S>
class StringValuePair : public Pair<std::string, S>
{

public:
	StringValuePair(const std::string& first, const S& second):
		Pair<std::string, S>{first, second}
	{}

};

#endif