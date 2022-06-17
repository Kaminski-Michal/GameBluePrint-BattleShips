#include <iostream>
#include "NotifyObservers.h"
#include "NotifyThreeBlockObserver.h"


void NotifyThreeBlockObserver::NotifyParticularObserver(int positionOfHit)
{
	std::cout << "You just hit 3 block ship\n";
}