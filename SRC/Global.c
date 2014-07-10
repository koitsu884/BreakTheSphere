/*----------------------------------------------------------------------*/
/*   Copyright (C) 2005 by DEA                                          */
/*----------------------------------------------------------------------*/
#include "../inc/extern.h"

char TitleString[]="�ѓI�u���b�N����";    // �^�C�g����

float       Rot;                        // ��]�p�x
int			Hitchk;						//�����蔻��t���O

float       Width;
float       Height;
float       Fov;
float       Depth;

int         vcunt;                      // V-Sync �J�E���^
int         acunt[2];                   //�L�����N�^�A�j���[�V�����J�E���^
int			tcunt;						//�ʃA�j���[�V�����J�E���^
int			ocunt[2]={0};				//�������u���b�N�p�J�E���^
int			oflag[2]={0};				//�����������t���O
int			chcunt[2]={0};				//�L������A�C�R���ω��p�J�E���^�iP1�AP2�j
int			fin=0;						//�I������p�J�E���^
int			fflag=0;					//�I���t���O
int			opflag=1;					//�I�v�V������ʕ\���p�t���O
int			tamaMotion = 3;
int			btimer[2]= {350 , 350};		//�ʂ̐ڐG���肪�o��܂ł̎���
int			Bloop1,Bloop2;				//�j��u���b�N�p�J�E���^
int			Blife[17][4];				//�u���b�N�̍d��
unsigned char	poi[2]={0};				//���_
unsigned char	cflag[2]={0};			//�ʂƂ������u���b�N�Ƃ̐ڐG����
unsigned char	Dotti[2]={0};			//P1�̋ʂ�P2�̋ʁA�ǂ��炪�������u���b�N�ƏՓ˂����̂��𔻒肷��t���O
unsigned char	Dot[2]={0};				//P1��P2�A�ǂ��炪�������𔭐��������̂��𔻒肷��t���O
unsigned char	chflag[2]={0};			//�L������A�C�R���ω��p�t���O�iP1�AP2�jchflag=0�F�ʏ��A�P:��ъ�A�Q�F�߂��݊�
unsigned char	cpuflag[2]={0 , 1};		//�v���C�����삩CPU���삩����@0:�v���C���[�A�P:CPU
unsigned char	nsel = 0;				//��Փx�Z���N�g
unsigned char	comsel = 0;				//�v���C�l���Z���N�g
unsigned char	tageChange = 0;			//COM�^�[�Q�b�g�ݒ�AI�ύX�p
unsigned int	rtime = 3000;			//�Q�[���X�^�[�g�܂ł̎���
int			i,j;						//�J�E���^�p
short		cpuKey[2];					//CPU�L�[���͓��e
int			muki[2] = {6 ,6};			//CPU�ړ��̌���

GLuint      TexNo[18];                   // �e�N�X�`���Ǘ��ԍ�

AUX_RGBImageRec    *TexImage[18];        // �e�N�X�`���f�[�^�A�h���X

char  BmpFilename0[] = "dat/samp0.bmp";		//�L�����N�^�[
char  BmpFilename1[] = "dat/samp1.bmp";		//�L�����N�^�[�Q
char  BmpFilename2[] = "dat/kabe.bmp";		//��
char  BmpFilename3[] = "dat/LIGHT.bmp";		//��
char  BmpFilename4[] = "dat/LIGHT2.bmp";	//�ʂQ
char  BmpFilename5[] = "dat/Block.bmp";		//�u���b�N
char  BmpFilename6[] = "dat/score.bmp";		//�X�R�A�\�����������L�������������u���b�N
char  BmpFilename7[] = "dat/P1_FACE.bmp";	//�L�����P�̃f�t�H������
char  BmpFilename8[] = "dat/P2_FACE.bmp";	//�L�����Q
char  BmpFilename9[] = "dat/retry.bmp";		//���g���C�\��
char  BmpFilename10[]= "dat/P1_WIN.bmp";	//�L�����P������
char  BmpFilename11[]= "dat/P1_LOS.bmp";	//�L�����P������
char  BmpFilename12[]= "dat/P2_WIN.bmp";	//�L�����Q������
char  BmpFilename13[]= "dat/P2_LOS.bmp";	//�L�����Q������
char  BmpFilename14[]= "dat/nanido.bmp";	//��Փx����
char  BmpFilename15[]= "dat/nanisel.bmp";   //��Փx�Z���N�g&�Q�[���^�C�g��
char  BmpFilename16[]= "dat/Ready.bmp";		//�Q�[���J�n�O�\������
char  BmpFilename17[]= "dat/comsel.bmp";	//�v���C�l���I��

GLuint      DspList;                    // �f�B�X�v���C���X�g�Ǘ��ԍ�
GLuint		DspList2;
GLuint		DspList3;
GLuint		DspList4;

unsigned char   keyin[2] = { 2, 2 };    // �v���C���[ 1, 2 ���̓L�[


POINT2D    PlayP[2] =					// �v���C���[�̈ʒu
{
            { -100.0f, -100.0f},			// �v���C���[�P
            { 100.0f, -100.0f},	    // �v���C���[�Q
};
POINT2D		comT[2] =
{
	{ -100.0f, -100.0f},
	{ 100.0f, -100.0f},					//CPU�ړ��ڕW�ʒu
};

POINT2D	   Iti[2] =					//�������u���b�N�̈ʒu
{
	{204.0f, 0.0f},				//�u���b�N�P
	{-204.0f,0.0f}				//�u���b�N�Q
};

BALL		Ball[8];				//�{�[�����������L�����̈ʒu�ƈړ�����

POINT2D		Bpos[17][4]={0};					//�j��u���b�N�̈ʒu



GLuint      anime[8][4] =              // �A�j���[�V�����p�^�[���o�^
{
            {  0,  1,  2,  3 },    // 1
            {  4,  5,  6,  7 },    // 2
            {  8,  9, 10, 11 },    // 3
            { 12, 13, 14, 15 },    // 4
            { 16, 17, 18, 19 },    // 6
            { 20, 21, 22, 23 },    // 7
            { 24, 25, 26, 27 },    // 8
            { 28, 29, 30, 31 },    // 9
};

GLuint		tamaAnime[9] = { 1 , 2 , 3 ,  4 , 5 , 6 , 7 , 6 , 5 }; //�ʂ̃A�j���[�V�����p�^�[��


int     KeyInT[2][8] =          // ���̓L�[�̎��
{        // �v���C���[1�̃L�[
        { 'Z',        'X',        'C',        'A',        'D',        'Q',        'W',        'E'        },
		// �v���C���[2�̃L�[
        { VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9 },
 };


KEY_MOV_TABLE   KeyMovT[8] = {          // �v���C���[�P���Q�̈ړ���
                    { -0.14f, -0.14f },  // 1 z
                    {  0.0f, -0.20f },  // 2 x
                    {  0.14f, -0.14f },  // 3 c
                    { -0.20f,  0.0f },  // 4 a
                    {  0.20f,  0.0f },  // 6 d
                    { -0.14f,  0.14f },  // 7 q
                    {  0.0f,  0.20f },  // 8 w
                    {  0.14f,  0.14f },  // 9 e
};

