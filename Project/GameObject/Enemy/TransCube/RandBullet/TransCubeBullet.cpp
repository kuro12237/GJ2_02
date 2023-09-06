#include "TransCubeBullet.h"

TransCubeBullet::TransCubeBullet()
{
}

TransCubeBullet::~TransCubeBullet()
{
}

void TransCubeBullet::Initialize(Vector3 &velocity)
{

	model_ = std::make_unique<Model>();
	model_.get()->CreateFromOBJ("Project/Resources/EnemyObj/TransCube", "TransCube.obj");

	worldTransform_.matWorld_ = MakeIdentity4x4();
	velocity_ = velocity;


}

void TransCubeBullet::Update()
{
	//velocity_ = Multiply(velocity_, { 0.5f,0.5f,0.5f });
	worldTransform_.translation_ = Add(worldTransform_.translation_, velocity_);

	worldTransform_.UpdateMatrix();
}

void TransCubeBullet::Draw(ViewProjection view)
{
	model_.get()->Draw(worldTransform_, view);

}
