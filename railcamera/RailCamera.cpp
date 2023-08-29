#include "RailCamera.h"

void RailCamera::Initialize(const Vector3& position, const Vector3& rotation) {
	worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};
	worldTransform_.translation_ = position;
	worldTransform_.rotation_ = rotation;

	viewProjection_.Initialize();
}

void RailCamera::Update() { 
	worldTransform_.translation_.z -= 0.01f;
	//worldTransform_.rotation_.y += 0.001f;
	worldTransform_.matWorld_ = MakeAffineMatrix(
	    {1.0f, 1.0f, 1.0f}, worldTransform_.rotation_, worldTransform_.translation_);

	viewProjection_.matView = Inverse(worldTransform_.matWorld_);

	ImGui::Begin("Rail Camera");
	ImGui::DragFloat3("Camera Position", &worldTransform_.translation_.x, 0.01f);
	ImGui::DragFloat3("Camera Rotation", &worldTransform_.rotation_.x, 0.01f);
	ImGui::End();
}