#ifndef FRUIT_H
#define FRUIT_H

#include <string>
#include <iostream>

class Fruit
{

	std::string m_name{};
	std::string m_color{};

public:

	Fruit(const std::string& name, const std::string& color) :
		m_name{ name }, m_color {color}
	{

	}

	const std::string& getName()
	{
		return m_name;
	}

	const std::string& getColor()
	{
		return m_color;
	}

};

class Banana : public Fruit
{
public:

	Banana(std::string color = "yellow") :
		Fruit("banana", color)
	{

	}
		

};

class Apple : public Fruit
{

protected:
	Apple(const std::string& name, const std::string& color)
		: Fruit{ name, color }
	{

	}
public:

	Apple(std::string color = "red") :
		Fruit("apple", color)
	{

	}


};

class GrannySmith : public Apple
{
public:

	GrannySmith() :
		Apple("granny smith apple", "green")
	{

	}
};

#endif