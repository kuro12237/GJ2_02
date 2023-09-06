#include"TransCube.h"

TransCube::TransCube()
{
}

TransCube::~TransCube()
{
	delete state_;
}

void TransCube::Initialize()
{
	model_ = std::make_unique<Model>();
	worldTransform.matWorld_ = MakeIdentity4x4();
	model_.get()->CreateFromOBJ("Project/Resources/EnemyObj/TransCube","TransCube.obj");
    state_ = new TransCubeLaserState;
	state_->Initialize(this);
	state_->SetParent(&worldTransform);
}

void TransCube::Update()
{
	worldTransform.rotation_.y += 0.01f;
	
	worldTransform.UpdateMatrix();
	state_->Update(this);
}

void TransCube::Draw(ViewProjection view)
{
	state_->Draw(this,view);
	model_.get()->Draw(worldTransform, view);

}

void TransCube::ChangeState(ITransCubeState* state)
{
	delete state_;
	state_ = state;
	state_->Initialize(this);
}
