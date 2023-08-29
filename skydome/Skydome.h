#pragma once

#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"

class SkyDome {
public:
	void Initialize(Model* model);

	void Update();

	void Draw(const ViewProjection& viewProjection);

private:
	WorldTransform worldTransform_;
	Model* model_ = nullptr;
};