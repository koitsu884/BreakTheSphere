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
    #include "GL/glut.h"                    // GLUT �錾
                                            // ��GLUT �ɂ́AOpenGL ���C�u���� ��
                                            //   OpenGL ���[�e�B���e�B ���C�u������
                                            //   �ŏ�����g�ݍ��܂�Ă��܂��B
#else
    #include <GL/gl.h>                      // OpenGL �w�b�_�t�@�C��
    #pragma comment (lib, "opengl32.lib")   // OpenGL ���C�u����

    #include <GL/glu.h>                     // OpenGL ���[�e�B���e�B
    #pragma comment (lib, "glu32.lib")      // OpenGL ���[�e�B���e�B ���C�u����
#endif

#include "glaux.h"                       // aux �w�b�_�t�@�C��
#pragma comment (lib, "glaux.lib")          // aux ���C�u����

#include "system.h"                         // �\���̐錾�� �ݒ�t�@�C��




//----------------------------------------------------------------------
// �O���[�o���ϐ�
extern char             TitleString[];      // �^�C�g����


extern float            Rot;                // ��]�p�x
extern int				Hitchk;				//�����蔻��t���O

extern float            Width;
extern float            Height;
extern float            Fov;
extern float            Depth;

extern int              vcunt;              // V-Sync �J�E���^
extern int              acunt[2];           // �L�����N�^�A�j���[�V�����J�E���^
extern int				tcunt;				//�ʃA�j���[�V�����J�E���^
extern int				ocunt[2];			//�������u���b�N�p�J�E���^
extern int				oflag[2];			//�����������t���O
extern int				chcunt[2];			//�L������A�C�R���ω��p�J�E���^�iP1�AP2�j
extern int				fin;				//�I������p�J�E���^
extern int				fflag;				//�I���t���O
extern int				opflag;				//�I�v�V������ʕ\���p�t���O
extern int				tamaMotion;			
extern int				btimer[2];			//�ʂ̐ڐG���肪�o��܂ł̎���
extern int				Bloop1,Bloop2;		//�j��u���b�N�p�J�E���^
extern int				Blife[17][4];		//�u���b�N�̍d��
extern unsigned char	poi[2];				//���_
extern unsigned char	cflag[2];			//�ʂƎז��u���b�N�Ƃ̐ڐG����
extern unsigned char	Dotti[2];			//P1�̋ʂ�P2�̋ʁA�ǂ��炪�������u���b�N�ƏՓ˂����̂��𔻒肷��t���O
extern unsigned char	Dot[2];				//P1��P2�A�ǂ��炪�������𔭐��������̂��𔻒肷��t���O
extern unsigned char	chflag[2];			//�L������A�C�R���ω��p�t���O�@�iP1�AP2)�@chflag=0�F�ʏ��A�P:��ъ�A�Q�F�߂��݊�
extern unsigned char	cpuflag[2];			//�v���C�����삩CPU���삩����@0:�v���C���[�A�P:CPU
extern unsigned char	nsel;				//��Փx�Z���N�g
extern unsigned char	comsel;				//�v���C�l���Z���N�g
extern unsigned char	tageChange;		//COM�^�[�Q�b�g�ݒ�AI�ύX�p
extern unsigned int			rtime;			//�Q�[���X�^�[�g�܂ł̎���
extern int						i,j;
extern short			cpuKey[2];			//CPU�L�[���͓��e
extern int				muki[2];			//CPU�ړ��̌���

extern unsigned char    keyin1;             // ���̓L�[
extern unsigned char    keyin2;             // ���̓L�[
extern GLuint           DspList;            // �f�B�X�v���C���X�g�Ǘ��ԍ�
extern GLuint			DspList2;
extern GLuint			DspList3;
extern GLuint			DspList4;
extern unsigned char    keyin[2];           // �v���C���[ 1, 2 ���̓L�[
extern POINT2D			PlayP[2];           // �v���C���[�̈ʒu
extern int              KeyInT[2][8];       // ���̓L�[�̎��
extern KEY_MOV_TABLE    KeyMovT[8];         // �v���C���[�P���Q�̈ړ���
extern POINT2D			comT[2];			//CPU�ړ��ڕW�ʒu
extern POINT2D			Iti[2];				//�ז��u���b�N�̈ʒu
extern BALL				Ball[8];			//�{�[���̈ʒu�ƈړ���
extern POINT2D			Bpos[17][4];		//�j��u���b�N�̈ʒu

extern GLuint           TexNo[18];           // �e�N�X�`���Ǘ��ԍ�
extern AUX_RGBImageRec  *TexImage[18];       // �e�N�X�`���f�[�^�A�h���X

extern char             BmpFilename0[];     // �摜�t�@�C����
extern char             BmpFilename1[];     // �摜�t�@�C����
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
extern char				BmpFilename14[];	//��Փx����
extern char				BmpFilename15[];	//��Փx�Z���N�g&�Q�[���^�C�g��
extern char				BmpFilename16[];	//�Q�[���J�n�O�\������
extern char				BmpFilename17[];	//�v���C�l���I��

extern GLuint           anime[8][4];        // �A�j���[�V�����p�^�[���o�^
extern GLuint			tamaAnime[9];		//�ʂ̃A�j���[�V�����p�^�[��

//----------------------------------------------------------------------
// �v���g�^�C�v�錾
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