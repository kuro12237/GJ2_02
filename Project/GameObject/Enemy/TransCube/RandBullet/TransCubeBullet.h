#pragma once


#include"Model/Model.h"


class TransCubeBullet
{
public:
	TransCubeBullet();
	~TransCubeBullet();


	void Initialize(Vector3 velocity);

	void Update();

	void Draw(ViewProjection view);
private:



};


