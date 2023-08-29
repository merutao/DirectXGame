#pragma once

#include "Model.h"
#include "WorldTransform.h"
#include "Input.h"
#include "CreatedMath.h"
#include "Collider.h"
#include "CollisionConfig.h"

class PlayerBullet : public Collider{
public:
	/// 初期化
	void Initialize(Model* model, const Vector3& position, const Vector3& velocity);

	void Update();

	void Draw(const ViewProjection& viewProjection);

	bool IsDead() const { return isDead_; }

	void OnCollision() override;

	Vector3 GetWorldPosition() override;

private:
	// ワールド変換データ
	WorldTransform worldTransform_;
	// モデル
	Model* model_ = nullptr;
	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;
	// 速度
	Vector3 velocity_;

	// 弾
	static const int32_t kLifeTime = 60 * 4;
	// デスタイマー
	int32_t deathTimer = kLifeTime;
	// デスフラグ
	bool isDead_ = false;
};