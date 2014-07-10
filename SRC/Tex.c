/*----------------------------------------------------------------------*/
/* Copyright (C) 2005 by DEA                                            */
/*----------------------------------------------------------------------*/
#include "../inc/extern.h"


/*----------------------------------------------------------------------*/
/* テクスチャ作成                                                       */
/*                                                                      */
/* char *filename : 画像ファイル名                                      */
/*----------------------------------------------------------------------*/
AUX_RGBImageRec *makeImage( char *filename )
{
    int loop1, loop2, loop3;

    AUX_RGBImageRec *image;
    FILE *fp = NULL;

    unsigned char r, g, b, a;

    unsigned char *data;

    // 作業用ポインタ
    unsigned char *rgb;
    unsigned char *rgba;


    // ファイル名が入力されていない時の処理
    if( filename == NULL )  return FALSE;

    // ファイルオープンチェック
    fp = fopen( filename, "rb" );

    // ファイルが存在しないとき
    if( fp == NULL )        return FALSE;

    // ファイルクローズ
    fclose( fp );

    // AUXコマンドの画像データロード
    image = auxDIBImageLoad( filename );

    // データ格納領域確保（ＲＧＢＡ）
    data = (unsigned char *)malloc( (image->sizeX * 4 ) * image->sizeY );
    if( data == NULL )
    {
        return FALSE;
    }

    // 作業用ポインタセット
    rgb  = image->data;
    rgba = data;

    // データコンバート RGB → RGBA
    for( loop1=0; loop1<image->sizeY; loop1++ )
    {
        for( loop2=0; loop2<image->sizeX; loop2++)
        {
            r = *(rgb+0);   // 赤
            g = *(rgb+1);   // 緑
            b = *(rgb+2);   // 青
            a = 0xFF;       // アルファー(0xFF:不透明)

            // 完全な黒色の時は透明色
            if( (r|g|b) == 0x00 )
            {
                a = 0x00;   // アルファー(0x00:透明)
            }

            // RGB データコピー
            for( loop3=0; loop3<3; loop3++ )
            {
                // RGB データ書込み
                *rgba = *rgb;
                rgba++;             // RGBA アドレスアップ
                rgb ++;             // RGB  アドレスアップ
            }

            *rgba = a;      // アルファー値書込み
            rgba++;         // RGB アドレスアップ
        }
    }

    // RGB データ領域解放
    free(image->data);

    // RGBA データ領域セット
    image->data = data;

    return image;
}


/*----------------------------------------------------------------------*/
/* テクスチャ登録処理                                                   */
/*                                                                      */
/* GLuint texno  : テクスチャ管理番号                                   */
/* char  *f_name : ファイル名                                           */
/* GLuint wrap   : テクスチャテクスチャ座標     GL_REPEAT :GL_CLAMP     */
/* GLuint filter : テクスチャ拡大・縮小補間処理 GL_NEAREST:GL_LINEAR    */
/*----------------------------------------------------------------------*/
AUX_RGBImageRec *TextureGL( GLuint texno, char *f_name, GLuint wrap, GLuint filter )
{
    AUX_RGBImageRec *image;

    // テクスチャ番号選択
    glBindTexture( GL_TEXTURE_2D, texno );

    // テクスチャ作成
    image = makeImage( f_name );
    // テクスチャ読込み失敗
    if( image == NULL ) exit(0);

    //メインメモリからVRAMに画像転送
    glTexImage2D( GL_TEXTURE_2D,                    // 2Dテクスチャ使用
                  0,                                // ミプマップレベル
                  GL_RGBA,                          // テクスチャカラー要素数
                  image->sizeX,                     // テクスチャ画像の幅   ※絵の大きさは２のｎ乗
                  image->sizeY,                     // テクスチャ画像の高さ ※絵の大きさは２のｎ乗
                  0,                                // 境界線の幅を指定 [0:1](ドット)
                  GL_RGBA,                           // 画像データのフォーマット
                  GL_UNSIGNED_BYTE,                 // 画像データのデータ形式
                  image->data );                    // メインメモリ上の画像データのアドレス


    // テクスチャパラメータ設定
    // テクスチャ座標（繰り返し・クランプ）設定
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap );     // S 座標
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap );     // T 座標

    // テクスチャ拡大・縮小補間処理
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter );    // 拡大時の設定
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter );    // 縮小時の設定

    return image;
}
