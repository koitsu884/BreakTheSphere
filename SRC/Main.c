/*----------------------------------------------------------------------*/
/* Copyright (C) 2005 by DEA                                            */
/* OpenGL �v���O����                                                    */
/*----------------------------------------------------------------------*/
#include "../inc/extern.h"


/*----------------------------------------------------------------------*/
/* ���C���v���O����                                                     */
/*----------------------------------------------------------------------*/
int APIENTRY
WinMain( HINSTANCE  hCurrentInst,
         HINSTANCE  hPreviousInst,
         LPSTR      lpszCmdLine,
         int        nCmdShow )
{
    // ���C������
    MainPrg();

    return TRUE;
}


/*----------------------------------------------------------------------*/
/* �f�B�X�v���C���X�g�o�^                                               */
/*----------------------------------------------------------------------*/
void    disp_list()
{
    GLuint loop1, loop2;

    DspList = glGenLists(32);			//�L�����N�^�[
	DspList2 = glGenLists(8);			//��
	DspList3 = glGenLists(4);			//�u���b�N
	DspList4 = glGenLists(10);			//�X�R�A

	//�L�����N�^�[�p�f�B�X�v���C���X�g
    for( loop1=0; loop1<8; loop1++ )
    {
        for( loop2=0; loop2<4; loop2++ )
        {
            // �f�B�X�v���C���X�g�ݒ�
            glNewList( DspList+loop2+(loop1*4), GL_COMPILE );

                glBegin(GL_QUADS);  // 4�P�g�̒��_��Ɨ������l�p�`�Ƃ��Ĉ������[�h
                    glTexCoord2f( 0.125f * (float)loop2    , 0.125f * (float)loop1      );
                    glVertex3f( -16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.125f * (float)(loop2+1), 0.125f * (float)loop1      );
                    glVertex3f(  16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.125f * (float)(loop2+1), 0.125f * (float)(loop1+1)  );
                    glVertex3f(  16.0f,  16.0f,  0.0f);

                    glTexCoord2f( 0.125f * (float)loop2    , 0.125f * (float)(loop1+1)  );
                    glVertex3f( -16.0f,  16.0f,  0.0f);
                glEnd();

            glEndList();
        }
    }
   
	//�ʗp�f�B�X�v���C���X�g
    for( loop1=0; loop1<2; loop1++ )
    {
        for( loop2=0; loop2<4; loop2++ )
        {
            // �f�B�X�v���C���X�g�ݒ�
            glNewList( DspList2+loop2+(loop1*4), GL_COMPILE );

                glBegin(GL_QUADS);  // 4�P�g�̒��_��Ɨ������l�p�`�Ƃ��Ĉ������[�h
                    glTexCoord2f( 0.5f * (float)loop1    , 0.25f * (float)loop2      );
                    glVertex3f( -16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.5f * (float)(loop1+1), 0.25f * (float)loop2      );
                    glVertex3f(  16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.5f * (float)(loop1+1), 0.25f * (float)(loop2+1)  );
                    glVertex3f(  16.0f,  16.0f,  0.0f);

                    glTexCoord2f( 0.5f * (float)loop1    , 0.25f * (float)(loop2+1)  );
                    glVertex3f( -16.0f,  16.0f,  0.0f);
                glEnd();

            glEndList();
        }
    }

	//�j��u���b�N�p�f�B�X�v���C���X�g
	for( loop1=0; loop1<2; loop1++ )
    {
        for( loop2=0; loop2<2; loop2++ )
        {
            // �f�B�X�v���C���X�g�ݒ�
            glNewList( DspList3+loop2+(loop1*2), GL_COMPILE );

                glBegin(GL_QUADS);  // 4�P�g�̒��_��Ɨ������l�p�`�Ƃ��Ĉ������[�h
                    glTexCoord2f( 0.5f * (float)loop1    , 0.5f * (float)loop2      );
                    glVertex3f( -16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.5f * (float)(loop1+1), 0.5f * (float)loop2      );
                    glVertex3f(  16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.5f * (float)(loop1+1), 0.5f * (float)(loop2+1)  );
                    glVertex3f(  16.0f,  16.0f,  0.0f);

                    glTexCoord2f( 0.5f * (float)loop1    , 0.5f * (float)(loop2+1)  );
                    glVertex3f( -16.0f,  16.0f,  0.0f);
                glEnd();

            glEndList();
        }
    }

	//�X�R�A�p�f�B�X�v���C���X�g
	for( loop2=0; loop2<2; loop2++ )
    {
        for( loop1=0; loop1<5; loop1++ )
        {
            // �f�B�X�v���C���X�g�ݒ�
            glNewList( DspList4+(loop2*5)+loop1, GL_COMPILE );

                glBegin(GL_QUADS);  // 4�P�g�̒��_��Ɨ������l�p�`�Ƃ��Ĉ������[�h
                    glTexCoord2f( 0.125f * (float)loop1    , 0.25f * (float)(loop2 + 2)  );
                    glVertex3f( -8.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.125f * (float)(loop1+1), 0.25f * (float)(loop2 + 2)  );
                    glVertex3f(  8.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.125f * (float)(loop1+1), 0.25f * (float)(loop2 + 3)  );
                    glVertex3f(  8.0f,  16.0f,  0.0f);

                    glTexCoord2f( 0.125f * (float)loop1    , 0.25f * (float)(loop2 + 3)  );
                    glVertex3f( -8.0f,  16.0f,  0.0f);
                glEnd();

            glEndList();
        }
    }


}

