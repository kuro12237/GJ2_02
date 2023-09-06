#pragma once
#include"../ITransCubeState.h"
#include"Model/Model.h"

class TransCubeLaserState:public ITransCubeState
{
public:

	void Initialize(TransCube* state)override;

	void Update(TransCube* state)override;

	void Draw(TransCube* state,ViewProjection view)override;

	void SetParent(const WorldTransform* parent)override;

private:

	void Move();


	std::unique_ptr<Model> model_ = nullptr;
	WorldTransform worldTransform_ = {};

};

