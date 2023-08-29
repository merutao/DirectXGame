#include "Enemy.h"
#include <assert.h>
#include "Player.h"
#include "GameScene.h"

Enemy::Enemy() {

}

Enemy::~Enemy() { 
	delete phase_;
}

void Enemy::Initialize(Model* model, const Vector3& position, const Vector3& velocity) { 
	assert(model);
	
	textureHandle_ = TextureManager::Load("enemy.png");
	model_ = model;

	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	velocity_ = velocity;

	phase_ = new EnemyApproach();
	phase_->Initialize(this);

	SetCollisionAttribute(CollisionConfig::kCollisionAttributeEnemy);
	SetCollisionMask(~CollisionConfig::kCollisionAttributeEnemy);
}

void Enemy::Update() { 
	/*bullets_.remove_if([](EnemyBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
	});*/

	worldTransform_.UpdateMatrix();
	phase_->Update();

	/*for (EnemyBullet* bullet : bullets_) {
		bullet->Update();
	}*/
}

void Enemy::ChangingState(EnemyState* newState) { 
	delete phase_;
	phase_ = newState;
	phase_->Initialize(this);
}

void Enemy::Move(Vector3 velocity) { 
	worldTransform_.translation_ = Add(worldTransform_.translation_, velocity);
}

void Enemy::Fire() { 
	assert(player_);

	const float kBulletSpeed = 1.0f;

	Vector3 playerPosition = player_->GetWorldPosition();
	Vector3 enemyPosition = this->GetWorldPosition();
	Vector3 velocity = Subtract(playerPosition, enemyPosition);
	velocity = Normalize(velocity);

	velocity.x *= kBulletSpeed;
	velocity.y *= kBulletSpeed;
	velocity.z *= kBulletSpeed;

	EnemyBullet* newBullet = new EnemyBullet();
	newBullet->SetPlayer(player_);

	newBullet->Initialize(model_, worldTransform_.translation_, velocity);
	//bullets_.push_back(newBullet);

	gameScene_->AddEnemyBullet(newBullet);
}

void Enemy::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}

void Enemy::OnCollision() {

}

Vector3 Enemy::GetWorldPosition() {
	Vector3 worldPosition;
	worldTransform_.UpdateMatrix();

	worldPosition.x = worldTransform_.matWorld_.m[3][0];
	worldPosition.y = worldTransform_.matWorld_.m[3][1];
	worldPosition.z = worldTransform_.matWorld_.m[3][2];
	
	return worldPosition;
}