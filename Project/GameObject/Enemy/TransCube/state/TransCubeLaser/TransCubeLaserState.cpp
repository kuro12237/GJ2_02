#include "TransCubeLaserState.h"

void TransCubeLaserState::Initialize(TransCube* state)
{
	model_ = std::make_unique<Model>();
	model_.get()->CreateFromOBJ("Project/Resources/EnemyObj/TransCube", "TransCube.obj");
	worldTransform_.matWorld_ = MakeIdentity4x4();
	worldTransform_.translation_ = { 0.0f,0.5f,0.0f };
	worldTransform_.scale_ = { 0.5f,0.5f,0.5f };

}

void TransCubeLaserState::Update(TransCube* state)
{
	Move();
	worldTransform_.UpdateMatrix();
}

void TransCubeLaserState::Draw(TransCube* state,ViewProjection view)
{
	model_.get()->Draw(worldTransform_,view);
}

void TransCubeLaserState::SetParent(const WorldTransform* parent)
{

	worldTransform_.parent_ = parent;

}


void TransCubeLaserState::Move()
{
	
	worldTransform_.translation_.x += 0.05f;
	worldTransform_.scale_.x += 0.05f;

}
