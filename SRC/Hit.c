#include "../inc/extern.h"

//プレイヤーキャラが他のキャラ、壁、お助けブロックと接触したときの処理
void HitChara(void)
{
	//他プレイヤーとの接触判定
		if(HitCheck(PlayP[i],PlayP[1-i],16,16)==TRUE){
			POINT2D Haziki;

			Haziki.x=(PlayP[i].x-PlayP[1-i].x)/4.0f;
			Haziki.y=(PlayP[i].y-PlayP[1-i].y)/4.0f;
			
			PlayP[i].x+=Haziki.x;		//自キャラ吹き飛び量
			PlayP[i].y+=Haziki.y;
			PlayP[1-i].x-=Haziki.x;		//相手キャラ吹き飛び量
			PlayP[1-i].y-=Haziki.y;
		}

		//壁との当たり判定
		if(PlayP[i].x<-274) PlayP[i].x+=2.0;
		if(PlayP[i].x>274)  PlayP[i].x-=2.0;
		if(PlayP[i].y<-170) PlayP[i].y+=2.0;
		if(PlayP[i].y>86)  PlayP[i].y-=2.0;

		

		//お助けブロックとの接触判定
		for(j=0; j<2 ; j++){
            if(HitCheck(PlayP[i],Iti[j],16,16)==TRUE){
				POINT2D Haziki;

				Haziki.x=(PlayP[i].x-Iti[j].x)/4.0f;
				Haziki.y=(PlayP[i].y-Iti[j].y)/4.0f;
			
				PlayP[i].x+=Haziki.x;
				PlayP[i].y+=Haziki.y;
			}
		}
}


//ボールが壁、プレイヤーキャラ、お助けブロックに接触した時の処理
void HitBall(void)
{
	//壁との当たり判定
		if(Ball[i].pos.x<-280) Ball[i].mov.x =  fabs(Ball[i].mov.x);
		if(Ball[i].pos.x>280)  Ball[i].mov.x = -fabs(Ball[i].mov.x);
		if(Ball[i].pos.y>226){
			Ball[i].mov.y = -fabs(Ball[i].mov.y);
			if(cpuflag[i] == 1)	CPUT(i);		//CPUはこの瞬間で目標点の計算を行う
		}
	//キャラとの当たり判定
		if(HitCheck(Ball[i].pos,PlayP[i],10,16)==TRUE){
			POINT2D Haziki;

			Ball[i].mov.x = (Ball[i].pos.x - PlayP[i].x) / (170.0f - (nsel * 50));//難易度により速度が変わる
			Ball[i].mov.y = (Ball[i].pos.y - PlayP[i].y) / (170.0f - (nsel * 50));//nselが大きいほど難易度高

			Haziki.x=(Ball[i].pos.x-PlayP[i].x)/6.0f;
			Haziki.y=(Ball[i].pos.y-PlayP[i].y)/6.0f;

			Ball[i].pos.x += Haziki.x;
			Ball[i].pos.y += Haziki.y;
		}
	//お助けブロックとの接触判定
		for(j=0 ; j < 2 ; j++){
			if(HitCheck(Ball[i].pos,Iti[j],10,16)==TRUE){
				POINT2D Haziki;
				
				Ball[i].mov.x = (Ball[i].pos.x - Iti[j].x ) / (170.0f - (nsel * 50));
				Ball[i].mov.y = (Ball[i].pos.y - Iti[j].y ) / (170.0f - (nsel * 50));

				Haziki.x=(Ball[i].pos.x-Iti[j].x)/6.0f;
				Haziki.y=(Ball[i].pos.y-Iti[j].y)/6.0f;

				Ball[i].pos.x += Haziki.x;
				Ball[i].pos.y += Haziki.y;

				if(cpuflag[i] == 1){		//CPUの場合
					if(Ball[i].mov.y > 0){			//玉のY方向の速度が正なら目標点のX座標はボールのX座標
						comT[i].y = 40 - nsel * 90;//Y座標は難易度にあわせて決める（難易度が高いほど下の方で動き回る）
						comT[i].x = Ball[i].pos.x;
					}
					else CPUT(i);					//玉のY方向の速度が負なら目標点計算
				}

				cflag[j] = 30;				//衝突したらブロックの色が変わる、その為の判定用フラグ
				ocunt[j]++;					//数回衝突すると何かが起こる
				Dotti[j] = i;				//衝突した玉はP1のものかP2のものか判定
		
			}
		}
		
		//破壊ブロックとの接触判定
		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
			for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
				if(Blife[Bloop1][Bloop2]>0){			//ライフ0のブロックは対象外
					if(HitCheck(Ball[i].pos , Bpos[Bloop1][Bloop2] , 10 , 16)==TRUE){

						
						
						//跳ね返り方向計算
						Ball[i].mov.x = (Ball[i].pos.x - Bpos[Bloop1][Bloop2].x ) / (170.0f - (nsel * 50));
						Ball[i].mov.y = (Ball[i].pos.y - Bpos[Bloop1][Bloop2].y ) / (170.0f - (nsel * 50));

						if(cpuflag[i] == 1){
							if(Ball[i].mov.y < 0) CPUT(i);//ボールのY方向の速度が負ならCPUの目標点計算
						}

						Blife[Bloop1][Bloop2] -= 1;		//接触したらブロックのライフ－１
						if (Blife[Bloop1][Bloop2] == 0){
							poi[i]++;					//ブロックを破壊したらポイントプラス
							if(poi[i] == 20) fflag = 1; //ポイントが20溜まったらゲーム終了
							chflag[i] = 1;				//キャラ顔変化判定用フラグ＝１（喜び顔）
							chcunt[i] = 200;			//カウントが０になるまで顔は喜び顔のまま
							fin++;						//ブロックの破壊数プラス
							if(fin == 68) fflag = 1;	//全てのブロックが壊れたらゲーム終了
						}
					}
				}
			}
		}
}

