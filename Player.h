//#pragma once
//
//#define PI 3.1415926535897932384626433832795f
//
//int Thomas[10];//プレイヤーの画像
//
//extern void Player_Initialize();//
//extern void Player_Finalize();
//extern void Player_Update();	//
//extern void Player_Draw();		//
//
//const int SCREEN_WIDTH = 800;	//画面の幅
//const int SCREEN_HEIGHT = 600;	//画面の高さ
//
//const int PLAYER_POS_X = SCREEN_WIDTH / 2;		//プレイヤーのx軸は画面幅の中央
//const int PLAYER_POS_Y = SCREEN_HEIGHT + 50;	//プレイヤーのy軸は画面高さは中央寄りした
//
//const int PLAYER_SPEED = 5;	//プレイヤーのスピード
//const int PLAYER_HP = 100;	//プレイヤーのHP
//
//struct PLAYER {		//プレイヤーの設定
//	bool flg;		//フラグ判定
//	bool jump;		//ジャンプ判定
//	int x, y;		//x軸、y軸
//	int w, h;		//幅、高さ
//	int count;		//カウント
//	int speed;
//	int hp;			//HP
//	int mileage;	//マイレージ　距離
//};
//
//extern struct PLAYER mPlayer;