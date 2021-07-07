#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle; //�摜�n���h���i�[�p�ϐ�
static int mImageChara;
//������
void Game_Initialize() {
	//mImageHandle = LoadGraph("images/Scene_Game.png"); //�摜�̃��[�h
	mImageChara = LoadDivGraph("images/thomas2.png", 21, 3, 7, 70, 95, gh);
}

//�I������
void Game_Finalize() {

	DeleteGraph(mImageHandle); //�摜�̉��
	DeleteGraph(mImageChara);
}

//�X�V
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
		SceneMgr_ChangeScene(eScene_Menu);//�V�[�������j���[�ɕύX
	}


}
//�`��
void Game_Draw() {

	//LoadDivGraph("images/thomas2.png", 21, 3, 7, 70, 95, gh);
	if (CheckHitKey(KEY_INPUT_LEFT) == 1 || CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			move = 1.0f;
		}
		else if (CheckHitKey(KEY_INPUT_UP) == 1 || CheckHitKey(KEY_INPUT_DOWN) == 1) {
			move = 1.0f;
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			if (stop == false)
				x -= (int)4 * move;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			if (stop == false)
			x += (int)4 * move;
		}

		//��ʈړ�����
		if (x + (70 / 2) > 640)
			x = 640 - (70 / 2);
		if (x < (49 / 2))
			x = (49 / 2);



		//�W�����v����
		if (jflag == true) {			//�W�����v�t���O��true�ɂȂ�����
			y_temp = y;					//temp��360����
			y += (y - y_prev) + 1;		//y��(y - y_prev) + 1�𑫂�
			y_prev = y_temp;			//prev��temp�i360�j����
			if (y == 360)				//y��360�Ȃ�
				jflag = false;			//�t���O��false�ɂ���
		}
		if (CheckHitKey(KEY_INPUT_SPACE) == 1 && jflag == false) {
			jflag = true;			//�W�����v�t���O��true�ɂ���
			y_prev = y;				//prev��360����
			y = y - 20;				//y��340����

			if (jflag == true) {	//�t���O��true�Ȃ�
				ix = 1;			//[1]�̉摜��\��(�W�����v�̉摜)
				result = ix;		//
			}
		}

		//�p���`
		if (CheckHitKey(KEY_INPUT_Z) == 1 && panchi == false) {//Z�L�[����������
			panchi = true;			//panchi��true�ɂ���
			stop = true;

			if (panchi == true) {		//panchi��true�Ȃ�
				if (oldchar == 3 || oldchar == 4 || oldchar == 5) {
					ix = 15;//�E�����p���`
					result = ix;
				}
				else if (oldchar == 6 || oldchar == 7 || oldchar == 8) {
					ix = 16;//�������p���`
					result = ix;

				}
			}
		}
		if (CheckHitKey(KEY_INPUT_Z) != 1 && panchi == false) {//Z�L�[��������Ă��Ȃ����
			stop = false;
		}




		//���Ⴊ��
		if (CheckHitKey(KEY_INPUT_DOWN) == 1 && huse == false) {//�����L�[����������
			huse = true;			//huse��true�ɂ���

			if (huse == true) {		//huse��true�Ȃ�
				if (oldchar == 3 || oldchar == 4 || oldchar == 5) {
					ix = 13;//�E�������Ⴊ��
					result = ix;
					if (CheckHitKey(KEY_INPUT_Z) == 1 && CheckHitKey(KEY_INPUT_DOWN) == 1)//���Ⴊ�ݍU��
					{
						attack++;
						if (attack == 1) {//attack���P�Ȃ�

							timer++;									//�e�X�g
							if (timer < 100) {							//
								//ix += 1;								//
								//result = ix;							//
							}											//�e�X�g
							ix += 1;	//ix��+1����
							result = ix;//�U���摜�ɂ��肩��

							//�G��|���v���O����������

						}
					}
					else if (attack > 0)
					{
						attack = -1;
					}
					else {
						attack = 0;
					}
				}
				else  if (oldchar == 6 || oldchar == 7 || oldchar == 8) {
					ix = 10;//���������Ⴊ��
					result = ix;
					if (CheckHitKey(KEY_INPUT_Z) == 1 && CheckHitKey(KEY_INPUT_DOWN) == 1) {
						ix += 1;
						result = ix;
						//�G��|���v���O����������

					}
				}
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {			//�ړ������ۂɃ��[�V����������
			if (stop == false) {//�X�g�b�v�t���O��false1�Ȃ�
				if (xcount > 0)
					xcount = 0;
				--xcount;
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {		//�ړ������ۂɃ��[�V����������
			if (stop == false) {//�X�g�b�v�t���O��false1�Ȃ�
				if (xcount < 0)
					xcount = 0;
				++xcount;
			}
		}

		//
		ix = abs(xcount) % 30 / 10;
		iy = abs(ycount) % 30 / 10;

		//
		if (xcount > 0) {
			ix += 3;
			result = ix;
			oldchar = ix;
		}
		else if (xcount < 0) {
			ix += 6;
			result = ix;
			oldchar = ix;
		}

		DrawGraph(x - (70 / 2), y - (95 / 2), gh[result], TRUE);

		//������ĂȂ���΃J�E���g���[���ɂ���
		if (CheckHitKey(KEY_INPUT_LEFT) != 1 && CheckHitKey(KEY_INPUT_RIGHT) != 1) {
			xcount = 0;

			panchi = false;
			huse = false;
			if (panchi == false) {
				ix += 3;
				result = oldchar;
			}
			if (huse == false) {
				ix += 3;
				result = oldchar;
			}
		}

}