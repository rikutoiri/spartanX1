#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int mImageHandle; //画像ハンドル格納用変数
static int mImageChara;
//初期化
void Game_Initialize() {
	//mImageHandle = LoadGraph("images/Scene_Game.png"); //画像のロード
	mImageChara = LoadDivGraph("images/thomas2.png", 21, 3, 7, 70, 95, gh);
}

//終了処理
void Game_Finalize() {

	DeleteGraph(mImageHandle); //画像の解放
	DeleteGraph(mImageChara);
}

//更新
void Game_Update() {
	if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
		SceneMgr_ChangeScene(eScene_Menu);//シーンをメニューに変更
	}


}
//描画
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

		//画面移動制御
		if (x + (70 / 2) > 640)
			x = 640 - (70 / 2);
		if (x < (49 / 2))
			x = (49 / 2);



		//ジャンプ処理
		if (jflag == true) {			//ジャンプフラグがtrueになったら
			y_temp = y;					//tempに360を代入
			y += (y - y_prev) + 1;		//yに(y - y_prev) + 1を足す
			y_prev = y_temp;			//prevにtemp（360）を代入
			if (y == 360)				//yが360なら
				jflag = false;			//フラグをfalseにする
		}
		if (CheckHitKey(KEY_INPUT_SPACE) == 1 && jflag == false) {
			jflag = true;			//ジャンプフラグをtrueにする
			y_prev = y;				//prevに360を代入
			y = y - 20;				//yに340を代入

			if (jflag == true) {	//フラグがtrueなら
				ix = 1;			//[1]の画像を表示(ジャンプの画像)
				result = ix;		//
			}
		}

		//パンチ
		if (CheckHitKey(KEY_INPUT_Z) == 1 && panchi == false) {//Zキーを押したら
			panchi = true;			//panchiをtrueにする
			stop = true;

			if (panchi == true) {		//panchiがtrueなら
				if (oldchar == 3 || oldchar == 4 || oldchar == 5) {
					ix = 15;//右向きパンチ
					result = ix;
				}
				else if (oldchar == 6 || oldchar == 7 || oldchar == 8) {
					ix = 16;//左向きパンチ
					result = ix;

				}
			}
		}
		if (CheckHitKey(KEY_INPUT_Z) != 1 && panchi == false) {//Zキーを押されていなければ
			stop = false;
		}




		//しゃがみ
		if (CheckHitKey(KEY_INPUT_DOWN) == 1 && huse == false) {//したキーを押したら
			huse = true;			//huseをtrueにする

			if (huse == true) {		//huseがtrueなら
				if (oldchar == 3 || oldchar == 4 || oldchar == 5) {
					ix = 13;//右向きしゃがみ
					result = ix;
					if (CheckHitKey(KEY_INPUT_Z) == 1 && CheckHitKey(KEY_INPUT_DOWN) == 1)//しゃがみ攻撃
					{
						attack++;
						if (attack == 1) {//attackが１なら

							timer++;									//テスト
							if (timer < 100) {							//
								//ix += 1;								//
								//result = ix;							//
							}											//テスト
							ix += 1;	//ixに+1して
							result = ix;//攻撃画像にきりかえ

							//敵を倒すプログラムを書く

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
					ix = 10;//左向きしゃがみ
					result = ix;
					if (CheckHitKey(KEY_INPUT_Z) == 1 && CheckHitKey(KEY_INPUT_DOWN) == 1) {
						ix += 1;
						result = ix;
						//敵を倒すプログラムを書く

					}
				}
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {			//移動した際にモーションをつける
			if (stop == false) {//ストップフラグがfalse1なら
				if (xcount > 0)
					xcount = 0;
				--xcount;
			}
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {		//移動した際にモーションをつける
			if (stop == false) {//ストップフラグがfalse1なら
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

		//押されてなければカウントをゼロにする
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