#pragma once


#include"Model/Model.h"

using std::unique_ptr;


class TransCubeBullet
{
public:
	TransCubeBullet();
	~TransCubeBullet();


	void Initialize(Vector3 &velocity);

	void Update();

	void Draw(ViewProjection view);
private:

	unique_ptr<Model> model_ = nullptr;
	WorldTransform worldTransform_ = {};

	Vector3 velocity_ = {};

};



