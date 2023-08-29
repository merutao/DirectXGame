#include "PlayerBullet.h"
#include <assert.h>

void PlayerBullet::Initialize(Model* model, const Vector3& position, const Vector3& velocity) {
	// NULLポインタチェック
	assert(model);
	model_ = model;

	// テクスチャ読み込む
	textureHandle_ = TextureManager::Load("black.png");
	
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.UpdateMatrix();

	velocity_ = velocity;

	SetCollisionAttribute(CollisionConfig::kCollisionAttributePlayer);
	SetCollisionMask(~CollisionConfig::kCollisionAttributePlayer);
}

void PlayerBullet::Update() {
	worldTransform_.UpdateMatrix();
	worldTransform_.translation_ = Add(worldTransform_.translation_, velocity_);
	
	 //時間経過で取り消し
	if (--deathTimer <= 0) {
		isDead_ = true;
	}
}

void PlayerBullet::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

void PlayerBullet::OnCollision() { isDead_ = true; }

Vector3 PlayerBullet::GetWorldPosition() {
	Vector3 worldPosition;

	worldPosition.x = worldTransform_.matWorld_.m[3][0];
	worldPosition.y = worldTransform_.matWorld_.m[3][1];
	worldPosition.z = worldTransform_.matWorld_.m[3][2];

	return worldPosition;
}