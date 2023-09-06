#pragma once
#include"TransformationMatrix/ViewProjection.h"
#include"TransformationMatrix/WorldTransform.h"
class TransCube;

class ITransCubeState
{
public:

	virtual void Initialize(TransCube* state) = 0;

	virtual void Update(TransCube* state) = 0;

	virtual void Draw(TransCube* state,ViewProjection view) = 0;

	virtual void SetParent(const WorldTransform* parent) = 0;
private:

};