/*----------------------------------------------------------------------*/
/* �n�������f�k������                                                   */
/*----------------------------------------------------------------------*/
void InitGL(void)
{

    glEnable( GL_CULL_FACE  );          // �ʕ����N���b�s���O �n�m
    glEnable( GL_DEPTH_TEST );          // �f�B�v�X�o�b�t�@   �n�m

    glEnable( GL_TEXTURE_2D );          // �e�N�X�`���\��t�� �n�m


    // �e�N�X�`���Ǘ��ԍ��擾
    // ���� �F �ԍ��擾���C �e�N�X�`���ԍ��i�[�ϐ��̃A�h���X
    glGenTextures( 18, &TexNo[0] );

    // �P���� �摜�Ǎ���
    TexImage[0] = TextureGL( TexNo[0], BmpFilename0, GL_REPEAT, GL_NEAREST );

    // �Q���� �摜�Ǎ���
    TexImage[1] = TextureGL( TexNo[1], BmpFilename1, GL_REPEAT, GL_NEAREST );

	// �ǂ̉摜
	TexImage[2] = TextureGL( TexNo[2], BmpFilename2, GL_REPEAT, GL_NEAREST );

	//�ʂ̉摜
	TexImage[3] = TextureGL( TexNo[3], BmpFilename3, GL_REPEAT, GL_NEAREST );

	//�ʂQ�̉摜
	TexImage[4] = TextureGL( TexNo[4], BmpFilename4, GL_REPEAT, GL_NEAREST );

	//�u���b�N�̉摜
	TexImage[5] = TextureGL( TexNo[5], BmpFilename5, GL_REPEAT, GL_NEAREST );

	//���_�\���Ǝז��u���b�N�̉摜
	TexImage[6] = TextureGL( TexNo[6], BmpFilename6, GL_REPEAT, GL_NEAREST );

	//�L�����N�^�[�P�̃f�t�H������
	TexImage[7] = TextureGL( TexNo[7], BmpFilename7, GL_REPEAT, GL_NEAREST );

	//�L�����N�^�[�Q�̃f�t�H������
	TexImage[8] = TextureGL( TexNo[8], BmpFilename8, GL_REPEAT, GL_NEAREST );

	//���g���C�\��
	TexImage[9] = TextureGL( TexNo[9], BmpFilename9, GL_REPEAT, GL_NEAREST );

	//�L�����P������
	TexImage[10] = TextureGL( TexNo[10], BmpFilename10, GL_REPEAT, GL_NEAREST );

	//�L�����P������
	TexImage[11] = TextureGL( TexNo[11], BmpFilename11, GL_REPEAT, GL_NEAREST );

	//�L�����Q������
	TexImage[12] = TextureGL( TexNo[12], BmpFilename12, GL_REPEAT, GL_NEAREST );

	//�L�����Q������
	TexImage[13] = TextureGL( TexNo[13], BmpFilename13, GL_REPEAT, GL_NEAREST );

	//��Փx����
	TexImage[14] = TextureGL( TexNo[14], BmpFilename14, GL_REPEAT, GL_NEAREST );

	//��Փx�Z���N�g���Q�[���^�C�g��
	TexImage[15] = TextureGL( TexNo[15], BmpFilename15, GL_REPEAT, GL_NEAREST );

	//�Q�[���J�n�O�\������
	TexImage[16] = TextureGL( TexNo[16], BmpFilename16, GL_REPEAT, GL_NEAREST );

	//�v���C�l���I��\��
	TexImage[17] = TextureGL( TexNo[17], BmpFilename17, GL_REPEAT, GL_NEAREST );



    // �f�B�X�v���C���X�g�̓o�^
    disp_list();

	//��1�̏����ݒ�
		//�����ʒu
		Ball[0].pos.x = -100.0;
		Ball[0].pos.y = 0.0;
		//�����ړ�����
		Ball[0].mov.x = -0.15;
		Ball[0].mov.y = 0.15;

	//�ʂQ�̏����ݒ�
		//�����ʒu
        Ball[1].pos.x = 100.0;
        Ball[1].pos.y = 0.0;
		//�����ړ�����
		Ball[1].mov.x = 0.15;
		Ball[1].mov.y = 0.15;
	//�������L�����̏����ݒ�
		for(i=2 ; i<8 ; i++){
			Ball[i].pos.x = 0;
			Ball[i].pos.y = -400;
			Ball[i].mov.x = 0;
			Ball[i].mov.y = 0;
			Rot = 0;
		}
	//�j��u���b�N�̏����ݒ�

		//�u���b�N�̈ʒu�ƍd���̐ݒ�
		srand((unsigned int) time(NULL));

		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
		for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
			Bpos[Bloop1][Bloop2].x = -256.0f + (float)Bloop1 * 32.0f;	//�u���b�N�ʒu���聕�l�i�[
			Bpos[Bloop1][Bloop2].y = 216.0f - (float)Bloop2 * 32.0f;
			Blife[Bloop1][Bloop2] =(rand() % 4) + 1;		//1�`4�̃��C�t�������_���Ŋi�[
		}
	}
   // �����ݒ�

    // �������ݒ�

    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

     // �A���t�@�l�̔�r��������
    glEnable(GL_ALPHA_TEST);
    // �A���t�@�l�� 0 �ӊO�̃f�[�^����������
    glAlphaFunc(GL_NOTEQUAL, 0.0);

    // �w�i�N���A�F�ݒ�
    glClearColor( 0.0f, 0.0f, 0.1f, 1.0f );

}

