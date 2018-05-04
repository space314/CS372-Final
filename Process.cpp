#include "Process.h"

bool NoMagicProcess::handle(std::shared_ptr<User> user)
{
	cast();
	return true;
}


void SplashWater::cast() const
{
	std::cout << "You splash water... its ineffective." << std::endl;
}

//If you can't cast a basic spell, defaults to no spell.
bool LowLevelProcess::handle(std::shared_ptr<User> user)
{
	if (user->get_lvl() >= 1)
	{
		cast();
		return true;
	}
	else
	{
		std::cout << "You feel your stomach churn, thats not magic... is it?" << std::endl;
		nextProcess(user);
		return false;
	}
}


void BasicWaterSpell::cast() const
{
	std::cout << "You move water in the air... it looks cool? ... though ineffective." << std::endl;
}

//Can't quite manage a powerfull spell, well, maybe you can cast a weaker version.
bool PowerfulProcess::handle(std::shared_ptr<User> user) 
{
	if (user->get_lvl() >= 2)
	{
		cast();
		return true;
	}
	else
	{
		std::cout << "You feel magic surging through your body..." << std::endl;
		nextProcess(user);
		return false;
	}
}


void MiniFlood::cast() const
{
	std::cout << "A torental rain appears... all who whatch are terrified... highly effective." << std::endl;
}


//If you're god, this should be a piece of cake, if not well, maybe you can succefully cast
//a lower level spell.
bool GodProcess::handle(std::shared_ptr<User> user)
{
	if (user->get_lvl() >= 3)
	{
		std::cout << "You lift your finger... What sort of magic are we about to witness..." << std::endl;
		cast();
		return true;
	}
	else if (user->get_lvl() == 2)
	{
		std::cout << "You close your eyes and concentrate..." << std::endl;
		std::cout << "Dispite you best efforts, you are unable conjure enough magic to perform the task" << std::endl;
		nextProcess(user);
		return false;
	}
	else
	{
		std::cout << "You close your eyes..." << std::endl;
		nextProcess(user);
		return false;
	}
}


void WorldFlood::cast() const
{
	std::cout << "The land falls beneath the sea." << std::endl;
	std::cout << "All are instanteously killed by powerful storms..." << std::endl;
	std::cout<< "Highly effective... also slight overkill." << std::endl;
}
