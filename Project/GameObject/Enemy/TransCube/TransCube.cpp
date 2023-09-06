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
	model_.get()->CreateFromOBJ("Project/Resources/EnemyObj/TransCube","TransCube.obj");
   
	//state_->Initialize(this);
	//state_->SetParent(&worldTransform);
}

void TransCube::Update()
{
	worldTransform.rotation_.y += 0.01f;
	worldTransform.UpdateMatrix();
	//state_->Update(this);
}

void TransCube::Draw(ViewProjection view)
{
	//state_->Draw(this,view);
	model_.get()->Draw(worldTransform, view);

}

void TransCube::ChangeLaserState()
{
	state_.release();
	//state_ = std::make_unique<TransCubeLaserState>();
	state_.get()->Initialize(this);
}