/*----------------------------------------------------------------------*/
/*   �I������                                                           */
/*----------------------------------------------------------------------*/
void finish(unsigned char ten1 , unsigned char ten2)
{
	if(ten1==ten2){				//���_�Ȃ�ǂ���������\��
		i=1;
		j=1;
	}
	else if(ten1 > ten2){		//���������\��
			i=0;
			j=1;
		}
		else {
			i=1;
			j=0;
		}
		//���g���C�\��
		glBindTexture(GL_TEXTURE_2D, TexNo[9] );
		glBegin(GL_POLYGON);

		glTexCoord2f(1.0f,0.0f);
		glVertex2f(128.0f,80.0f);

		glTexCoord2f(1.0f,1.0f);
		glVertex2f(128.0f,208.0f);

		glTexCoord2f(0.0f,1.0f);
		glVertex2f(-128.0f,208.0f);

		glTexCoord2f(0.0f,0.0f);
		glVertex2f(-128.0f,80.0f);

		glEnd();
					
		//P1 ��\��
		glBindTexture(GL_TEXTURE_2D, TexNo[10+i] );
		glBegin(GL_POLYGON);

		glTexCoord2f(1.0f,0.0f);
		glVertex2f(-44.0f,-186.0f);

		glTexCoord2f(1.0f,1.0f);
		glVertex2f(-44.0f,70.0f);

		glTexCoord2f(0.0f,1.0f);
		glVertex2f(-300.0f,70.0f);

		glTexCoord2f(0.0f,0.0f);
		glVertex2f(-300.0f,-186.0f);

		glEnd();

		//P2 ��\��
		glBindTexture(GL_TEXTURE_2D, TexNo[12+j] );
		glBegin(GL_POLYGON);

		glTexCoord2f(1.0f,0.0f);
		glVertex2f(300.0f,-186.0f);

		glTexCoord2f(1.0f,1.0f);
		glVertex2f(300.0f,70.0f);

		glTexCoord2f(0.0f,1.0f);
		glVertex2f(44.0f,70.0f);

		glTexCoord2f(0.0f,0.0f);
		glVertex2f(44.0f,-186.0f);
		
		glEnd();
}
/*----------------------------------------------------------------------*/
/*   �������u���b�N����                                                 */
/*----------------------------------------------------------------------*/
void Otasuke(int LorR)
{
	for(i= (2 + LorR * 3) ; i < (5 + LorR * 3) ; i++){
		//�������L�����o���ʒu
			Ball[i].pos.x = Iti[LorR].x;		
			Ball[i].pos.y = Iti[LorR].y+30;
		//�������L�����̓����̑���
			Ball[i].mov.x = 0.299f - (0.3f) * (float)(i - 2 - LorR * 3);
			Ball[i].mov.y = 0.6f - fabs(Ball[i].mov.x);
			Rot = 0.3f;
		}
}



/*----------------------------------------------------------------------*/
/*   ���g���C����                                                       */
/*----------------------------------------------------------------------*/
void Retry(void)
{
	fflag=0;						//�I������t���O���I�t��
	poi[0]=0;						//P1�̃|�C���g���Z�b�g
	poi[1]=0;						//P2�̃|�C���g���Z�b�g
	fin=0;							//�I������J�E���^�����Z�b�g
	ocunt[0] = 0;					//�������u���b�N�P��������J�E���g���Z�b�g
	ocunt[1] = 0;					//�������u���b�N�Q
	btimer[0] = 350;				//P1�ʏo���^�C�}�[���Z�b�g
	btimer[1] = 350;				//P2
	rtime = 3000;					//�Q�[���X�^�[�g�O�����p�^�C�}�[

	PlayP[0].x = -100.0;      // �v���C���[�P
	PlayP[0].y = -100.0;

	PlayP[1].x = 100.0;		//�v���C���[�Q
	PlayP[1].y = -100.0;

	comT[0].x = -100;
	comT[0].y = -100;
	comT[1].x = 100;
	comT[1].y = -100;

	//��1�̏����ݒ�
		//�����ʒu
		Ball[0].pos.x = -100.0;
		Ball[0].pos.y = 0.0;
		//�����ړ�����
		Ball[0].mov.x = -0.075 * (float)(nsel + 1);
		Ball[0].mov.y = 0.075 * (float)(nsel + 1);

	//�ʂQ�̏����ݒ�
		//�����ʒu
        Ball[1].pos.x = 100.0;
        Ball[1].pos.y = 0.0;
		//�����ړ�����
		Ball[1].mov.x = 0.075 * (float)(nsel + 1);
		Ball[1].mov.y = 0.075 * (float)(nsel + 1);

	//�������L�����̏����ݒ�
		for(i=2 ; i<8 ; i++){
			Ball[i].pos.x = 0;
			Ball[i].pos.y = -400;
			Ball[i].mov.x = 0;
			Ball[i].mov.y = 0;
			Rot = 0;
		}

	//�j��u���b�N�̏����ݒ�

		//�u���b�N�̈ʒu�ƍd���̐ݒ�
		srand((unsigned int) time(NULL));					//�����_���������g�p
		//17�~�R��̃u���b�N�쐬
		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
		for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
			Bpos[Bloop1][Bloop2].x = -256.0f + (float)Bloop1 * 32.0f;	//�u���b�N�ʒu���聕�l�i�[
			Bpos[Bloop1][Bloop2].y = 216.0f - (float)Bloop2 * 32.0f;
			Blife[Bloop1][Bloop2] =(rand() % 4) + 1;		//1�`4�̃��C�t�������_���Ŋi�[
		}
	}
}

