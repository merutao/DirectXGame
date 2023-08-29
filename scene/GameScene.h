#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Player.h"
#include "ImGuiManager.h"
#include "DebugCamera.h"
#include "Enemy.h"

#include "CollisionConfig.h"
#include "CollisionManager.h"

#include "Skydome.h"
#include "RailCamera.h"

#include <string>
#include <sstream>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void AddEnemyBullet(EnemyBullet* enemyBullet);

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	// 3Dモデルデータ
	Model* model_ = nullptr;
	Model* skyDomeModel_ = nullptr;
	// ワールドトランスフォーム
	//WorldTransform worldTransform_;
	// ビュープロジェクション
	ViewProjection viewProjection_;
	// 自キャラ
	Player* player_ = nullptr;
	// bool デバッグカメラ有効
	bool isDebugCameraActive_ = false;
	// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;

	std::list<Enemy*> enemies_;

	// 敵
	//Enemy* enemy_ = nullptr;

	CollisionManager* collisionManager_;

	SkyDome* skyDome_;

	RailCamera* railCamera_;

	std::list<EnemyBullet*> enemyBullets_;
	std::stringstream enemyPopCommands;

	bool enemyPopWait;
	int32_t enemyPopWaitTimer;

private:
	void LoadEnemyPopData();
	void UpdateEnemyPopCommands();
	void EnemySpawn(Vector3 position, Vector3 velocity);
};