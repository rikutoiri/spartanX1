#pragma once

void Game_Initialize();//������
void Game_Finalize();//�I������
void Game_Update();//�X�V
void Game_Draw();//�`��


//�L�[�擾�p�z��
static char key[256];

//x���W
static int x = 300, y = 360, y_prev = 0, y_temp = 0;

static int oldchar = 3;//�O�̉摜������

static int attack = 0;//���Ⴊ�ݍU��


static int timer = 0;//�^�C�}�[

//�W�����v���Ă邩�̃t���O�B
static bool jflag = false;
//���Ⴊ�݂��Ă��邩�̃t���O
static bool huse = false;

static bool panchi = false;

//�U�������Ƃ��ɕ������~�߂�t���O
static bool stop = false;

//�O���t�B�b�N�n���h���i�[�p�z��
static int gh[21];

//�摜�ǂݍ���
//LoadDivGraph("images/thomas2.png", 21, 3, 7, 70, 95, gh);

//�ړ��W��
static float move = 1.0f;

//�������Əc�����̃J�E���g���B
static int xcount = 0, ycount = 0;

//�Y���p�ϐ�
static int ix = 0, iy = 0, result = 0;