/*----------------------------------------------------------------------*/
/*   �I�[�v�j���O����                                                   */
/*----------------------------------------------------------------------*/
void Opning(void){
// ��ʃN���A����
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// �e�N�X�`�����p�����[�^�ݒ�
    // GL_MODULATE  �F�e�N�X�`���Ƀ|���S���̐F�ŕϒ����ĕ`��
    // GL_DECAL     �F�e�N�X�`���̐F�����̂܂ܕ`��
    // GL_BLEND     �F�e�N�X�`���ƃ|���S���̐F���������킹�ĕ`��
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // �F�f�[�^�ݒ�
    glColor4f( 1.0f, 1.0f, 1.0f, 1.0f );

	// �}�g���b�N�X���[�h�ύX�i���f���r���[�}�g���b�N�X�j
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();   // �}�g���b�N�X�̏�����

        // ���_�ʒu�ݒ�
        gluLookAt( 0.0, 0.0, Depth,      // ���_�ʒu
                   0.0, 0.0,  0.0,      // �����_�ʒu
                   0.0, 1.0,  0.0 );    // �A�b�v�x�N�g��


			//��Փx�����\��
			glBindTexture(GL_TEXTURE_2D, TexNo[14] );	

			glBegin(GL_POLYGON);

			glTexCoord2f(1.0f,0.0f);
			glVertex2f(-172.0f,-130.0f);

			glTexCoord2f(1.0f,1.0f);
			glVertex2f(-172.0f,-66.0f);

			glTexCoord2f(0.0f,1.0f);
			glVertex2f(-300.0f,-66.0f);

			glTexCoord2f(0.0f,0.0f);
			glVertex2f(-300.0f,-130.0f);

			glEnd();

			glBindTexture(GL_TEXTURE_2D, TexNo[15] );	

			//�Q�[���^�C�g���\��
			glBegin(GL_POLYGON);

			glTexCoord2f(1.0f,0.0f);
			glVertex2f(256.0f,156.0f);
	
			glTexCoord2f(1.0f,0.25f);
			glVertex2f(256.0f,220.0f);

			glTexCoord2f(0.0f,0.25f);
			glVertex2f(-256.0f,220.0f);

			glTexCoord2f(0.0f,0.0f);
			glVertex2f(-256.0f,156.0f);

			glEnd();

			//��Փx�\��
			glBegin(GL_POLYGON);

			glTexCoord2f(1.0f,1.0-(0.25f * (float)(nsel+1)));
			glVertex2f(340.0f,-130.0f);

			glTexCoord2f(1.0f,1.0-(0.25f * (float)nsel));
			glVertex2f(340.0f,-66.0f);

			glTexCoord2f(0.0f,1.0-(0.25f * (float)nsel));
			glVertex2f(-172.0f,-66.0f);

			glTexCoord2f(0.0f,1.0-(0.25f * (float)(nsel+1)));
			glVertex2f(-172.0f,-130.0f);

			glEnd();

			//�v���C�l���\��

			glBindTexture(GL_TEXTURE_2D, TexNo[17] );

			glBegin(GL_POLYGON);

			glTexCoord2f(1.0f,1.0-(0.5f * (float)(comsel+1)));
			glVertex2f(128.0f,-30.0f);

			glTexCoord2f(1.0f,1.0-(0.5f * (float)comsel));
			glVertex2f(128.0f,98.0f);

			glTexCoord2f(0.0f,1.0-(0.5f * (float)comsel));
			glVertex2f(-128.0f,98.0f);

			glTexCoord2f(0.0f,1.0-(0.5f * (float)(comsel+1)));
			glVertex2f(-128.0f,-30.0f);

			glEnd();

		

  }

/*----------------------------------------------------------------------*/
/* �����蔻��̃`�F�b�N                                                 */
/*----------------------------------------------------------------------*/

int HitCheck(POINT2D ply,POINT2D mono,float r1,float r2){
	float kyori;
	float hankeigoukei;

	kyori=(ply.x-mono.x)*(ply.x-mono.x)+(ply.y-mono.y)*(ply.y-mono.y);
	hankeigoukei=(r1+r2)*(r1+r2);

	if(kyori<=hankeigoukei)
		return TRUE;
	else
		return FALSE;
}


