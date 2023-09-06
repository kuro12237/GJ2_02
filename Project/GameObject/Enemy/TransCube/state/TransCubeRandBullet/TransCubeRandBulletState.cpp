#include "TransCubeRandBulletState.h"

TransCubeRandBulletState::TransCubeRandBulletState()
{
}

TransCubeRandBulletState::~TransCubeRandBulletState()
{
}

void TransCubeRandBulletState::Initialize(TransCube* state)
{
	CoolTime = 0;

}

void TransCubeRandBulletState::Update(TransCube* state)
{
	Vector3 FlontVelocity = Lerp(state->GetReticlePos().Front, state->GetWorldPosition(), 0);

	FlontVelocity = Normalize(FlontVelocity);
	CoolTime++;
	Fire(FlontVelocity);
	for (TransCubeBullet* bullet : bullets_)
	{
		bullet->Update();
	}

}

void TransCubeRandBulletState::Draw(TransCube* state, ViewProjection view)
{

	for (TransCubeBullet* bullet : bullets_)
	{

		bullet->Draw(view);

	}
}

void TransCubeRandBulletState::SetParent(const WorldTransform* parent)
{


}

void TransCubeRandBulletState::Fire(Vector3 velocity)
{
	if (CoolTime >= 30)
	{

		TransCubeBullet* Fbullet = new TransCubeBullet();
		Fbullet->Initialize(velocity);
		bullets_.push_back(Fbullet);

		CoolTime = 0;
	}


}