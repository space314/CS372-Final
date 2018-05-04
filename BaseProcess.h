#pragma once

#include<memory>
#include "User.h"

//Base spell
class BaseProcess
{
public:
	//takes pointer to next spell to try
	BaseProcess(std::shared_ptr<BaseProcess> next):m_next(next) {}
	//gets next spell
	void nextProcess(std::shared_ptr<User> user)
	{
		m_next->handle(user);
	}
	//virtual function deciding what to do for a specific wizard.
	virtual bool handle(std::shared_ptr<User> user) = 0;
private:
	//virtual function that casts spell.
	virtual void cast() const = 0;
private:
	std::shared_ptr<BaseProcess> m_next;
};