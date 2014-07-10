/*----------------------------------------------------------------------*/
/*   Copyright (C) 2005 by DEA                                          */
/*----------------------------------------------------------------------*/
#include "../inc/extern.h"

char TitleString[]="林的ブロック崩し";    // タイトル名

float       Rot;                        // 回転角度
int			Hitchk;						//当たり判定フラグ

float       Width;
float       Height;
float       Fov;
float       Depth;

int         vcunt;                      // V-Sync カウンタ
int         acunt[2];                   //キャラクタアニメーションカウンタ
int			tcunt;						//玉アニメーションカウンタ
int			ocunt[2]={0};				//お助けブロック用カウンタ
int			oflag[2]={0};				//お助け発生フラグ
int			chcunt[2]={0};				//キャラ顔アイコン変化用カウンタ（P1、P2）
int			fin=0;						//終了判定用カウンタ
int			fflag=0;					//終了フラグ
int			opflag=1;					//オプション画面表示用フラグ
int			tamaMotion = 3;
int			btimer[2]= {350 , 350};		//玉の接触判定が出るまでの時間
int			Bloop1,Bloop2;				//破壊ブロック用カウンタ
int			Blife[17][4];				//ブロックの硬さ
unsigned char	poi[2]={0};				//得点
unsigned char	cflag[2]={0};			//玉とお助けブロックとの接触判定
unsigned char	Dotti[2]={0};			//P1の玉とP2の玉、どちらがお助けブロックと衝突したのかを判定するフラグ
unsigned char	Dot[2]={0};				//P1とP2、どちらがお助けを発生させたのかを判定するフラグ
unsigned char	chflag[2]={0};			//キャラ顔アイコン変化用フラグ（P1、P2）chflag=0：通常顔、１:喜び顔、２：悲しみ顔
unsigned char	cpuflag[2]={0 , 1};		//プレイヤ操作かCPU操作か判定　0:プレイヤー、１:CPU
unsigned char	nsel = 0;				//難易度セレクト
unsigned char	comsel = 0;				//プレイ人数セレクト
unsigned char	tageChange = 0;			//COMターゲット設定AI変更用
unsigned int	rtime = 3000;			//ゲームスタートまでの時間
int			i,j;						//カウンタ用
short		cpuKey[2];					//CPUキー入力内容
int			muki[2] = {6 ,6};			//CPU移動の向き

GLuint      TexNo[18];                   // テクスチャ管理番号

AUX_RGBImageRec    *TexImage[18];        // テクスチャデータアドレス

char  BmpFilename0[] = "dat/samp0.bmp";		//キャラクター
char  BmpFilename1[] = "dat/samp1.bmp";		//キャラクター２
char  BmpFilename2[] = "dat/kabe.bmp";		//壁
char  BmpFilename3[] = "dat/LIGHT.bmp";		//玉
char  BmpFilename4[] = "dat/LIGHT2.bmp";	//玉２
char  BmpFilename5[] = "dat/Block.bmp";		//ブロック
char  BmpFilename6[] = "dat/score.bmp";		//スコア表示＆お助けキャラ＆お助けブロック
char  BmpFilename7[] = "dat/P1_FACE.bmp";	//キャラ１のデフォルメ顔
char  BmpFilename8[] = "dat/P2_FACE.bmp";	//キャラ２
char  BmpFilename9[] = "dat/retry.bmp";		//リトライ表示
char  BmpFilename10[]= "dat/P1_WIN.bmp";	//キャラ１勝利顔
char  BmpFilename11[]= "dat/P1_LOS.bmp";	//キャラ１負け顔
char  BmpFilename12[]= "dat/P2_WIN.bmp";	//キャラ２勝利顔
char  BmpFilename13[]= "dat/P2_LOS.bmp";	//キャラ２負け顔
char  BmpFilename14[]= "dat/nanido.bmp";	//難易度文字
char  BmpFilename15[]= "dat/nanisel.bmp";   //難易度セレクト&ゲームタイトル
char  BmpFilename16[]= "dat/Ready.bmp";		//ゲーム開始前表示文字
char  BmpFilename17[]= "dat/comsel.bmp";	//プレイ人数選択

GLuint      DspList;                    // ディスプレイリスト管理番号
GLuint		DspList2;
GLuint		DspList3;
GLuint		DspList4;

unsigned char   keyin[2] = { 2, 2 };    // プレイヤー 1, 2 入力キー


POINT2D    PlayP[2] =					// プレイヤーの位置
{
            { -100.0f, -100.0f},			// プレイヤー１
            { 100.0f, -100.0f},	    // プレイヤー２
};
POINT2D		comT[2] =
{
	{ -100.0f, -100.0f},
	{ 100.0f, -100.0f},					//CPU移動目標位置
};

POINT2D	   Iti[2] =					//お助けブロックの位置
{
	{204.0f, 0.0f},				//ブロック１
	{-204.0f,0.0f}				//ブロック２
};

BALL		Ball[8];				//ボール＆お助けキャラの位置と移動距離

POINT2D		Bpos[17][4]={0};					//破壊ブロックの位置



GLuint      anime[8][4] =              // アニメーションパターン登録
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

GLuint		tamaAnime[9] = { 1 , 2 , 3 ,  4 , 5 , 6 , 7 , 6 , 5 }; //玉のアニメーションパターン


int     KeyInT[2][8] =          // 入力キーの種類
{        // プレイヤー1のキー
        { 'Z',        'X',        'C',        'A',        'D',        'Q',        'W',        'E'        },
		// プレイヤー2のキー
        { VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9 },
 };


KEY_MOV_TABLE   KeyMovT[8] = {          // プレイヤー１＆２の移動量
                    { -0.14f, -0.14f },  // 1 z
                    {  0.0f, -0.20f },  // 2 x
                    {  0.14f, -0.14f },  // 3 c
                    { -0.20f,  0.0f },  // 4 a
                    {  0.20f,  0.0f },  // 6 d
                    { -0.14f,  0.14f },  // 7 q
                    {  0.0f,  0.20f },  // 8 w
                    {  0.14f,  0.14f },  // 9 e
};

