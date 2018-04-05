#include "particleSystem.h"

void particleSystem::update()
{
	for (int i = 0; i > pb.size(); i++) // First for loop to go through all the particles in the buffer.
	{
		for (int j = 0; j > pb.size(); j++) // 2nd for loop to check first particle's collision vs. all the other particles in the buffer.
		{
			if (i != j && pb[i].getLife() > 0 && pb[j].getLife() > 0) // Make sure that the particles aren't being collision tested on themselves and that all particles involved are still alive.
			{
				if (pb[i].checkCollision[j]) // Calls collision checker in particle class.
				{
					// Reverse VELOCITY vectors creating a 'bounce' effect.
					pb[i].getVel()[0] = -pb[i].getVel()[0];
					pb[i].getVel()[1] = -pb[i].getVel()[1];
					pb[i].getVel()[2] = -pb[i].getVel()[2];

					// Note that pb[j] POSITION isn't updated just its VELOCITY so if it collides with another particle again before it is updated it could reverse its VELOCITY again and in effect cause no change.
					// This however could be correct as it would 'bounce' from one particle to another with no net change in VELOCITY.
					// Test realism here.
					pb[j].getVel()[0] = -pb[j].getVel()[0];
					pb[j].getVel()[1] = -pb[j].getVel()[1];
					pb[j].getVel()[2] = -pb[j].getVel()[2];
				}
			}
		}

		if (pb[i].getLife() > 0) // Update the vectors for pb[i]
		{
			pb[i].getPos().add(pb[i].getVel()); // Adding the VELOCITY vector to the POSITION vector of the particle.
			pb[i].setLife(pb[i].getLife() - 1); // Taking 1 away from current LIFE value of particle.

			// Update to colour vec4 may be required as life reaches its end to change alpha channel so it fades.
		}
	}

}