//お助けキャラが壁、プレイヤーキャラ、破壊ブロックに接触した時の処理
void HitOtasuke(void)
{
	//壁との当たり判定
			if(Ball[i].pos.x<-284) Ball[i].mov.x =  fabs(Ball[i].mov.x);
			if(Ball[i].pos.x>284)  Ball[i].mov.x = -fabs(Ball[i].mov.x);
			if(Ball[i].pos.y>230)  Ball[i].mov.y = -fabs(Ball[i].mov.y);

			//お助けブロックとの当たり判定
			for(j=0 ; j < 2 ; j++){
			if(HitCheck(Ball[i].pos,Iti[j],12,16)==TRUE){
			
				Ball[i].mov.x = (Ball[i].pos.x - Iti[j].x ) / 100.0f;
				Ball[i].mov.y = (Ball[i].pos.y - Iti[j].y ) / 100.0f;
				cflag[j] = 30;				//衝突したらブロックの色が変わる、その為の判定用フラグ
			}
		}
			//キャラとの当たり判定
			//お助けブロック１から出たお助けキャラ
			if(i < 5){
                if(HitCheck(Ball[i].pos,PlayP[Dot[0]],12,16)==TRUE){
				Ball[i].mov.x = (Ball[i].pos.x - PlayP[Dot[0]].x) / 100.0f;//お助けイベントを発生させたキャラなら触れる
				Ball[i].mov.y = (Ball[i].pos.y - PlayP[Dot[0]].y) / 100.0f;//Dot[0]=0ならプレイヤー１、1ならプレイヤー２
				}
			}
			//お助けブロック２から出たお助けキャラ
			else{
				if(HitCheck(Ball[i].pos,PlayP[Dot[1]],12,16)==TRUE){
				Ball[i].mov.x = (Ball[i].pos.x - PlayP[Dot[1]].x) / 100.0f;
				Ball[i].mov.y = (Ball[i].pos.y - PlayP[Dot[1]].y) / 100.0f;
				}
			}


		
		//破壊ブロックとの接触判定
		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
			for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
				if(Blife[Bloop1][Bloop2]>0){			//ライフ0のブロックは対象外
					if(HitCheck(Ball[i].pos , Bpos[Bloop1][Bloop2] , 12 , 16)==TRUE){
						
						//跳ね返り方向計算
						Ball[i].mov.x = (Ball[i].pos.x - Bpos[Bloop1][Bloop2].x ) / 100.0f;
						Ball[i].mov.y = (Ball[i].pos.y - Bpos[Bloop1][Bloop2].y ) / 100.0f;

						Blife[Bloop1][Bloop2] -= 1;		//接触したらブロックのライフ－１
						if (Blife[Bloop1][Bloop2] == 0){
							//お助けブロック１から出たお助けキャラ
							if(i < 5){
								poi[Dot[0]]++; //ブロックを破壊したらポイントプラス
								if(poi[Dot[0]] == 20) fflag = 1;
								chflag[Dot[0]] = 1;
								chcunt[Dot[0]] = 200;
							}
							//お助けブロック２から出たお助けキャラ
							else	{
								poi[Dot[1]]++;
								if(poi[Dot[1]] == 20) fflag = 1;
								chflag[Dot[1]] = 1;
								chcunt[Dot[1]] = 200;
							}
							fin++;
							if(fin == 68) fflag = 1;
						}
					}
				}
			}
		}
}