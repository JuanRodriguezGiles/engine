#include "collision.h"
#include <math.h>

namespace GL
{
	const float overlapSpeed = 0.35f;

	Collision::Collision()
	{
	}

	Collision::~Collision()
	{
	}

	void Collision::CollisionUpdate(Entity* entity1, Entity* entity2)
	{
		if (CheckCollisionRecRec(entity1, entity2))
		{
			std::cout << "Collision!" << std::endl;

			Overlap(entity1, entity2);
		}
	}

	bool Collision::CheckCollisionRecRec(Entity* entity1, Entity* entity2)
	{
		if (entity2->HasCollider())
		{
			bool collisionX = entity1->GetPosX() - (entity1->GetScaleX() / 2) + entity1->GetScaleX() >= entity2->GetPosX() - (entity2->GetScaleX() / 2)
				&& entity2->GetPosX() - (entity2->GetScaleX() / 2) + entity2->GetScaleX() >= entity1->GetPosX() - (entity1->GetScaleX() / 2);
			bool collisionY = entity1->GetPosY() - (entity1->GetScaleY() / 2) + entity1->GetScaleY() >= entity2->GetPosY() - (entity2->GetScaleY() / 2)
				&& entity2->GetPosY() - (entity2->GetScaleY() / 2) + entity2->GetScaleY() >= entity1->GetPosY() - (entity1->GetScaleY() / 2);
			return collisionX && collisionY;
		}

		return false;
	}

	void Collision::Overlap(Entity* entity1, Entity* entity2) 
	{
		//Check if entity is movable
		if (entity2->IsMoveable())
		{
			do
			{
				//calculate a direction based on the normalized vector from the pivot of entity1 to the pivot of entity2
				glm::vec3 director = glm::normalize(entity2->GetPivot() - entity1->GetPivot()); 
				//move ent2 away from ent1 alogn the direction
				entity2->SetPos(entity2->GetPivot() + director * overlapSpeed);
			} while (CheckCollisionRecRec(entity1, entity2)); //While colliding
		}
	}
}