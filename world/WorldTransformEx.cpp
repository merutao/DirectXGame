﻿#include "WorldTransform.h"
#include "CreatedMath.h"

void WorldTransform::UpdateMatrix() {
	// スケール、回転、平行移動を合成して行列計算する
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);
	
	if (parent_) {
		matWorld_ = Multiply(matWorld_, parent_->matWorld_);
	}

	// 定数バッファに転送する
	TransferMatrix();
}