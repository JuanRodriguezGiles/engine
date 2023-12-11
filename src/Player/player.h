#ifndef PLAYER_H
#define PLAYER_H

#include "exports.h"
#include "Input/input.h"
#include "Sprite/sprite.h"

namespace GameTest
{
	enum class STATUS
	{
		IDLE,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	class GRAPHICSENGINE_API Player
	{
	public:
		Player();
		~Player();

		void Init(GL::Render* render, float speed, const char* textureUrl);
		void Update(GL::Input* input);
		void Draw();
		void DeInit();

		GL::Sprite* GetSprite();
		GL::Sprite* GetMovePos();
		void Move();

	private:
		GL::Sprite* sprite;
		STATUS status;
		float speed;

		void Inputs(GL::Input* input);
		
		void ChangeStatus(STATUS status);
	};
}

#endif // !PLAYER_H
