#pragma once

#include "WorldTransform.h"
#include "ViewProjection.h"
#include "CreatedMath.h"
#include "ImGuiManager.h"

class RailCamera {
public:
	void Initialize(const Vector3& position, const Vector3& rotation);
	void Update();
	
	const ViewProjection& GetViewProjection() { return viewProjection_; }
	const WorldTransform& GetWorldTransform() { return worldTransform_; }

private:
	WorldTransform worldTransform_;
	ViewProjection viewProjection_;
};