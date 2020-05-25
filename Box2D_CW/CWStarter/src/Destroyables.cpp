#include "Collidables.h"
#include "Destroyables.h"

Destroyables::Destroyables()
{
}

Destroyables::~Destroyables()
{
}

void Destroyables::ToggleDestroy()
{
	m_bDestroy = true;

}
