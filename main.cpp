// Jesse Keller
// 5/3/18
// CS 372
//
// Implements Chain of responsibility
// Wizards want to cast powerful spells,
// however what spell they succeffully manage
// to cast largely depends on how powerful they 
// are.


#include "Process.h"
#include "User.h"

int main()
{
	//Sets up chain
	SplashWater splash(nullptr);
	BasicWaterSpell basic( std::make_shared<SplashWater>(splash));
	MiniFlood minflood( std::make_shared<BasicWaterSpell>(basic));
	WorldFlood flood(std::make_shared<MiniFlood>(minflood));

	//Bob tries creating a world flood, but he's not a wizard so nothing happens.
	NonWizard Bob("Bob");
	flood.handle(std::make_shared<NonWizard>(Bob));
	std::cout << "......." << std::endl;

	//Mary tries creating a world flood, she moves water?
	LowLevelWizard Mary("Mary");
	flood.handle(std::make_shared<LowLevelWizard>(Mary));
	std::cout << "......." << std::endl;

	//Sue tries creating world flood, she creates a miniflood...
	//still impressive.
	HighLevelWizard Sue("Sue");
	flood.handle(std::make_shared<HighLevelWizard>(Sue));
	std::cout << "......." << std::endl;

	//All are immediately killed.
	God god("god");
	flood.handle(std::make_shared<God>(god));
	std::cout << "......." << std::endl;


	system("pause");
	return 0;
}