#pragma once
#include"Model/Model.h"
#include"state/ITransCubeState.h"

class TransCube
{
public:
	TransCube();
	~TransCube();

	void Initialize();

	void Update();

	void Draw(ViewProjection view);

	void ChangeLaserState();

private:

	std::unique_ptr<Model> model_;
	WorldTransform worldTransform = {};

	//ITransCubeState* state_ = nullptr;
	
	std::unique_ptr<ITransCubeState>state_ = nullptr;
};

