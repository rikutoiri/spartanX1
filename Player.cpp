//#include "DxLib.h"
//#include "SceneMgr.h"
//#include "Input.h"
//#include "Player.h"
//
//static int mImagePlayer;
//
//void Player_Initialize() {
//	mImagePlayer = LoadGraph("images/Thomas.png");
//
//	//プレイヤーの初期設定
//	mPlayer.flg = true;				//フラグをtrue
//	mPlayer.x = PLAYER_POS_X;		//プレイヤーのx軸
//	mPlayer.y = PLAYER_POS_Y;		//プレイヤーのy軸
//	mPlayer.jump = false;			//ジャンプしてない
//	//mPlayer.w = PLAYER_WIDTH;
//	//mPlayer.h = PLAYER_HEIGHT;
//	mPlayer.speed = PLAYER_SPEED;	//プレイヤーのスピード
//	mPlayer.hp = PLAYER_HP;			//ぷれいやーのHP 
//	mPlayer.mileage = 0;			//
//}
//
//void Player_Finalize() {
//	DeleteGraph(mImagePlayer);
//}
//
//void Player_Update() {
//	if (CheckHitKey(KEY_INPUT_LEFT))
//	{
//
//		LoadDivGraph("images/Thomas.png", 10, 10, 1, 33, 33, Thomas);	//画像分割
//	}
//}
//
//void Player_Draw() {
//
//}