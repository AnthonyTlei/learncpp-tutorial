#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }

	friend std::ostream& operator<<(std::ostream& out, const Resource& res)
	{
		out << "I am a resource\n";
		return out;
	}
};

class WeakResource
{
public:

	std::weak_ptr<WeakResource> m_ptr;
	//std::shared_ptr<WeakResource> m_ptr; // This will cause cylic reference 

	WeakResource() { std::cout << "Resource acquired\n"; }
	~WeakResource() { std::cout << "Resource destroyed\n"; }
};

// The function only uses the resource, so we'll accept a pointer to the resource, not a reference to the whole std::unique_ptr<Resource>
void useResource(Resource* res)
{
	if (res)
		std::cout << *res << '\n';
}

#endif