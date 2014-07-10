/*----------------------------------------------------------------------*/
/* Copyright (C) 2005 by DEA                                            */
/*----------------------------------------------------------------------*/
#include "../inc/extern.h"


/*----------------------------------------------------------------------*/
/* �e�N�X�`���쐬                                                       */
/*                                                                      */
/* char *filename : �摜�t�@�C����                                      */
/*----------------------------------------------------------------------*/
AUX_RGBImageRec *makeImage( char *filename )
{
    int loop1, loop2, loop3;

    AUX_RGBImageRec *image;
    FILE *fp = NULL;

    unsigned char r, g, b, a;

    unsigned char *data;

    // ��Ɨp�|�C���^
    unsigned char *rgb;
    unsigned char *rgba;


    // �t�@�C���������͂���Ă��Ȃ����̏���
    if( filename == NULL )  return FALSE;

    // �t�@�C���I�[�v���`�F�b�N
    fp = fopen( filename, "rb" );

    // �t�@�C�������݂��Ȃ��Ƃ�
    if( fp == NULL )        return FALSE;

    // �t�@�C���N���[�Y
    fclose( fp );

    // AUX�R�}���h�̉摜�f�[�^���[�h
    image = auxDIBImageLoad( filename );

    // �f�[�^�i�[�̈�m�ہi�q�f�a�`�j
    data = (unsigned char *)malloc( (image->sizeX * 4 ) * image->sizeY );
    if( data == NULL )
    {
        return FALSE;
    }

    // ��Ɨp�|�C���^�Z�b�g
    rgb  = image->data;
    rgba = data;

    // �f�[�^�R���o�[�g RGB �� RGBA
    for( loop1=0; loop1<image->sizeY; loop1++ )
    {
        for( loop2=0; loop2<image->sizeX; loop2++)
        {
            r = *(rgb+0);   // ��
            g = *(rgb+1);   // ��
            b = *(rgb+2);   // ��
            a = 0xFF;       // �A���t�@�[(0xFF:�s����)

            // ���S�ȍ��F�̎��͓����F
            if( (r|g|b) == 0x00 )
            {
                a = 0x00;   // �A���t�@�[(0x00:����)
            }

            // RGB �f�[�^�R�s�[
            for( loop3=0; loop3<3; loop3++ )
            {
                // RGB �f�[�^������
                *rgba = *rgb;
                rgba++;             // RGBA �A�h���X�A�b�v
                rgb ++;             // RGB  �A�h���X�A�b�v
            }

            *rgba = a;      // �A���t�@�[�l������
            rgba++;         // RGB �A�h���X�A�b�v
        }
    }

    // RGB �f�[�^�̈���
    free(image->data);

    // RGBA �f�[�^�̈�Z�b�g
    image->data = data;

    return image;
}


/*----------------------------------------------------------------------*/
/* �e�N�X�`���o�^����                                                   */
/*                                                                      */
/* GLuint texno  : �e�N�X�`���Ǘ��ԍ�                                   */
/* char  *f_name : �t�@�C����                                           */
/* GLuint wrap   : �e�N�X�`���e�N�X�`�����W     GL_REPEAT :GL_CLAMP     */
/* GLuint filter : �e�N�X�`���g��E�k����ԏ��� GL_NEAREST:GL_LINEAR    */
/*----------------------------------------------------------------------*/
AUX_RGBImageRec *TextureGL( GLuint texno, char *f_name, GLuint wrap, GLuint filter )
{
    AUX_RGBImageRec *image;

    // �e�N�X�`���ԍ��I��
    glBindTexture( GL_TEXTURE_2D, texno );

    // �e�N�X�`���쐬
    image = makeImage( f_name );
    // �e�N�X�`���Ǎ��ݎ��s
    if( image == NULL ) exit(0);

    //���C������������VRAM�ɉ摜�]��
    glTexImage2D( GL_TEXTURE_2D,                    // 2D�e�N�X�`���g�p
                  0,                                // �~�v�}�b�v���x��
                  GL_RGBA,                          // �e�N�X�`���J���[�v�f��
                  image->sizeX,                     // �e�N�X�`���摜�̕�   ���G�̑傫���͂Q�̂���
                  image->sizeY,                     // �e�N�X�`���摜�̍��� ���G�̑傫���͂Q�̂���
                  0,                                // ���E���̕����w�� [0:1](�h�b�g)
                  GL_RGBA,                           // �摜�f�[�^�̃t�H�[�}�b�g
                  GL_UNSIGNED_BYTE,                 // �摜�f�[�^�̃f�[�^�`��
                  image->data );                    // ���C����������̉摜�f�[�^�̃A�h���X


    // �e�N�X�`���p�����[�^�ݒ�
    // �e�N�X�`�����W�i�J��Ԃ��E�N�����v�j�ݒ�
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap );     // S ���W
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap );     // T ���W

    // �e�N�X�`���g��E�k����ԏ���
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter );    // �g�厞�̐ݒ�
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter );    // �k�����̐ݒ�

    return image;
}
