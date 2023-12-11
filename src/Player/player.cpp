#include "player.h"

namespace GameTest
{
	Player::Player()
	{
		sprite = nullptr;
		status = STATUS::IDLE;
		speed = 0.0f;
	}

	Player::~Player()
	{
		if (sprite != nullptr)
		{
			sprite->DeInit();
			delete sprite;
			sprite = nullptr;
		}
	}

	void Player::Init(GL::Render* render, float speed, const char* textureUrl)
	{
		sprite = new GL::Sprite(render);
		sprite->Init();
		sprite->LoadTexture(textureUrl, false);
		sprite->SetPos(0.f, 55.f, 0.0f);
		sprite->SetScale(25.f, 25.f, 1.0f);
		sprite->SetMoveable(true);
		sprite->SetCollider(true);

		GL::AtlasConfig atlas = GL::AtlasConfig(6, 11, 0, 0, 1, 18);
		sprite->AddAnimation(atlas, 10.f);

		atlas = GL::AtlasConfig(6, 11, 0, 7, 1, 12);
		sprite->AddAnimation(atlas, 10.f);

		atlas = GL::AtlasConfig(6, 11, 0, 3, 1, 12);
		sprite->AddAnimation(atlas, 10.f);

		atlas = GL::AtlasConfig(6, 11, 0, 9, 1, 12);
		sprite->AddAnimation(atlas, 10.f);

		atlas = GL::AtlasConfig(6, 11, 0, 5, 1, 12);
		sprite->AddAnimation(atlas, 10.f);

		this->speed = speed;
	}

	void Player::Update(GL::Input* input)
	{
		Inputs(input);
	}

	void Player::Draw()
	{
		sprite->Draw();
	}

	void Player::DeInit()
	{
	}

	GL::Sprite* Player::GetSprite()
	{
		return sprite;
	}

	void Player::Inputs(GL::Input* input)
	{
		if (input->IsKeyPressed(KEY_A) || input->IsKeyPressed(KEY_LEFT))
		{
			//sprite->SetPos(sprite->GetPosX() - speed, sprite->GetPosY(), sprite->GetPosZ());
			ChangeStatus(STATUS::LEFT);
		}
		else if (input->IsKeyPressed(KEY_D) || input->IsKeyPressed(KEY_RIGHT))
		{
			//sprite->SetPos(sprite->GetPosX() + speed, sprite->GetPosY(), sprite->GetPosZ());
			ChangeStatus(STATUS::RIGHT);
		}
		else if (input->IsKeyPressed(KEY_W) || input->IsKeyPressed(KEY_UP))
		{
			//sprite->SetPos(sprite->GetPosX(), sprite->GetPosY() + speed, sprite->GetPosZ());
			ChangeStatus(STATUS::UP);
		}
		else if (input->IsKeyPressed(KEY_S) || input->IsKeyPressed(KEY_DOWN))
		{
			//sprite->SetPos(sprite->GetPosX(), sprite->GetPosY() - speed, sprite->GetPosZ());
			ChangeStatus(STATUS::DOWN);
		}
		else if (input->IsKeyPressed(KEY_Q))
		{
			sprite->SetRotZ(sprite->GetRotZ() - speed);
		}
		else if (input->IsKeyPressed(KEY_E))
		{
			sprite->SetRotZ(sprite->GetRotZ() + speed);
		}
		else if (input->IsKeyPressed(KEY_Z))
		{
			sprite->SetScale(sprite->GetScaleX() - speed, sprite->GetScaleY() - speed, sprite->GetScaleZ());
		}
		else if (input->IsKeyPressed(KEY_C))
		{
			sprite->SetScale(sprite->GetScaleX() + speed, sprite->GetScaleY() + speed, sprite->GetScaleZ());
		}
		else
		{
			ChangeStatus(STATUS::IDLE);
		}
	}

	void Player::Move()
	{
		switch (status)
		{
		case GameTest::STATUS::IDLE:
			break;
		case GameTest::STATUS::LEFT:
			sprite->SetPos(sprite->GetPosX() - speed, sprite->GetPosY(), sprite->GetPosZ());
			break;
		case GameTest::STATUS::RIGHT:
			sprite->SetPos(sprite->GetPosX() + speed, sprite->GetPosY(), sprite->GetPosZ());
			break;
		case GameTest::STATUS::UP:
			sprite->SetPos(sprite->GetPosX(), sprite->GetPosY() + speed, sprite->GetPosZ());
			break;
		case GameTest::STATUS::DOWN:
			sprite->SetPos(sprite->GetPosX(), sprite->GetPosY() - speed, sprite->GetPosZ());
			break;
		default:
			break;
		}
	}

	GL::Sprite* Player::GetMovePos()
	{
		GL::Sprite* moveSprite = new GL::Sprite();
		moveSprite->SetPos(sprite->GetPos());

		switch (status)
		{
		case GameTest::STATUS::IDLE:
			break;
		case GameTest::STATUS::LEFT:
			moveSprite->SetPos(moveSprite->GetPosX() - speed, moveSprite->GetPosY(), moveSprite->GetPosZ());
			break;
		case GameTest::STATUS::RIGHT:
			moveSprite->SetPos(moveSprite->GetPosX() + speed, moveSprite->GetPosY(), moveSprite->GetPosZ());
			break;
		case GameTest::STATUS::UP:
			moveSprite->SetPos(moveSprite->GetPosX(), moveSprite->GetPosY() + speed, moveSprite->GetPosZ());
			break;
		case GameTest::STATUS::DOWN:
			moveSprite->SetPos(moveSprite->GetPosX(), moveSprite->GetPosY() - speed, moveSprite->GetPosZ());
			break;
		default:
			break;
		}
		return moveSprite;
	}

	void Player::ChangeStatus(STATUS status)
	{
		this->status = status;
		sprite->ChangeAnimation(static_cast<int>(this->status));
	}
}