#pragma once
#include"Model/Model.h"
#include"state/TransCubeRandBullet/TransCubeRandBulletState.h"
#include"Input/Input.h"
struct TransCubeReticle
{
	Vector3 Left = {};
	Vector3 Right = {};
	Vector3 Front = {};
	Vector3 Back = {};
	WorldTransform LworldTransform = {};
	WorldTransform RworldTransform = {};
	WorldTransform FworldTransform = {};
	WorldTransform BworldTransform = {};


};

class TransCube
{
public:
	TransCube();
	~TransCube();

	void Initialize();

	void Update();

	void Draw(ViewProjection view);

	void ChangeLaserState();

	Vector3 GetWorldPosition();
	TransCubeReticle GetReticlePos() { return DirectionReticlePos_; }
	WorldTransform GetWorldTransform() { return worldTransform; }
	
	void SetWorldTransform(WorldTransform w) { worldTransform = w; }


private:

	void ReticlePosFanc();

	Model*model_;
	WorldTransform worldTransform = {};


	std::unique_ptr<ITransCubeState>state_ = nullptr;

	TransCubeReticle DirectionReticlePos_ = {};

	const float DirectionReticleSpace = 5.0f;

	Input* input = nullptr;
};
