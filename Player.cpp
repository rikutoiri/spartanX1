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
//	//�v���C���[�̏����ݒ�
//	mPlayer.flg = true;				//�t���O��true
//	mPlayer.x = PLAYER_POS_X;		//�v���C���[��x��
//	mPlayer.y = PLAYER_POS_Y;		//�v���C���[��y��
//	mPlayer.jump = false;			//�W�����v���ĂȂ�
//	//mPlayer.w = PLAYER_WIDTH;
//	//mPlayer.h = PLAYER_HEIGHT;
//	mPlayer.speed = PLAYER_SPEED;	//�v���C���[�̃X�s�[�h
//	mPlayer.hp = PLAYER_HP;			//�Ղꂢ��[��HP 
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
//		LoadDivGraph("images/Thomas.png", 10, 10, 1, 33, 33, Thomas);	//�摜����
//	}
//}
//
//void Player_Draw() {
//
//}