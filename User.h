#pragma once
#include<string>
#include<iostream>
#include "BaseUser.h"

class NonWizard : public User
{
public:
	NonWizard(std::string name) :User(name), m_level(0) {}
	int get_lvl() const override;
private:
	int m_level;
};

class LowLevelWizard : public User
{
public:
	LowLevelWizard(std::string name) :User(name), m_level(1) {}
	int get_lvl() const override;
private:
	int m_level;
};

class HighLevelWizard : public LowLevelWizard
{
public:
	HighLevelWizard(std::string name) : LowLevelWizard(name), m_level(2) {}
	int get_lvl() const override;
private:
	int m_level;
};

class God : public HighLevelWizard
{
public:
	God(std::string name) : HighLevelWizard(name), m_level(3) {}
	int get_lvl() const override;
private:
	int m_level;
};
