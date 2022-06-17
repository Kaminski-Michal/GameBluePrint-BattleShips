#include <iostream>
#include "NotifyObservers.h"
#include "NotifyFourBlockObserver.h"






void NotifyFourBlockObserver::NotifyParticularObserver(int positionOfHit)
{

	std::cout << "You just hit 4 block ship\n";
}