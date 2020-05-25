#pragma once

 class Destroyables 
{
private:
	bool m_bDestroy = false;

public:

	Destroyables();
	~Destroyables();
	void ToggleDestroy(); //!< Sets the chosen reference to be destroyed (enemy, item, weapon instance)

};