#ifndef NEXUS_H
#define NEXUS_H

#include "gameobject.h"

class CNexus : public CGameObject
{
public:
					CNexus(int xPos, int yPos);
	virtual			~CNexus();

	virtual void	Update(double timeElapsed);
};

#endif // !NEXUS_H