/*----------------------------------------------------------------------*/
/*   �\������                                                           */
/*----------------------------------------------------------------------*/
void Display( void )
{
if(opflag == 1){
		Opning();
		//��1�̏����ݒ�
		//�����ʒu
		Ball[0].pos.x = -100.0;
		Ball[0].pos.y = 0.0;
		//�����ړ�����
		Ball[0].mov.x = -0.075 * (float)(nsel + 1);
		Ball[0].mov.y = 0.075 * (float)(nsel + 1);

	//�ʂQ�̏����ݒ�
		//�����ʒu
        Ball[1].pos.x = 100.0;
        Ball[1].pos.y = 0.0;
		//�����ړ�����
		Ball[1].mov.x = 0.075 * (float)(nsel + 1);
		Ball[1].mov.y = 0.075 * (float)(nsel + 1);
		glEnd();
	}
else{
	// �L�[���͏���
	if(cpuflag[0] == 0)    KeyChk( 0 );
	else cpuAI(PlayP[0] , 0);
		
	if(cpuflag[1] == 0)    KeyChk( 1 );
	else cpuAI(PlayP[1] , 1);

    // ��ʃN���A����
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );




    // �e�N�X�`�����p�����[�^�ݒ�
    // GL_MODULATE  �F�e�N�X�`���Ƀ|���S���̐F�ŕϒ����ĕ`��
    // GL_DECAL     �F�e�N�X�`���̐F�����̂܂ܕ`��
    // GL_BLEND     �F�e�N�X�`���ƃ|���S���̐F���������킹�ĕ`��
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // �F�f�[�^�ݒ�
    glColor4f( 1.0f, 1.0f, 1.0f, 1.0f );

    // �A�j���[�V��������
	
    vcunt++;
	tcunt++;
	//�Q�[���X�^�[�g����̏���
	if(rtime > 0){
		rtime--;									//rtime��0�ɂȂ�܂ŏ������s��
		if(rtime > 1000) i=1;						//�r���ŕ\������镶�����؂�ւ��iReady��Go�j
		else i=0;
		
		glBindTexture(GL_TEXTURE_2D, TexNo[16] );	

		glBegin(GL_POLYGON);

		glTexCoord2f(1.0f,0.5f * (float)i);
		glVertex2f(256.0f,-128.0f);

		glTexCoord2f(1.0f,0.5f * (float)(i+1));
		glVertex2f(256.0f,128.0f);

		glTexCoord2f(0.0f,0.5f * (float)(i+1));
		glVertex2f(-256.0f,128.0f);

		glTexCoord2f(0.0f,0.5f * (float)i);
		glVertex2f(-256.0f,-128.0f);

		glEnd();
	}

	if(btimer[0] > 0 && rtime == 0)	btimer[0]--;	//P1�̃{�[���̏o���A�j���[�V�����p�^�C�}�[
	if(btimer[1] > 0 && rtime == 0)	btimer[1]--;	//P2
	//�Q�[���X�^�[�g����Ⴕ���̓{�[������ʊO�ɍs���Ă��܂�������btimer�ɂ�0�ȏ�̒l���i�[�����B
	//rtime���O�A�܂菀����Ԃ����������܂ł̓{�[���͏o�����Ȃ�

	if(fflag==1){					//�Q�[���I�������𖞂������Ƃ�
		glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();   // �}�g���b�N�X�̏�����

        // ���_�ʒu�ݒ�
        gluLookAt( 0.0, 0.0, Depth,      // ���_�ʒu
                   0.0, 0.0,  0.0,      // �����_�ʒu
                   0.0, 1.0,  0.0 );    // �A�b�v�x�N�g��

		finish(poi[0] , poi[1]);		//�I������
		
	}

	if( acunt[0] > 320) acunt[0] = 0;//�L�����N�^�A�j���[�V�����p�J�E���^
	if( acunt[1] > 320) acunt[1] = 0;

   	if( tcunt > 50 )				//�ʂ̃A�j���[�V����
	{
		tcunt=0;
		tamaMotion++;
		if( tamaMotion > 8 ) tamaMotion = 3;
	}
	for(i=0;i<2;i++){			//�L�����N�^��A�C�R���ω�
		if( chcunt[i] > 0) chcunt[i]--;		//chcunt���O�ɂȂ�܂Ŋ�A�C�R����ω������ĕ\��
		else chflag[i] = 0;					//chcunt���O�Ȃ�ʏ�̊��\��
	}

	//�ʂƂ������u���b�N���Փ˂������̏���(�ʂƃu���b�N���Ԃ���Ə����̊ԃu���b�N�̐F���ω�)
		if(cflag[0]>0) cflag[0]--;
		if(cflag[1]>0) cflag[1]--;

	// ����������
	//�������u���b�N�P�i���ɂ�����j
		if( ocunt[0] == 2 + nsel * 3 ){		//��Փx�ɂ���Ĕ����̂��Ղ����ω�
		Otasuke(0);							//��������������
		ocunt[0] = 0;						//�����������p�J�E���^��0�ɖ߂�
		if(Dotti[0] == 0)	Dot[0] = 0;		//�������������������ɏՓ˂��Ă����ʂ��v���C���[�P�̂��̂��ǂ���
		else				Dot[0] = 1;		//�����łȂ��ꍇ�Ȃ�v���C���[�Q
		}
	//�������u���b�N�Q�@�i�E�ɂ�����j
		if( ocunt[1] == 2 + nsel * 3 ){	
		Otasuke(1);
		ocunt[1] = 0;						//�����������p�J�E���^��0�ɖ߂�
		if(Dotti[1] == 0)	Dot[1] = 0;		//�������������������ɏՓ˂��Ă����ʂ��v���C���[�P�̂��̂��ǂ���
		else				Dot[1] = 1;		//�����łȂ��ꍇ�Ȃ�v���C���[�Q
		}
	// �}�g���b�N�X���[�h�ύX�i���f���r���[�}�g���b�N�X�j
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();   // �}�g���b�N�X�̏�����

        // ���_�ʒu�ݒ�
        gluLookAt( 0.0, 0.0, Depth,      // ���_�ʒu
                   0.0, 0.0,  0.0,      // �����_�ʒu
                   0.0, 1.0,  0.0 );    // �A�b�v�x�N�g��


		glPushMatrix();

	//�ǂ����
		glBindTexture(GL_TEXTURE_2D, TexNo[2] );

		//��̕�
		glBegin(GL_POLYGON);

		glTexCoord2f(18.0f,0.0f);
		glVertex2f(290.0f,234.0f);

		glTexCoord2f(18.0f,1.0f);
		glVertex2f(290.0f,266.0f);

		glTexCoord2f(0.0f,1.0f);
		glVertex2f(-290.0f,266.0f);

		glTexCoord2f(0.0f,0.0f);
		glVertex2f(-290.0f,234.0f);

		glEnd();

		//���̕�
		glBegin(GL_POLYGON);

		glTexCoord2f(1.0f,0.0f);
		glVertex2f(-290.0f,-262.0f);

		glTexCoord2f(1.0f,17.0f);
		glVertex2f(-290.0f,282.0f);

		glTexCoord2f(0.0f,17.0f);
		glVertex2f(-322.0f,282.0f);

		glTexCoord2f(0.0f,0.0f);
		glVertex2f(-322.0f,-262.0f);

		glEnd();

		//�E�̕�
		glBegin(GL_POLYGON);

		glTexCoord2f(1.0f,0.0f);
		glVertex2f(322.0f,-262.0f);

		glTexCoord2f(1.0f,17.0f);
		glVertex2f(322.0f,282.0f);

		glTexCoord2f(0.0f,17.0f);
		glVertex2f(290.0f,282.0f);

		glTexCoord2f(0.0f,0.0f);
		glVertex2f(290.0f,-262.0f);

		glEnd();

	//�������u���b�N
		glBindTexture(GL_TEXTURE_2D, TexNo[6] );	
		glBegin(GL_POLYGON);
		//�������u���b�N�P
		if(cflag[0] > 0){			//�ʂ��Փ˂�������͐ԐF
			glTexCoord2f(0.5f,0.0f);
			glVertex2f(Iti[0].x + 16.0f,Iti[0].y -16.0f);

			glTexCoord2f(0.5f,0.5f);
			glVertex2f(Iti[0].x + 16.0f,Iti[0].y +16.0f);

			glTexCoord2f(0.0f,0.5f);
			glVertex2f(Iti[0].x - 16.0f,Iti[0].y +16.0f);

			glTexCoord2f(0.0f,0.0f);
			glVertex2f(Iti[0].x - 16.0f,Iti[0].y -16.0f);

			glEnd();
		}

		else{					//���i�͐F
			glTexCoord2f(1.0f,0.0f);
			glVertex2f(Iti[0].x + 16.0f,Iti[0].y -16.0f);

			glTexCoord2f(1.0f,0.5f);
			glVertex2f(Iti[0].x + 16.0f,Iti[0].y +16.0f);

			glTexCoord2f(0.5f,0.5f);
			glVertex2f(Iti[0].x - 16.0f,Iti[0].y +16.0f);

			glTexCoord2f(0.5f,0.0f);
			glVertex2f(Iti[0].x - 16.0f,Iti[0].y -16.0f);

			glEnd();
		}
		//�������u���b�N�Q
		if(cflag[1] > 0){
			glBegin(GL_POLYGON);

			glTexCoord2f(0.5f,0.0f);
			glVertex2f(Iti[1].x + 16.0f,Iti[0].y -16.0f);

			glTexCoord2f(0.5f,0.5f);
			glVertex2f(Iti[1].x + 16.0f,Iti[0].y +16.0f);

			glTexCoord2f(0.0f,0.5f);
			glVertex2f(Iti[1].x - 16.0f,Iti[0].y +16.0f);

			glTexCoord2f(0.0f,0.0f);
			glVertex2f(Iti[1].x - 16.0f,Iti[0].y -16.0f);

			glEnd();
		}

		else{
			glBegin(GL_POLYGON);

			glTexCoord2f(1.0f,0.0f);
			glVertex2f(Iti[1].x + 16.0f,Iti[1].y -16.0f);

			glTexCoord2f(1.0f,0.5f);
			glVertex2f(Iti[1].x + 16.0f,Iti[1].y +16.0f);

			glTexCoord2f(0.5f,0.5f);
			glVertex2f(Iti[1].x - 16.0f,Iti[1].y +16.0f);

			glTexCoord2f(0.5f,0.0f);
			glVertex2f(Iti[1].x - 16.0f,Iti[1].y -16.0f);

			glEnd();
		}


//�L�����N�^�[�\��

	  //�v���C���[�̕\��
	for(i=0 ; i<2 ; i++){
		glPopMatrix();
		glPushMatrix();

		//���L�����A�ǁA�������u���b�N�Ƃ̐ڐG����
		HitChara();
		//���s�ړ�
		glTranslatef( PlayP[i].x, PlayP[i].y , 0);

        // �L�����N�^�\��
        // �e�N�X�`���I��
        glBindTexture(GL_TEXTURE_2D, TexNo[i] );
        // �f�B�X�v���C���X�g�Ăяo��
        glCallList( DspList + anime[ keyin[i] ][acunt[i]/80] );
	}


 
	//�ʂ̕\��
	for(i=0; i<2 ;i++){

        glPopMatrix();
		glPushMatrix();

		if(btimer[i] == 0){

		//�ǁA�L�����A�������u���b�N�Ƃ̐ڐG����
		HitBall();

		//�ʂ̈ړ�
		if(fflag==0){			//�I����������������Ă��Ȃ�
			if(Ball[i].mov.y == 0) Ball[i].mov.y = 0.001;

			Ball[i].pos.x += Ball[i].mov.x;
			Ball[i].pos.y += Ball[i].mov.y;
		}

		glTranslatef( Ball[i].pos.x , Ball[i].pos.y , 0);

		//CPU��AI
		if(cpuflag[i] == 1){
			if(Ball[i].mov.y > 0){				//�{�[����Y�����̓�������
				comT[i].x = Ball[i].pos.x;				//�ڕW�_��X���W�̓{�[����X���W
				//�{�[�������鋫�E����̈ʒu�ɂ���΁A�ڕW�_��Y���W�͂��̋��E�̂x���W�ɂȂ�
				if(Ball[i].pos.y > 40 - nsel * 90) comT[i].y = 40 - nsel * 90;
				tageChange = 0;					//�ʏ�AI�ɖ߂��i����ȏ�����AI���ς��j
			}
			else{
                if(Ball[i].pos.y < -170){		//�{�[�����قډ�ʉ��܂ł����Ă��܂�������߂ď����ʒu�ɖ߂�
					comT[i].x = -100 + 200 * i;
					comT[i].y = 40 - nsel * 90;
					tageChange = 0;
				}
				else{
					//�{�[����Y���W���v���C���[��艺�ɍs�������ɂȂ�����
					if(Ball[i].pos.y < PlayP[i].y + 5)	tageChange = 1;//AI�ύX

					if(tageChange == 1){
						comT[i].x = Ball[i].pos.x;									  //�ڕW�_��X���W�̓{�[���ʒu��X���W
						if(Ball[i].pos.y < PlayP[i].y) comT[i].y = Ball[i].pos.y - 50;//�{�[���̈ʒu��艺�ɍs�����Ƃ���
					}
				}
			}
		}
		
		
		if(Ball[i].pos.y<-300){				//�ʂ���ʊO�ɍs���Ă��܂�����ʂ������ʒu�ɖ߂�
			Ball[i].pos.x = -100.0 + (200.0 * i);
			Ball[i].pos.y = 0.0;
			Ball[i].mov.x = (-0.075 + 0.15 * i) * (float)(nsel + 1);
			Ball[i].mov.y = 0.075 * (float)(nsel + 1);

			chflag[i] = 2;					//�L������A�C�R������
			chcunt[i] = 300;				//�ύX��̊�ł��΂炭�\��

			if(poi[i] >= 3) poi[i] -= 3;	//�v���C���[�P�̓��_���}�C�i�X�����
			else poi[i] = 0;				//���_���}�C�i�X�ɂȂ鎖�͖���
			btimer[i] = 350;				//�߂����ʂ͂����ɂ͑łĂȂ�
			tamaMotion = 3;
		}



		//�ʕ\��
		
		glBindTexture(GL_TEXTURE_2D, TexNo[3+i] );

        glCallList( DspList2 + tamaAnime[tamaMotion]);
		}
		else{

			glTranslatef( Ball[i].pos.x , Ball[i].pos.y , 0);

			glBindTexture(GL_TEXTURE_2D, TexNo[3+i] );

			glCallList( DspList2 + tamaAnime[5 -(btimer[i] / 70)]);
		}

	}

//�������L�����\��
	for(i=2; i<8 ; i++){
		glPopMatrix();
		glPushMatrix();

		//�v���C���[�L�����A�ǁA�j��u���b�N�Ƃ̐ڐG����
		HitOtasuke();

		//�������L�����̈ړ�
		if(fflag==0){							//�I����������������Ă��Ȃ�������
			Ball[i].pos.x += Ball[i].mov.x;
			Ball[i].pos.y += Ball[i].mov.y;
		}

		glTranslatef( Ball[i].pos.x , Ball[i].pos.y , 0);
		Rot += 0.1;								//�����B
		glRotated( Rot ,0.0f , 0.0f , 1.0f);


		if(Ball[i].pos.y<-300){				//�ʂ���ʊO�ɍs���Ă��܂�����
			Ball[i].mov.x = 0.0f;
			Ball[i].mov.y = 0.0f;
		}
		//�������L�����\��
		//�������u���b�N�P
		if(i < 5) glBindTexture(GL_TEXTURE_2D, TexNo[7 + Dot[0]] );//P1�AP2�ǂ��炪�������C�x���g�𔭐����������ɂ��e�N�X�`����ς���
		//�������u���b�N�Q
		else	  glBindTexture(GL_TEXTURE_2D, TexNo[7 + Dot[1]] );

         glBegin(GL_QUADS);  // 4�P�g�̒��_��Ɨ������l�p�`�Ƃ��Ĉ������[�h
                    glTexCoord2f( 0.75f    , 0.0f  );
                    glVertex3f( -16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 1.0f  ,0.0f   );
                    glVertex3f(  16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 1.0f , 1.0f  );
                    glVertex3f(  16.0f,  16.0f,  0.0f);

                    glTexCoord2f( 0.75f  , 1.0f  );
                    glVertex3f( -16.0f,  16.0f,  0.0f);
                glEnd();
	}


	//�u���b�N�̕\��

		glBindTexture( GL_TEXTURE_2D,TexNo[5] );

		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
			for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
				glPopMatrix();
				glPushMatrix();

				glTranslatef( Bpos[Bloop1][Bloop2].x , Bpos[Bloop1][Bloop2].y , 0);

				if(Blife[Bloop1][Bloop2]>0){
                    glCallList( DspList3 + (Blife[Bloop1][Bloop2] -1));//�u���b�N�̃��C�t�ɂ���ČĂяo�������ς��
				}
			}
		}

		
	//�L�����N�^�[��A�C�R���\��
		for(i=0; i<2 ; i++){

			glPopMatrix();
			glPushMatrix();
			glBindTexture( GL_TEXTURE_2D,TexNo[7+i] );

			glTranslatef( -240 + (374 * i) , -210 , 0 );

			glBegin(GL_QUADS);  // 4�P�g�̒��_��Ɨ������l�p�`�Ƃ��Ĉ������[�h
                    glTexCoord2f( 0.25f * (float)chflag[i]  , 0.0f   );//chflag�̒l�ɂ���ĕ\��������ς���
                    glVertex3f( -16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.25f * (float)(chflag[i]+1), 0.0f  );
                    glVertex3f(  16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.25f * (float)(chflag[i]+1),  1.0f  );
                    glVertex3f(  16.0f,  16.0f,  0.0f);

                    glTexCoord2f( 0.25f * (float)chflag[i]    ,  1.0f  );
                    glVertex3f( -16.0f,  16.0f,  0.0f);
                glEnd();

		//�X�R�A�\��
			glBindTexture( GL_TEXTURE_2D,TexNo[6] );

			//�v���C���[�̃X�R�A
			//10�̈ʕ\��
			glTranslatef( 42 , 0 , 0);
			if(poi[i] / 10 > 0)	glCallList( DspList4 + poi[i] / 10 );
			//�P�̈ʕ\��
			glTranslatef( 18 , 0 , 0);
			glCallList( DspList4 + poi[i] % 10);

		}	
	}
	glPopMatrix();
    glFlush();                      // �����`��

    glutSwapBuffers();          // �_�u���o�b�t�@�̐؂�ւ�
    glutPostRedisplay();        // �ĕ`��w��

}



