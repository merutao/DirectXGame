#pragma once

#include "Vector3.h"

class Collider {
public:
	float GetRadius() const { return radius_; }
	float SetRadius(float rad) { radius_ = rad; }

	virtual ~Collider() {}
	virtual void OnCollision() = 0;
	virtual Vector3 GetWorldPosition() = 0;

	uint32_t GetCollisionAttribute() const { return collisionAttribute_; }
	void SetCollisionAttribute(uint32_t attribute) { collisionAttribute_ = attribute; }
	uint32_t GetCollisionMask() const { return collisionMask_; }
	void SetCollisionMask(uint32_t mask) { collisionMask_ = mask; }

private:
	float radius_ = 1.0f;
	uint32_t collisionAttribute_ = 0xffffffff;
	uint32_t collisionMask_ = 0xffffffff;
};