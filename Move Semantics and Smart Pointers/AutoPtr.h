#ifndef AUTOPTR_H
#define AUTOPTR_H

template<typename T>
class AutoPtr
{
	T* m_ptr;

public:

	AutoPtr(T* ptr = nullptr)
		:m_ptr(ptr)
	{}

	AutoPtr(const AutoPtr& ap) = delete;

	AutoPtr(AutoPtr&& ap) noexcept
		:m_ptr(ap.m_ptr)
	{
		ap.m_ptr = nullptr;
	}

	~AutoPtr()
	{
		delete m_ptr;
	}

	AutoPtr& operator=(const AutoPtr& ap) = delete;

	AutoPtr& operator=(AutoPtr&& ap)
	{
		if (&ap == this)
			return *this;

		delete m_ptr;

		m_ptr = ap.m_ptr;

		ap.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }

};



#endif