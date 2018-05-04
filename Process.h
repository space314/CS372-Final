// Main spells
#pragma once
#include <memory>
#include "User.h"
#include "BaseProcess.h"

//Non magical stuff...
class NoMagicProcess : public BaseProcess
{
public:
	NoMagicProcess(std::shared_ptr<BaseProcess> next): BaseProcess(next){}
	bool handle(std::shared_ptr<User> user) override;
private:
	virtual void cast() const override = 0;
private:
};

//Splash water, one raises their hand,
//and hits the surface of the water.
class SplashWater : public NoMagicProcess
{
public:
	SplashWater(std::shared_ptr<BaseProcess> next): NoMagicProcess(next){}
private:
	void cast() const override;
};

//Low level spells
class LowLevelProcess : public BaseProcess
{
public:
	LowLevelProcess(std::shared_ptr<BaseProcess> next): BaseProcess(next){}
	bool handle(std::shared_ptr<User> user) override;
private:
	virtual void cast() const override = 0;
};

//Basic water spell
class BasicWaterSpell : public LowLevelProcess
{
public:
	BasicWaterSpell(std::shared_ptr<BaseProcess> next): LowLevelProcess(next){}
private:
	void cast() const override;
};

//Powerful spells
class PowerfulProcess : public BaseProcess
{
public:
	PowerfulProcess(std::shared_ptr<BaseProcess> next): BaseProcess(next){}
	bool handle(std::shared_ptr<User> user)  override;
private:
	virtual void cast() const override = 0;
};


//Miniflood spell
class MiniFlood : public PowerfulProcess
{
public:
	MiniFlood(std::shared_ptr<BaseProcess> next): PowerfulProcess(next){}
private:
	void cast() const override;
};

//No one except god can cast these properly.
class GodProcess : public BaseProcess
{
public:
	GodProcess(std::shared_ptr<BaseProcess> next): BaseProcess(next){}
	bool handle(std::shared_ptr<User> user) override;
private:
	virtual void cast() const override = 0;
};


//biblical flood
class WorldFlood : public GodProcess
{
public:
	WorldFlood(std::shared_ptr<BaseProcess> next): GodProcess(next){}
private:
	void cast() const override;
};