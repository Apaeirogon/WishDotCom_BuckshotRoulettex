#pragma once

class Degats_Possible {
public:

	// Destructeur
	virtual ~Degats_Possible() = default;

	// Prendre des dégats
	virtual void prendDegats(int degats) = 0;
};