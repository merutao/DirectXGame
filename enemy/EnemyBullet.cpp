#include "EnemyBullet.h"
#include "CreatedMath.h"
#include <assert.h>
#include "Player.h"

void EnemyBullet::Initialize(Model* model, const Vector3& position, const Vector3& velocity) {
	assert(model);

	textureHandle_ = TextureManager::Load("enemybullet.png");
	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	worldTransform_.scale_ = {0.5f, 0.5f, 3.0f};
	velocity_ = velocity;

	worldTransform_.rotation_.y = std::atan2(velocity_.x, velocity_.z);
	float velociteXZ = Length({velocity_.x, 0.0f, velocity_.z});
	worldTransform_.rotation_.x = std::atan2(-velocity_.y, velociteXZ);

	SetCollisionAttribute(CollisionConfig::kCollisionAttributeEnemy);
	SetCollisionMask(~CollisionConfig::kCollisionAttributeEnemy);
}

void EnemyBullet::Update() {
	/*Vector3 toPlayer = Subtract(player_->GetWorldPosition(), worldTransform_.translation_);

	toPlayer = Normalize(toPlayer);
	velocity_ = Normalize(velocity_);
	velocity_ = Slerp(0.1f, velocity_, toPlayer);

	worldTransform_.rotation_.y = std::atan2(velocity_.x, velocity_.z);
	float velociteXZ = Length({velocity_.x, 0.0f, velocity_.z});
	
	worldTransform_.rotation_.x = std::atan2(-velocity_.y, velociteXZ);*/

	worldTransform_.UpdateMatrix();

	worldTransform_.translation_ = Add(worldTransform_.translation_, velocity_);
	if (--deathTimer <= 0) {
		isDead_ = true;
	}
}

void EnemyBullet::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

void EnemyBullet::OnCollision() { 
	isDead_ = true;
}

Vector3 EnemyBullet::GetWorldPosition() {
	Vector3 worldPosition;

	worldPosition.x = worldTransform_.matWorld_.m[3][0];
	worldPosition.y = worldTransform_.matWorld_.m[3][1];
	worldPosition.z = worldTransform_.matWorld_.m[3][2];

	return worldPosition;
}