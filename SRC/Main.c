/*----------------------------------------------------------------------*/
/* Copyright (C) 2005 by DEA                                            */
/* OpenGL プログラム                                                    */
/*----------------------------------------------------------------------*/
#include "../inc/extern.h"


/*----------------------------------------------------------------------*/
/* メインプログラム                                                     */
/*----------------------------------------------------------------------*/
int APIENTRY
WinMain( HINSTANCE  hCurrentInst,
         HINSTANCE  hPreviousInst,
         LPSTR      lpszCmdLine,
         int        nCmdShow )
{
    // メイン処理
    MainPrg();

    return TRUE;
}


/*----------------------------------------------------------------------*/
/* ディスプレイリスト登録                                               */
/*----------------------------------------------------------------------*/
void    disp_list()
{
    GLuint loop1, loop2;

    DspList = glGenLists(32);			//キャラクター
	DspList2 = glGenLists(8);			//玉
	DspList3 = glGenLists(4);			//ブロック
	DspList4 = glGenLists(10);			//スコア

	//キャラクター用ディスプレイリスト
    for( loop1=0; loop1<8; loop1++ )
    {
        for( loop2=0; loop2<4; loop2++ )
        {
            // ディスプレイリスト設定
            glNewList( DspList+loop2+(loop1*4), GL_COMPILE );

                glBegin(GL_QUADS);  // 4つ１組の頂点を独立した四角形として扱うモード
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
   
	//玉用ディスプレイリスト
    for( loop1=0; loop1<2; loop1++ )
    {
        for( loop2=0; loop2<4; loop2++ )
        {
            // ディスプレイリスト設定
            glNewList( DspList2+loop2+(loop1*4), GL_COMPILE );

                glBegin(GL_QUADS);  // 4つ１組の頂点を独立した四角形として扱うモード
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

	//破壊ブロック用ディスプレイリスト
	for( loop1=0; loop1<2; loop1++ )
    {
        for( loop2=0; loop2<2; loop2++ )
        {
            // ディスプレイリスト設定
            glNewList( DspList3+loop2+(loop1*2), GL_COMPILE );

                glBegin(GL_QUADS);  // 4つ１組の頂点を独立した四角形として扱うモード
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

	//スコア用ディスプレイリスト
	for( loop2=0; loop2<2; loop2++ )
    {
        for( loop1=0; loop1<5; loop1++ )
        {
            // ディスプレイリスト設定
            glNewList( DspList4+(loop2*5)+loop1, GL_COMPILE );

                glBegin(GL_QUADS);  // 4つ１組の頂点を独立した四角形として扱うモード
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
/* ＯｐｅｎＧＬ初期化                                                   */
/*----------------------------------------------------------------------*/
void InitGL(void)
{

    glEnable( GL_CULL_FACE  );          // 面方向クリッピング ＯＮ
    glEnable( GL_DEPTH_TEST );          // ディプスバッファ   ＯＮ

    glEnable( GL_TEXTURE_2D );          // テクスチャ貼り付け ＯＮ


    // テクスチャ管理番号取得
    // 引数 ： 番号取得数， テクスチャ番号格納変数のアドレス
    glGenTextures( 18, &TexNo[0] );

    // １枚目 画像読込み
    TexImage[0] = TextureGL( TexNo[0], BmpFilename0, GL_REPEAT, GL_NEAREST );

    // ２枚目 画像読込み
    TexImage[1] = TextureGL( TexNo[1], BmpFilename1, GL_REPEAT, GL_NEAREST );

	// 壁の画像
	TexImage[2] = TextureGL( TexNo[2], BmpFilename2, GL_REPEAT, GL_NEAREST );

	//玉の画像
	TexImage[3] = TextureGL( TexNo[3], BmpFilename3, GL_REPEAT, GL_NEAREST );

	//玉２の画像
	TexImage[4] = TextureGL( TexNo[4], BmpFilename4, GL_REPEAT, GL_NEAREST );

	//ブロックの画像
	TexImage[5] = TextureGL( TexNo[5], BmpFilename5, GL_REPEAT, GL_NEAREST );

	//得点表示と邪魔ブロックの画像
	TexImage[6] = TextureGL( TexNo[6], BmpFilename6, GL_REPEAT, GL_NEAREST );

	//キャラクター１のデフォルメ顔
	TexImage[7] = TextureGL( TexNo[7], BmpFilename7, GL_REPEAT, GL_NEAREST );

	//キャラクター２のデフォルメ顔
	TexImage[8] = TextureGL( TexNo[8], BmpFilename8, GL_REPEAT, GL_NEAREST );

	//リトライ表示
	TexImage[9] = TextureGL( TexNo[9], BmpFilename9, GL_REPEAT, GL_NEAREST );

	//キャラ１勝ち顔
	TexImage[10] = TextureGL( TexNo[10], BmpFilename10, GL_REPEAT, GL_NEAREST );

	//キャラ１負け顔
	TexImage[11] = TextureGL( TexNo[11], BmpFilename11, GL_REPEAT, GL_NEAREST );

	//キャラ２勝ち顔
	TexImage[12] = TextureGL( TexNo[12], BmpFilename12, GL_REPEAT, GL_NEAREST );

	//キャラ２負け顔
	TexImage[13] = TextureGL( TexNo[13], BmpFilename13, GL_REPEAT, GL_NEAREST );

	//難易度文字
	TexImage[14] = TextureGL( TexNo[14], BmpFilename14, GL_REPEAT, GL_NEAREST );

	//難易度セレクト＆ゲームタイトル
	TexImage[15] = TextureGL( TexNo[15], BmpFilename15, GL_REPEAT, GL_NEAREST );

	//ゲーム開始前表示文字
	TexImage[16] = TextureGL( TexNo[16], BmpFilename16, GL_REPEAT, GL_NEAREST );

	//プレイ人数選択表示
	TexImage[17] = TextureGL( TexNo[17], BmpFilename17, GL_REPEAT, GL_NEAREST );



    // ディスプレイリストの登録
    disp_list();

	//玉1の初期設定
		//初期位置
		Ball[0].pos.x = -100.0;
		Ball[0].pos.y = 0.0;
		//初期移動方向
		Ball[0].mov.x = -0.15;
		Ball[0].mov.y = 0.15;

	//玉２の初期設定
		//初期位置
        Ball[1].pos.x = 100.0;
        Ball[1].pos.y = 0.0;
		//初期移動方向
		Ball[1].mov.x = 0.15;
		Ball[1].mov.y = 0.15;
	//お助けキャラの初期設定
		for(i=2 ; i<8 ; i++){
			Ball[i].pos.x = 0;
			Ball[i].pos.y = -400;
			Ball[i].mov.x = 0;
			Ball[i].mov.y = 0;
			Rot = 0;
		}
	//破壊ブロックの初期設定

		//ブロックの位置と硬さの設定
		srand((unsigned int) time(NULL));

		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
		for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
			Bpos[Bloop1][Bloop2].x = -256.0f + (float)Bloop1 * 32.0f;	//ブロック位置決定＆値格納
			Bpos[Bloop1][Bloop2].y = 216.0f - (float)Bloop2 * 32.0f;
			Blife[Bloop1][Bloop2] =(rand() % 4) + 1;		//1～4のライフをランダムで格納
		}
	}
   // 透明設定

    // 混合率設定

    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

     // アルファ値の比較書き込み
    glEnable(GL_ALPHA_TEST);
    // アルファ値が 0 意外のデータを書き込む
    glAlphaFunc(GL_NOTEQUAL, 0.0);

    // 背景クリア色設定
    glClearColor( 0.0f, 0.0f, 0.1f, 1.0f );

}

/*----------------------------------------------------------------------*/
/*   終了処理                                                           */
/*----------------------------------------------------------------------*/
void finish(unsigned char ten1 , unsigned char ten2)
{
	if(ten1==ten2){				//同点ならどちらも負け表示
		i=1;
		j=1;
	}
	else if(ten1 > ten2){		//勝ち負け表示
			i=0;
			j=1;
		}
		else {
			i=1;
			j=0;
		}
		//リトライ表示
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
					
		//P1 顔表示
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

		//P2 顔表示
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
/*   お助けブロック処理                                                 */
/*----------------------------------------------------------------------*/
void Otasuke(int LorR)
{
	for(i= (2 + LorR * 3) ; i < (5 + LorR * 3) ; i++){
		//お助けキャラ出現位置
			Ball[i].pos.x = Iti[LorR].x;		
			Ball[i].pos.y = Iti[LorR].y+30;
		//お助けキャラの動きの早さ
			Ball[i].mov.x = 0.299f - (0.3f) * (float)(i - 2 - LorR * 3);
			Ball[i].mov.y = 0.6f - fabs(Ball[i].mov.x);
			Rot = 0.3f;
		}
}



/*----------------------------------------------------------------------*/
/*   リトライ処理                                                       */
/*----------------------------------------------------------------------*/
void Retry(void)
{
	fflag=0;						//終了判定フラグをオフに
	poi[0]=0;						//P1のポイントリセット
	poi[1]=0;						//P2のポイントリセット
	fin=0;							//終了判定カウンタをリセット
	ocunt[0] = 0;					//お助けブロック１発生判定カウントリセット
	ocunt[1] = 0;					//お助けブロック２
	btimer[0] = 350;				//P1玉出現タイマーリセット
	btimer[1] = 350;				//P2
	rtime = 3000;					//ゲームスタート前処理用タイマー

	PlayP[0].x = -100.0;      // プレイヤー１
	PlayP[0].y = -100.0;

	PlayP[1].x = 100.0;		//プレイヤー２
	PlayP[1].y = -100.0;

	comT[0].x = -100;
	comT[0].y = -100;
	comT[1].x = 100;
	comT[1].y = -100;

	//玉1の初期設定
		//初期位置
		Ball[0].pos.x = -100.0;
		Ball[0].pos.y = 0.0;
		//初期移動方向
		Ball[0].mov.x = -0.075 * (float)(nsel + 1);
		Ball[0].mov.y = 0.075 * (float)(nsel + 1);

	//玉２の初期設定
		//初期位置
        Ball[1].pos.x = 100.0;
        Ball[1].pos.y = 0.0;
		//初期移動方向
		Ball[1].mov.x = 0.075 * (float)(nsel + 1);
		Ball[1].mov.y = 0.075 * (float)(nsel + 1);

	//お助けキャラの初期設定
		for(i=2 ; i<8 ; i++){
			Ball[i].pos.x = 0;
			Ball[i].pos.y = -400;
			Ball[i].mov.x = 0;
			Ball[i].mov.y = 0;
			Rot = 0;
		}

	//破壊ブロックの初期設定

		//ブロックの位置と硬さの設定
		srand((unsigned int) time(NULL));					//ランダム数字を使用
		//17個×３列のブロック作成
		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
		for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
			Bpos[Bloop1][Bloop2].x = -256.0f + (float)Bloop1 * 32.0f;	//ブロック位置決定＆値格納
			Bpos[Bloop1][Bloop2].y = 216.0f - (float)Bloop2 * 32.0f;
			Blife[Bloop1][Bloop2] =(rand() % 4) + 1;		//1～4のライフをランダムで格納
		}
	}
}

/*----------------------------------------------------------------------*/
/*   オープニング処理                                                   */
/*----------------------------------------------------------------------*/
void Opning(void){
// 画面クリア処理
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// テクスチャ環境パラメータ設定
    // GL_MODULATE  ：テクスチャにポリゴンの色で変調して描画
    // GL_DECAL     ：テクスチャの色をそのまま描画
    // GL_BLEND     ：テクスチャとポリゴンの色を混ぜ合わせて描画
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // 色データ設定
    glColor4f( 1.0f, 1.0f, 1.0f, 1.0f );

	// マトリックスモード変更（モデルビューマトリックス）
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();   // マトリックスの初期化

        // 視点位置設定
        gluLookAt( 0.0, 0.0, Depth,      // 視点位置
                   0.0, 0.0,  0.0,      // 注視点位置
                   0.0, 1.0,  0.0 );    // アップベクトル


			//難易度文字表示
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

			//ゲームタイトル表示
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

			//難易度表示
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

			//プレイ人数表示

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
/* 当たり判定のチェック                                                 */
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
/*   表示処理                                                           */
/*----------------------------------------------------------------------*/
void Display( void )
{
if(opflag == 1){
		Opning();
		//玉1の初期設定
		//初期位置
		Ball[0].pos.x = -100.0;
		Ball[0].pos.y = 0.0;
		//初期移動方向
		Ball[0].mov.x = -0.075 * (float)(nsel + 1);
		Ball[0].mov.y = 0.075 * (float)(nsel + 1);

	//玉２の初期設定
		//初期位置
        Ball[1].pos.x = 100.0;
        Ball[1].pos.y = 0.0;
		//初期移動方向
		Ball[1].mov.x = 0.075 * (float)(nsel + 1);
		Ball[1].mov.y = 0.075 * (float)(nsel + 1);
		glEnd();
	}
else{
	// キー入力処理
	if(cpuflag[0] == 0)    KeyChk( 0 );
	else cpuAI(PlayP[0] , 0);
		
	if(cpuflag[1] == 0)    KeyChk( 1 );
	else cpuAI(PlayP[1] , 1);

    // 画面クリア処理
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );




    // テクスチャ環境パラメータ設定
    // GL_MODULATE  ：テクスチャにポリゴンの色で変調して描画
    // GL_DECAL     ：テクスチャの色をそのまま描画
    // GL_BLEND     ：テクスチャとポリゴンの色を混ぜ合わせて描画
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

    // 色データ設定
    glColor4f( 1.0f, 1.0f, 1.0f, 1.0f );

    // アニメーション処理
	
    vcunt++;
	tcunt++;
	//ゲームスタート直後の処理
	if(rtime > 0){
		rtime--;									//rtimeが0になるまで処理を行う
		if(rtime > 1000) i=1;						//途中で表示される文字が切り替わる（Ready→Go）
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

	if(btimer[0] > 0 && rtime == 0)	btimer[0]--;	//P1のボールの出現アニメーション用タイマー
	if(btimer[1] > 0 && rtime == 0)	btimer[1]--;	//P2
	//ゲームスタート直後若しくはボールが画面外に行ってしまった時にbtimerには0以上の値が格納される。
	//rtimeが０、つまり準備状態が解除されるまではボールは出現しない

	if(fflag==1){					//ゲーム終了条件を満たしたとき
		glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();   // マトリックスの初期化

        // 視点位置設定
        gluLookAt( 0.0, 0.0, Depth,      // 視点位置
                   0.0, 0.0,  0.0,      // 注視点位置
                   0.0, 1.0,  0.0 );    // アップベクトル

		finish(poi[0] , poi[1]);		//終了処理
		
	}

	if( acunt[0] > 320) acunt[0] = 0;//キャラクタアニメーション用カウンタ
	if( acunt[1] > 320) acunt[1] = 0;

   	if( tcunt > 50 )				//玉のアニメーション
	{
		tcunt=0;
		tamaMotion++;
		if( tamaMotion > 8 ) tamaMotion = 3;
	}
	for(i=0;i<2;i++){			//キャラクタ顔アイコン変化
		if( chcunt[i] > 0) chcunt[i]--;		//chcuntが０になるまで顔アイコンを変化させて表示
		else chflag[i] = 0;					//chcuntが０なら通常の顔を表示
	}

	//玉とお助けブロックが衝突した時の処理(玉とブロックがぶつかると少しの間ブロックの色が変化)
		if(cflag[0]>0) cflag[0]--;
		if(cflag[1]>0) cflag[1]--;

	// お助け発生
	//お助けブロック１（左にある方）
		if( ocunt[0] == 2 + nsel * 3 ){		//難易度によって発生のし易さが変化
		Otasuke(0);							//お助け発生処理
		ocunt[0] = 0;						//お助け発生用カウンタは0に戻す
		if(Dotti[0] == 0)	Dot[0] = 0;		//お助けが発生した時に衝突していた玉がプレイヤー１のものかどうか
		else				Dot[0] = 1;		//そうでない場合ならプレイヤー２
		}
	//お助けブロック２　（右にある方）
		if( ocunt[1] == 2 + nsel * 3 ){	
		Otasuke(1);
		ocunt[1] = 0;						//お助け発生用カウンタは0に戻す
		if(Dotti[1] == 0)	Dot[1] = 0;		//お助けが発生した時に衝突していた玉がプレイヤー１のものかどうか
		else				Dot[1] = 1;		//そうでない場合ならプレイヤー２
		}
	// マトリックスモード変更（モデルビューマトリックス）
        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();   // マトリックスの初期化

        // 視点位置設定
        gluLookAt( 0.0, 0.0, Depth,      // 視点位置
                   0.0, 0.0,  0.0,      // 注視点位置
                   0.0, 1.0,  0.0 );    // アップベクトル


		glPushMatrix();

	//壁を作る
		glBindTexture(GL_TEXTURE_2D, TexNo[2] );

		//上の壁
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

		//左の壁
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

		//右の壁
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

	//お助けブロック
		glBindTexture(GL_TEXTURE_2D, TexNo[6] );	
		glBegin(GL_POLYGON);
		//お助けブロック１
		if(cflag[0] > 0){			//玉が衝突した直後は赤色
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

		else{					//普段は青色
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
		//お助けブロック２
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


//キャラクター表示

	  //プレイヤーの表示
	for(i=0 ; i<2 ; i++){
		glPopMatrix();
		glPushMatrix();

		//他キャラ、壁、お助けブロックとの接触処理
		HitChara();
		//平行移動
		glTranslatef( PlayP[i].x, PlayP[i].y , 0);

        // キャラクタ表示
        // テクスチャ選択
        glBindTexture(GL_TEXTURE_2D, TexNo[i] );
        // ディスプレイリスト呼び出し
        glCallList( DspList + anime[ keyin[i] ][acunt[i]/80] );
	}


 
	//玉の表示
	for(i=0; i<2 ;i++){

        glPopMatrix();
		glPushMatrix();

		if(btimer[i] == 0){

		//壁、キャラ、お助けブロックとの接触処理
		HitBall();

		//玉の移動
		if(fflag==0){			//終了条件が満たされていない
			if(Ball[i].mov.y == 0) Ball[i].mov.y = 0.001;

			Ball[i].pos.x += Ball[i].mov.x;
			Ball[i].pos.y += Ball[i].mov.y;
		}

		glTranslatef( Ball[i].pos.x , Ball[i].pos.y , 0);

		//CPUのAI
		if(cpuflag[i] == 1){
			if(Ball[i].mov.y > 0){				//ボールのY方向の動きが正
				comT[i].x = Ball[i].pos.x;				//目標点のX座標はボールのX座標
				//ボールがある境界より上の位置にあれば、目標点のY座標はその境界のＹ座標になる
				if(Ball[i].pos.y > 40 - nsel * 90) comT[i].y = 40 - nsel * 90;
				tageChange = 0;					//通常AIに戻す（特殊な条件でAIが変わる）
			}
			else{
                if(Ball[i].pos.y < -170){		//ボールがほぼ画面下までいってしまったら諦めて初期位置に戻る
					comT[i].x = -100 + 200 * i;
					comT[i].y = 40 - nsel * 90;
					tageChange = 0;
				}
				else{
					//ボールのY座標がプレイヤーより下に行きそうになったら
					if(Ball[i].pos.y < PlayP[i].y + 5)	tageChange = 1;//AI変更

					if(tageChange == 1){
						comT[i].x = Ball[i].pos.x;									  //目標点のX座標はボール位置のX座標
						if(Ball[i].pos.y < PlayP[i].y) comT[i].y = Ball[i].pos.y - 50;//ボールの位置より下に行こうとする
					}
				}
			}
		}
		
		
		if(Ball[i].pos.y<-300){				//玉が画面外に行ってしまったら玉を初期位置に戻す
			Ball[i].pos.x = -100.0 + (200.0 * i);
			Ball[i].pos.y = 0.0;
			Ball[i].mov.x = (-0.075 + 0.15 * i) * (float)(nsel + 1);
			Ball[i].mov.y = 0.075 * (float)(nsel + 1);

			chflag[i] = 2;					//キャラ顔アイコン→悲
			chcunt[i] = 300;				//変更後の顔でしばらく表示

			if(poi[i] >= 3) poi[i] -= 3;	//プレイヤー１の得点がマイナスされる
			else poi[i] = 0;				//得点がマイナスになる事は無い
			btimer[i] = 350;				//戻った玉はすぐには打てない
			tamaMotion = 3;
		}



		//玉表示
		
		glBindTexture(GL_TEXTURE_2D, TexNo[3+i] );

        glCallList( DspList2 + tamaAnime[tamaMotion]);
		}
		else{

			glTranslatef( Ball[i].pos.x , Ball[i].pos.y , 0);

			glBindTexture(GL_TEXTURE_2D, TexNo[3+i] );

			glCallList( DspList2 + tamaAnime[5 -(btimer[i] / 70)]);
		}

	}

//お助けキャラ表示
	for(i=2; i<8 ; i++){
		glPopMatrix();
		glPushMatrix();

		//プレイヤーキャラ、壁、破壊ブロックとの接触処理
		HitOtasuke();

		//お助けキャラの移動
		if(fflag==0){							//終了条件が満たされていなかったら
			Ball[i].pos.x += Ball[i].mov.x;
			Ball[i].pos.y += Ball[i].mov.y;
		}

		glTranslatef( Ball[i].pos.x , Ball[i].pos.y , 0);
		Rot += 0.1;								//回る回る。
		glRotated( Rot ,0.0f , 0.0f , 1.0f);


		if(Ball[i].pos.y<-300){				//玉が画面外に行ってしまったら
			Ball[i].mov.x = 0.0f;
			Ball[i].mov.y = 0.0f;
		}
		//お助けキャラ表示
		//お助けブロック１
		if(i < 5) glBindTexture(GL_TEXTURE_2D, TexNo[7 + Dot[0]] );//P1、P2どちらがお助けイベントを発生させたかによりテクスチャを変える
		//お助けブロック２
		else	  glBindTexture(GL_TEXTURE_2D, TexNo[7 + Dot[1]] );

         glBegin(GL_QUADS);  // 4つ１組の頂点を独立した四角形として扱うモード
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


	//ブロックの表示

		glBindTexture( GL_TEXTURE_2D,TexNo[5] );

		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
			for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
				glPopMatrix();
				glPushMatrix();

				glTranslatef( Bpos[Bloop1][Bloop2].x , Bpos[Bloop1][Bloop2].y , 0);

				if(Blife[Bloop1][Bloop2]>0){
                    glCallList( DspList3 + (Blife[Bloop1][Bloop2] -1));//ブロックのライフによって呼び出す物が変わる
				}
			}
		}

		
	//キャラクター顔アイコン表示
		for(i=0; i<2 ; i++){

			glPopMatrix();
			glPushMatrix();
			glBindTexture( GL_TEXTURE_2D,TexNo[7+i] );

			glTranslatef( -240 + (374 * i) , -210 , 0 );

			glBegin(GL_QUADS);  // 4つ１組の頂点を独立した四角形として扱うモード
                    glTexCoord2f( 0.25f * (float)chflag[i]  , 0.0f   );//chflagの値によって表示する顔を変える
                    glVertex3f( -16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.25f * (float)(chflag[i]+1), 0.0f  );
                    glVertex3f(  16.0f, -16.0f,  0.0f);

                    glTexCoord2f( 0.25f * (float)(chflag[i]+1),  1.0f  );
                    glVertex3f(  16.0f,  16.0f,  0.0f);

                    glTexCoord2f( 0.25f * (float)chflag[i]    ,  1.0f  );
                    glVertex3f( -16.0f,  16.0f,  0.0f);
                glEnd();

		//スコア表示
			glBindTexture( GL_TEXTURE_2D,TexNo[6] );

			//プレイヤーのスコア
			//10の位表示
			glTranslatef( 42 , 0 , 0);
			if(poi[i] / 10 > 0)	glCallList( DspList4 + poi[i] / 10 );
			//１の位表示
			glTranslatef( 18 , 0 , 0);
			glCallList( DspList4 + poi[i] % 10);

		}	
	}
	glPopMatrix();
    glFlush();                      // 強制描画

    glutSwapBuffers();          // ダブルバッファの切り替え
    glutPostRedisplay();        // 再描画指示

}



/*----------------------------------------------------------------------*/
/* リアルタイム キーボード入力処理                                      */
/*----------------------------------------------------------------------*/
void KeyChk( int playNo )
{
    int   loop1;
    short key;

    // プレイヤーの移動処理
    for( loop1=0; loop1<8; loop1++ )
    {
        // 現在押されているキーの情報を取得
        // GetAsyncKeyState      ：関数呼び出し時にキーが押されているかどうか判定します。(API)
        //                       ：第１引数 ： 確認するキー
        //                       ：返値     ： キー情報
        // KeyInT[playNo][loop1] ：プレイヤーの移動キーを登録した変数
        //                         ※例：1 2 3 4 6 7 8 9
		key = GetAsyncKeyState( KeyInT[playNo][loop1] );
			

        // キーの状態確認
        if( (key&0x8000) != 0x00 )  // 0x8000 最上位ビットが ON か確認
        {
            keyin[playNo] = loop1;
			acunt[playNo]++;
            PlayP[playNo].x += KeyMovT[loop1].x;
            PlayP[playNo].y += KeyMovT[loop1].y;
			break;  // loop1 から抜ける
        }
    }
}
/*----------------------------------------------------------------------*/
/* キーボード入力処理                                                   */
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
		//ゲーム終了処理中に押せばオプション画面に戻る
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
		//ゲーム終了処理中に押せばリトライ
		if(fflag == 1) Retry();
		break;
	case'Y':
		if(fflag == 1) Retry();
		break;
	//オプション画面難易度セレクト
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
	//オプション画面プレイ人数セレクト
	case '8':
		if(opflag == 1)	comsel = 0;
		break;
	case '2':
		if(opflag == 1) comsel = 1;
		break;
			

	}
	
}


/*----------------------------------------------------------------------*/
/* 縦横比からさいず変更                                                 */
/*----------------------------------------------------------------------*/
void Reshape(int w, int h)
{
    float   fw, fh;

    // キャスト変換
    fw = (float) w;
    fh = (float) h;

    Width  = fw / 2.0f;
    Height = fh / 2.0f;

    Fov = 45.0f*PI/180.0f;

    //奥行き
    Depth = Height/(float)tan( Fov / 2.0f );

    // 表示領域設定
    glViewport(0, 0, w, h);

    // マトリックスモード変更（プロジェクションマトリックス）
    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();           // マトリックスの初期化
        //射影行列設定
        //画角・アスペクト比・Nearクリップ・Farクリップ
        gluPerspective( 45.0, fw/fh, 1.0, 1000.0);


    // マトリックスモード変更（モデルビューマトリックス）
    glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();           // マトリックスの初期化



}


/*----------------------------------------------------------------------*/
/* メインループ処理                                                     */
/*----------------------------------------------------------------------*/
void MainPrg( void )
{
    // レイヤー設定
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutInitWindowPosition( 0, 0 );                 // 窓の左上の座標 (ドット)
    glutInitWindowSize( 640, 480 );                 // 窓のサイズ
//    glutInitWindowSize(1027, 768);                  // 窓のサイズ
    glutCreateWindow( TitleString );                // 窓作成

//    glutFullScreen();               // フルスクリーン

    InitGL();                       // ＯｐｅｎＧＬの初期化

    glutReshapeFunc( Reshape );     // 画面サイズ変更時の処理（呼び出しｻﾌﾞﾙｰﾁﾝ）
    glutDisplayFunc( Display );     // 画面表示処理（呼び出しｻﾌﾞﾙｰﾁﾝ）
    glutKeyboardFunc( Keyboard );   // キーボード入力時の処理（呼び出しｻﾌﾞﾙｰﾁﾝ

    glutMainLoop();                 // ＯｐｅｎＧＬメインループ
}
