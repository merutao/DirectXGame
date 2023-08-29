#pragma once

#include "Model.h"
#include "WorldTransform.h"
#include "Collider.h"

class Player;

class EnemyBullet : public Collider{
public:
	void Initialize(Model* model, const Vector3& position, const Vector3& velocity);

	void Update();

	void Draw(const ViewProjection& viewProjection);

	bool IsDead() const { return isDead_; }
	
	void OnCollision() override;

	void SetPlayer(Player* player) { player_ = player; }

	Vector3 GetWorldPosition() override;

private:
	WorldTransform worldTransform_;
	Model* model_;
	uint32_t textureHandle_;

	Vector3 velocity_;

	static const int32_t kLifeTime = 120;
	int32_t deathTimer = kLifeTime;

	bool isDead_ = false;

	Player* player_;
};