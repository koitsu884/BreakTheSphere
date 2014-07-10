/*----------------------------------------------------------------------*/
/*   Copyright (C) 2005 by DEA                                          */
/*----------------------------------------------------------------------*/
#ifndef _MY_EXTERN_INCLUDE
#define _MY_EXTERN_INCLUDE

#include <windows.h>            /* must include this before GL/gl.h */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1415926

#define GLUT

#ifdef GLUT
    #include "GL/glut.h"                    // GLUT 宣言
                                            // ※GLUT には、OpenGL ライブラリ と
                                            //   OpenGL ユーティリティ ライブラリは
                                            //   最初から組み込まれています。
#else
    #include <GL/gl.h>                      // OpenGL ヘッダファイル
    #pragma comment (lib, "opengl32.lib")   // OpenGL ライブラリ

    #include <GL/glu.h>                     // OpenGL ユーティリティ
    #pragma comment (lib, "glu32.lib")      // OpenGL ユーティリティ ライブラリ
#endif

#include "glaux.h"                       // aux ヘッダファイル
#pragma comment (lib, "glaux.lib")          // aux ライブラリ

#include "system.h"                         // 構造体宣言等 設定ファイル




//----------------------------------------------------------------------
// グローバル変数
extern char             TitleString[];      // タイトル名


extern float            Rot;                // 回転角度
extern int				Hitchk;				//当たり判定フラグ

extern float            Width;
extern float            Height;
extern float            Fov;
extern float            Depth;

extern int              vcunt;              // V-Sync カウンタ
extern int              acunt[2];           // キャラクタアニメーションカウンタ
extern int				tcunt;				//玉アニメーションカウンタ
extern int				ocunt[2];			//お助けブロック用カウンタ
extern int				oflag[2];			//お助け発生フラグ
extern int				chcunt[2];			//キャラ顔アイコン変化用カウンタ（P1、P2）
extern int				fin;				//終了判定用カウンタ
extern int				fflag;				//終了フラグ
extern int				opflag;				//オプション画面表示用フラグ
extern int				tamaMotion;			
extern int				btimer[2];			//玉の接触判定が出るまでの時間
extern int				Bloop1,Bloop2;		//破壊ブロック用カウンタ
extern int				Blife[17][4];		//ブロックの硬さ
extern unsigned char	poi[2];				//得点
extern unsigned char	cflag[2];			//玉と邪魔ブロックとの接触判定
extern unsigned char	Dotti[2];			//P1の玉とP2の玉、どちらがお助けブロックと衝突したのかを判定するフラグ
extern unsigned char	Dot[2];				//P1とP2、どちらがお助けを発生させたのかを判定するフラグ
extern unsigned char	chflag[2];			//キャラ顔アイコン変化用フラグ　（P1、P2)　chflag=0：通常顔、１:喜び顔、２：悲しみ顔
extern unsigned char	cpuflag[2];			//プレイヤ操作かCPU操作か判定　0:プレイヤー、１:CPU
extern unsigned char	nsel;				//難易度セレクト
extern unsigned char	comsel;				//プレイ人数セレクト
extern unsigned char	tageChange;		//COMターゲット設定AI変更用
extern unsigned int			rtime;			//ゲームスタートまでの時間
extern int						i,j;
extern short			cpuKey[2];			//CPUキー入力内容
extern int				muki[2];			//CPU移動の向き

extern unsigned char    keyin1;             // 入力キー
extern unsigned char    keyin2;             // 入力キー
extern GLuint           DspList;            // ディスプレイリスト管理番号
extern GLuint			DspList2;
extern GLuint			DspList3;
extern GLuint			DspList4;
extern unsigned char    keyin[2];           // プレイヤー 1, 2 入力キー
extern POINT2D			PlayP[2];           // プレイヤーの位置
extern int              KeyInT[2][8];       // 入力キーの種類
extern KEY_MOV_TABLE    KeyMovT[8];         // プレイヤー１＆２の移動量
extern POINT2D			comT[2];			//CPU移動目標位置
extern POINT2D			Iti[2];				//邪魔ブロックの位置
extern BALL				Ball[8];			//ボールの位置と移動量
extern POINT2D			Bpos[17][4];		//破壊ブロックの位置

extern GLuint           TexNo[18];           // テクスチャ管理番号
extern AUX_RGBImageRec  *TexImage[18];       // テクスチャデータアドレス

extern char             BmpFilename0[];     // 画像ファイル名
extern char             BmpFilename1[];     // 画像ファイル名
extern char             BmpFilename2[]; 
extern char             BmpFilename3[];
extern char             BmpFilename4[];
extern char				BmpFilename5[];
extern char				BmpFilename6[];
extern char				BmpFilename7[];
extern char				BmpFilename8[];
extern char				BmpFilename9[];
extern char				BmpFilename10[];
extern char				BmpFilename11[];
extern char				BmpFilename12[];
extern char				BmpFilename13[];
extern char				BmpFilename14[];	//難易度文字
extern char				BmpFilename15[];	//難易度セレクト&ゲームタイトル
extern char				BmpFilename16[];	//ゲーム開始前表示文字
extern char				BmpFilename17[];	//プレイ人数選択

extern GLuint           anime[8][4];        // アニメーションパターン登録
extern GLuint			tamaAnime[9];		//玉のアニメーションパターン

//----------------------------------------------------------------------
// プロトタイプ宣言
extern int APIENTRY WinMain( HINSTANCE, HINSTANCE, LPSTR, int );
extern void  MainPrg( void );

extern void InitGL(void);
extern void Display( void );
extern void Reshape(int w, int h);
extern void Keyboard( unsigned char key, int x, int y );
extern void KeyChk( int playNo );
extern int HitCheck(POINT2D ply,POINT2D mono,float r1,float r2);
extern void cpuAI(POINT2D play, int playNo);
extern void CPUT(int playNo);
extern void HitBall(void);
extern void HitOtasuke(void);
extern void HitChara(void);

extern AUX_RGBImageRec *makeImage( char *filename );
extern AUX_RGBImageRec *TextureGL( GLuint texno, char *f_name, GLuint wrap, GLuint filter );


#endif