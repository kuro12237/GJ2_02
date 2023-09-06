#pragma once
#include"Model/Model.h"
#include"state/ITransCubeState.h"
#include"state/TransCubeLaser/TransCubeLaserState.h"

class TransCube
{
public:
	TransCube();
	~TransCube();

	void Initialize();

	void Update();

	void Draw(ViewProjection view);

	void ChangeState(ITransCubeState *state);

private:

	std::unique_ptr<Model> model_;
	WorldTransform worldTransform = {};

	ITransCubeState* state_ = nullptr;
	
};

