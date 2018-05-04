// User class for processes. Depending on ones privilage type,
// a particular user may or may not be able to call a particular
// command.

#pragma once
#include<string>
#include<iostream>

class User
{
public:
	User(std::string name) :m_name(name) { std::cout << "Hello " << m_name << std::endl; }
	virtual int get_lvl() const = 0;
private:
	std::string m_name;
};