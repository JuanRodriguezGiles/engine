#ifndef ENTITY2D_H
#define ENTITY2D_H

#include "Entity/entity.h"

namespace GL
{
	class GRAPHICSENGINE_API Entity2D : public Entity
	{
	public:
		Entity2D();
		Entity2D(Render* render);
		~Entity2D();

	private:

	};
}

#endif // !ENTITY2D_H
