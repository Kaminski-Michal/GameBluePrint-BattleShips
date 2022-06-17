#include <iostream>
#include "NotifyObservers.h"
#include "NotifyOneBlockObserver.h"


void NotifyOneBlockObserver::NotifyParticularObserver(int positionOfHit)
{
	std::cout << "You just hit 1 block ship\n";
}