/*----------------------------------------------------------------------*/
/* ���A���^�C�� �L�[�{�[�h���͏���                                      */
/*----------------------------------------------------------------------*/
void KeyChk( int playNo )
{
    int   loop1;
    short key;

    // �v���C���[�̈ړ�����
    for( loop1=0; loop1<8; loop1++ )
    {
        // ���݉�����Ă���L�[�̏����擾
        // GetAsyncKeyState      �F�֐��Ăяo�����ɃL�[��������Ă��邩�ǂ������肵�܂��B(API)
        //                       �F��P���� �F �m�F����L�[
        //                       �F�Ԓl     �F �L�[���
        // KeyInT[playNo][loop1] �F�v���C���[�̈ړ��L�[��o�^�����ϐ�
        //                         ����F1 2 3 4 6 7 8 9
		key = GetAsyncKeyState( KeyInT[playNo][loop1] );
			

        // �L�[�̏�Ԋm�F
        if( (key&0x8000) != 0x00 )  // 0x8000 �ŏ�ʃr�b�g�� ON ���m�F
        {
            keyin[playNo] = loop1;
			acunt[playNo]++;
            PlayP[playNo].x += KeyMovT[loop1].x;
            PlayP[playNo].y += KeyMovT[loop1].y;
			break;  // loop1 ���甲����
        }
    }
}
/*----------------------------------------------------------------------*/
/* �L�[�{�[�h���͏���                                                   */
/*----------------------------------------------------------------------*/
void Keyboard( unsigned char key, int x, int y )
{
	switch( key )
    {
    case 27:
        exit(0);
        break;
    case VK_RETURN:
		if(opflag == 1){
			opflag = 0;
			if(comsel == 1) cpuflag[1] = 0;
			else cpuflag[1] = 1;
		}
        break;
	case 'n':
		//�Q�[���I���������ɉ����΃I�v�V������ʂɖ߂�
		if(fflag == 1){
			Retry();
			opflag = 1;
		}
		break;
	case 'N':
		if(fflag == 1){
			Retry();
			opflag = 1;
		}
		break;
	case 'y':
		//�Q�[���I���������ɉ����΃��g���C
		if(fflag == 1) Retry();
		break;
	case'Y':
		if(fflag == 1) Retry();
		break;
	//�I�v�V������ʓ�Փx�Z���N�g
	case '6':
		if(opflag == 1){
			if(nsel<2)nsel += 1;
		}
		break;
	case '4':
		if(opflag == 1){
			if(nsel>0) nsel -= 1;
		}
		break;
	//�I�v�V������ʃv���C�l���Z���N�g
	case '8':
		if(opflag == 1)	comsel = 0;
		break;
	case '2':
		if(opflag == 1) comsel = 1;
		break;
			

	}
	
}


