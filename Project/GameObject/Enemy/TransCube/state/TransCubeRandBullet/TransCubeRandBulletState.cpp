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
	ModeTimer = 0;
	rotateSpeed = 0.0001f;
	Input* input = Input::GetInstance();
	mode_ = boost;

}

void TransCubeRandBulletState::Update(TransCube* state)
{


	for (TransCubeBullet* bullet : bullets_) {

		if (bullet->GetPosition().x >= 80 || bullet->GetPosition().x <= -80)
		{
			bullet->SetIsDead(true);

		}
		if (bullet->GetPosition().z >= 80 || bullet->GetPosition().z <= -80)
		{
			bullet->SetIsDead(true);
		}

	}
	bullets_.remove_if([](TransCubeBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});



	WorldTransform GetCubeWorldTransform = state->GetWorldTransform();

	GetCubeWorldTransform.rotation_.y += rotateSpeed;
	state->SetWorldTransform(GetCubeWorldTransform);

	ModeTimer++;
	if (ModeTimer<300)
	{
		rotateSpeed += rotateSpeed*0.02f;

	}
	if (ModeTimer > 300)
	{
		if (ModeTimer <= 1200)
		{
			CoolTime++;

			Fire(state);
		}
	}
	if (ModeTimer>1200)
	{
		rotateSpeed -= rotateSpeed * 0.02f;
	}

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

void TransCubeRandBulletState::Deleate()
{

	for (TransCubeBullet* bullet : bullets_)
	{
		delete bullet;
	}

}

void TransCubeRandBulletState::Fire(TransCube *state)
{

	Vector3 Fpos = {};
	Fpos.x = state->GetReticlePos().FworldTransform.matWorld_.m[3][0];
	Fpos.y = state->GetReticlePos().FworldTransform.matWorld_.m[3][1];
	Fpos.z = state->GetReticlePos().FworldTransform.matWorld_.m[3][2];

	Vector3 Bpos = {};
	Bpos.x = state->GetReticlePos().BworldTransform.matWorld_.m[3][0];
	Bpos.y = state->GetReticlePos().BworldTransform.matWorld_.m[3][1];
	Bpos.z = state->GetReticlePos().BworldTransform.matWorld_.m[3][2];

	Vector3 Rpos = {};
	Rpos.x = state->GetReticlePos().RworldTransform.matWorld_.m[3][0];
	Rpos.y = state->GetReticlePos().RworldTransform.matWorld_.m[3][1];
	Rpos.z = state->GetReticlePos().RworldTransform.matWorld_.m[3][2];
	Vector3 Lpos = {};
	Lpos.x = state->GetReticlePos().LworldTransform.matWorld_.m[3][0];
	Lpos.y = state->GetReticlePos().LworldTransform.matWorld_.m[3][1];
	Lpos.z = state->GetReticlePos().LworldTransform.matWorld_.m[3][2];

	Vector3 FlontVelocity = VelocityFanc(state->GetWorldPosition(), Fpos);
	Vector3 BackVelocity = VelocityFanc(state->GetWorldPosition(), Bpos);
	Vector3 RightVelocity = VelocityFanc(state->GetWorldPosition(),Rpos);
	Vector3 LeftVelocity = VelocityFanc(state->GetWorldPosition(), Lpos);
	


	if (CoolTime >= 10)
	{
		BulletPushBack(FlontVelocity,state->GetWorldPosition());
		BulletPushBack(BackVelocity,state->GetWorldPosition());

		BulletPushBack(RightVelocity,state->GetWorldPosition());
		BulletPushBack(LeftVelocity,state->GetWorldPosition());

		CoolTime = 0;
	}



}

Vector3 TransCubeRandBulletState::VelocityFanc(Vector3 v1, Vector3 v2)
{
	Vector3 result = Lerp(v1, v2, 1);
	result = Normalize(result);
	return result;

}

void TransCubeRandBulletState::BulletPushBack(Vector3 v,Vector3 pos)
{
	TransCubeBullet* bullet = new TransCubeBullet();
	bullet->Initialize(v,pos);
	bullets_.push_back(bullet);

}
