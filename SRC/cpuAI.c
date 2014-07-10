
#include "../inc/extern.h"

/*----------------------------------------------------------------------*/
/* 　CPUのAI														 　*/
/*----------------------------------------------------------------------*/
void cpuAI(POINT2D play, int playNo)
{
	//CPUキー入力設定
	//目標点よりキャラクターが左上にいる時
	if(play.x < comT[playNo].x - 0.2 && play.y > comT[playNo].y + 2 ) muki[playNo] = 2;	//右下に進む
	//左下にいるとき
	else{
		if(play.x < comT[playNo].x - 0.2 && play.y < comT[playNo].y - 2 ) muki[playNo] = 7; //右上に進む
		//ほぼ左にいるとき
		else{
			if(play.x < comT[playNo].x - 0.2)	muki[playNo] = 4;	//右に進む
			//右上にいるとき
			else{
				if(play.x > comT[playNo].x + 0.2 && play.y > comT[playNo].y + 2) muki[playNo] = 0;	//左下に進む
				//右下にいるとき
				else{
					if(play.x > comT[playNo].x + 0.2 && play.y < comT[playNo].y - 2) muki[playNo] = 5;	//左上に進む
					//ほぼ右にいるとき
					else{
						if(play.x > comT[playNo].x + 0.2)	muki[playNo] = 3;	//左に進む
						//ほぼ上にいるとき
						else{
							if(play.y > comT[playNo].y + 2) muki[playNo] = 1;	//下に進む
							//ほぼ下にいるとき
							else{
								if(play.y < comT[playNo].y - 2) muki[playNo] = 6;	//上に進む
                                //目標点付近にいる時
                                else{
									acunt[playNo]--;
									PlayP[playNo].x -= KeyMovT[muki[playNo]].x * (1 + nsel * 0.1);
									PlayP[playNo].y -= KeyMovT[muki[playNo]].y * (1 + nsel * 0.1);
								}
							}
						}
					}
				}
			}
		}
	}
						
	
		keyin[playNo] = muki[playNo];
		acunt[playNo]++;
        PlayP[playNo].x += KeyMovT[muki[playNo]].x * (1 + nsel * 0.1);
        PlayP[playNo].y += KeyMovT[muki[playNo]].y * (1 + nsel * 0.1);
}

/*----------------------------------------------------------------------*/
/*   CPU目標位置設定                                                    */
/*----------------------------------------------------------------------*/
void CPUT(int playNo)
{
	comT[i].y = 40 - nsel * 90;
    comT[i].x = Ball[playNo].pos.x + Ball[playNo].mov.x * (fabs(Ball[playNo].pos.y - (40.0f - (float)nsel * 90.0f)) / (-Ball[playNo].mov.y));

	if(comT[i].x >2610){
		comT[i].x = Ball[playNo].pos.x;
		comT[i].y = Ball[playNo].pos.y - 20;
	}
	else{
		if	(comT[i].x > 2030) comT[i].x = comT[i].x - 2320;
		else{
			if(comT[i].x >1450){
				comT[i].x = comT[i].x - 1160;
				comT[i].x -= 2 * (comT[i].x - 290);
			}
			else{
				if(comT[i].x > 870) comT[i].x = comT[i].x - 1160;
				else{
					if(comT[i].x > 290) comT[i].x -= 2 * (comT[i].x - 290) - 6;
					else{
						if(comT[i].x >= -290){
							if(Ball[i].mov.x >= 0)comT[i].x -= 6;
							else comT[i].x += 6;
							}
						else{
							if(comT[i].x < -290) comT[i].x -= 2 * (comT[i].x + 290) + 6; 
							else{
								if(comT[i].x < -870) comT[i].x = comT[i].x + 1160;
								else{
									if(comT[i].x > -1450){
										comT[i].x = comT[i].x + 1160;
										comT[i].x -= 2 * (comT[i].x + 290);
										}
									else{
										if	(comT[i].x > -2030) comT[i].x = comT[i].x + 2320;
										else{
											if(comT[i].x < -2610){
												comT[i].x = Ball[playNo].pos.x;
												comT[i].y = Ball[playNo].pos.y - 20;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

				

	
}