/*----------------------------------------------------------------------*/
/* �c���䂩�炳�����ύX                                                 */
/*----------------------------------------------------------------------*/
void Reshape(int w, int h)
{
    float   fw, fh;

    // �L���X�g�ϊ�
    fw = (float) w;
    fh = (float) h;

    Width  = fw / 2.0f;
    Height = fh / 2.0f;

    Fov = 45.0f*PI/180.0f;

    //���s��
    Depth = Height/(float)tan( Fov / 2.0f );

    // �\���̈�ݒ�
    glViewport(0, 0, w, h);

    // �}�g���b�N�X���[�h�ύX�i�v���W�F�N�V�����}�g���b�N�X�j
    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();           // �}�g���b�N�X�̏�����
        //�ˉe�s��ݒ�
        //��p�E�A�X�y�N�g��ENear�N���b�v�EFar�N���b�v
        gluPerspective( 45.0, fw/fh, 1.0, 1000.0);


    // �}�g���b�N�X���[�h�ύX�i���f���r���[�}�g���b�N�X�j
    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();           // �}�g���b�N�X�̏�����



}


/*----------------------------------------------------------------------*/
/* ���C�����[�v����                                                     */
/*----------------------------------------------------------------------*/
void MainPrg( void )
{
    // ���C���[�ݒ�
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutInitWindowPosition( 0, 0 );                 // ���̍���̍��W (�h�b�g)
    glutInitWindowSize( 640, 480 );                 // ���̃T�C�Y
//    glutInitWindowSize(1027, 768);                  // ���̃T�C�Y
    glutCreateWindow( TitleString );                // ���쐬

//    glutFullScreen();               // �t���X�N���[��

    InitGL();                       // �n�������f�k�̏�����

    glutReshapeFunc( Reshape );     // ��ʃT�C�Y�ύX���̏����i�Ăяo�����ٰ�݁j
    glutDisplayFunc( Display );     // ��ʕ\�������i�Ăяo�����ٰ�݁j
    glutKeyboardFunc( Keyboard );   // �L�[�{�[�h���͎��̏����i�Ăяo�����ٰ��

    glutMainLoop();                 // �n�������f�k���C�����[�v
}
