#include "Skydome.h"
#include <cassert>

void SkyDome::Initialize(Model* model) { 
	assert(model);
	model_ = model;
	
	worldTransform_.Initialize();
	worldTransform_.scale_ = {100.0f, 100.0f, 100.0f};
	worldTransform_.UpdateMatrix();
}

void SkyDome::Update() {}

void SkyDome::Draw(const ViewProjection& viewProjection) { 
	model_->Draw(worldTransform_, viewProjection);
}