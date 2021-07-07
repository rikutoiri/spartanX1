#pragma once

void Game_Initialize();//初期化
void Game_Finalize();//終了処理
void Game_Update();//更新
void Game_Draw();//描画


//キー取得用配列
static char key[256];

//x座標
static int x = 300, y = 360, y_prev = 0, y_temp = 0;

static int oldchar = 3;//前の画像を入れる

static int attack = 0;//しゃがみ攻撃


static int timer = 0;//タイマー

//ジャンプしてるかのフラグ。
static bool jflag = false;
//しゃがみしているかのフラグ
static bool huse = false;

static bool panchi = false;

//攻撃したときに歩きを止めるフラグ
static bool stop = false;

//グラフィックハンドル格納用配列
static int gh[21];

//画像読み込み
//LoadDivGraph("images/thomas2.png", 21, 3, 7, 70, 95, gh);

//移動係数
static float move = 1.0f;

//横方向と縦方向のカウント数。
static int xcount = 0, ycount = 0;

//添字用変数
static int ix = 0, iy = 0, result = 0;