#include"TransCube.h"

TransCube::TransCube()
{
}

TransCube::~TransCube()
{
}

void TransCube::Initialize()
{
	model_ = std::make_unique<Model>();
	worldTransform.matWorld_ = MakeIdentity4x4();
	worldTransform.scale_ = { 5,5,5 };
	model_.get()->CreateFromOBJ("Project/Resources/EnemyObj/TransCube", "TransCube.obj");

	state_ = std::make_unique<TransCubeRandBulletState>();
	state_->Initialize(this);

}

void TransCube::Update()
{


	worldTransform.rotation_.y += 0.01f;
	worldTransform.UpdateMatrix();
	state_->Update(this);
}

void TransCube::Draw(ViewProjection view)
{
	state_->Draw(this, view);
	model_.get()->Draw(worldTransform, view);

}

void TransCube::ChangeLaserState()
{
	state_.release();
	state_ = std::make_unique<TransCubeRandBulletState>();
	state_.get()->Initialize(this);
}

Vector3 TransCube::GetWorldPosition()
{
	Vector3 result = {};

	result.x = worldTransform.matWorld_.m[3][0];
	result.y = worldTransform.matWorld_.m[3][0];
	result.z = worldTransform.matWorld_.m[3][0];
	return result;
}

void TransCube::ReticlePosFanc()
{
	DirectionReticlePos_.Front = { GetWorldPosition() };
	DirectionReticlePos_.Back = { GetWorldPosition() };
	DirectionReticlePos_.Left = { GetWorldPosition() };
	DirectionReticlePos_.Right = { GetWorldPosition() };

	DirectionReticlePos_.Front.z = DirectionReticlePos_.Front.z + DirectionReticleSpace;
	DirectionReticlePos_.Back.z = DirectionReticlePos_.Back.z - DirectionReticleSpace;
	DirectionReticlePos_.Right.x = DirectionReticlePos_.Right.x + DirectionReticleSpace;
	DirectionReticlePos_.Left.x = DirectionReticlePos_.Left.x - DirectionReticleSpace;



}