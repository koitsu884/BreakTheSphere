#include "../inc/extern.h"

//�v���C���[�L���������̃L�����A�ǁA�������u���b�N�ƐڐG�����Ƃ��̏���
void HitChara(void)
{
	//���v���C���[�Ƃ̐ڐG����
		if(HitCheck(PlayP[i],PlayP[1-i],16,16)==TRUE){
			POINT2D Haziki;

			Haziki.x=(PlayP[i].x-PlayP[1-i].x)/4.0f;
			Haziki.y=(PlayP[i].y-PlayP[1-i].y)/4.0f;
			
			PlayP[i].x+=Haziki.x;		//���L����������ї�
			PlayP[i].y+=Haziki.y;
			PlayP[1-i].x-=Haziki.x;		//����L����������ї�
			PlayP[1-i].y-=Haziki.y;
		}

		//�ǂƂ̓����蔻��
		if(PlayP[i].x<-274) PlayP[i].x+=2.0;
		if(PlayP[i].x>274)  PlayP[i].x-=2.0;
		if(PlayP[i].y<-170) PlayP[i].y+=2.0;
		if(PlayP[i].y>86)  PlayP[i].y-=2.0;

		

		//�������u���b�N�Ƃ̐ڐG����
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


//�{�[�����ǁA�v���C���[�L�����A�������u���b�N�ɐڐG�������̏���
void HitBall(void)
{
	//�ǂƂ̓����蔻��
		if(Ball[i].pos.x<-280) Ball[i].mov.x =  fabs(Ball[i].mov.x);
		if(Ball[i].pos.x>280)  Ball[i].mov.x = -fabs(Ball[i].mov.x);
		if(Ball[i].pos.y>226){
			Ball[i].mov.y = -fabs(Ball[i].mov.y);
			if(cpuflag[i] == 1)	CPUT(i);		//CPU�͂��̏u�ԂŖڕW�_�̌v�Z���s��
		}
	//�L�����Ƃ̓����蔻��
		if(HitCheck(Ball[i].pos,PlayP[i],10,16)==TRUE){
			POINT2D Haziki;

			Ball[i].mov.x = (Ball[i].pos.x - PlayP[i].x) / (170.0f - (nsel * 50));//��Փx�ɂ�葬�x���ς��
			Ball[i].mov.y = (Ball[i].pos.y - PlayP[i].y) / (170.0f - (nsel * 50));//nsel���傫���قǓ�Փx��

			Haziki.x=(Ball[i].pos.x-PlayP[i].x)/6.0f;
			Haziki.y=(Ball[i].pos.y-PlayP[i].y)/6.0f;

			Ball[i].pos.x += Haziki.x;
			Ball[i].pos.y += Haziki.y;
		}
	//�������u���b�N�Ƃ̐ڐG����
		for(j=0 ; j < 2 ; j++){
			if(HitCheck(Ball[i].pos,Iti[j],10,16)==TRUE){
				POINT2D Haziki;
				
				Ball[i].mov.x = (Ball[i].pos.x - Iti[j].x ) / (170.0f - (nsel * 50));
				Ball[i].mov.y = (Ball[i].pos.y - Iti[j].y ) / (170.0f - (nsel * 50));

				Haziki.x=(Ball[i].pos.x-Iti[j].x)/6.0f;
				Haziki.y=(Ball[i].pos.y-Iti[j].y)/6.0f;

				Ball[i].pos.x += Haziki.x;
				Ball[i].pos.y += Haziki.y;

				if(cpuflag[i] == 1){		//CPU�̏ꍇ
					if(Ball[i].mov.y > 0){			//�ʂ�Y�����̑��x�����Ȃ�ڕW�_��X���W�̓{�[����X���W
						comT[i].y = 40 - nsel * 90;//Y���W�͓�Փx�ɂ��킹�Č��߂�i��Փx�������قǉ��̕��œ������j
						comT[i].x = Ball[i].pos.x;
					}
					else CPUT(i);					//�ʂ�Y�����̑��x�����Ȃ�ڕW�_�v�Z
				}

				cflag[j] = 30;				//�Փ˂�����u���b�N�̐F���ς��A���ׂ̈̔���p�t���O
				ocunt[j]++;					//����Փ˂���Ɖ������N����
				Dotti[j] = i;				//�Փ˂����ʂ�P1�̂��̂�P2�̂��̂�����
		
			}
		}
		
		//�j��u���b�N�Ƃ̐ڐG����
		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
			for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
				if(Blife[Bloop1][Bloop2]>0){			//���C�t0�̃u���b�N�͑ΏۊO
					if(HitCheck(Ball[i].pos , Bpos[Bloop1][Bloop2] , 10 , 16)==TRUE){

						
						
						//���˕Ԃ�����v�Z
						Ball[i].mov.x = (Ball[i].pos.x - Bpos[Bloop1][Bloop2].x ) / (170.0f - (nsel * 50));
						Ball[i].mov.y = (Ball[i].pos.y - Bpos[Bloop1][Bloop2].y ) / (170.0f - (nsel * 50));

						if(cpuflag[i] == 1){
							if(Ball[i].mov.y < 0) CPUT(i);//�{�[����Y�����̑��x�����Ȃ�CPU�̖ڕW�_�v�Z
						}

						Blife[Bloop1][Bloop2] -= 1;		//�ڐG������u���b�N�̃��C�t�|�P
						if (Blife[Bloop1][Bloop2] == 0){
							poi[i]++;					//�u���b�N��j�󂵂���|�C���g�v���X
							if(poi[i] == 20) fflag = 1; //�|�C���g��20���܂�����Q�[���I��
							chflag[i] = 1;				//�L������ω�����p�t���O���P�i��ъ�j
							chcunt[i] = 200;			//�J�E���g���O�ɂȂ�܂Ŋ�͊�ъ�̂܂�
							fin++;						//�u���b�N�̔j�󐔃v���X
							if(fin == 68) fflag = 1;	//�S�Ẵu���b�N����ꂽ��Q�[���I��
						}
					}
				}
			}
		}
}

//�������L�������ǁA�v���C���[�L�����A�j��u���b�N�ɐڐG�������̏���
void HitOtasuke(void)
{
	//�ǂƂ̓����蔻��
			if(Ball[i].pos.x<-284) Ball[i].mov.x =  fabs(Ball[i].mov.x);
			if(Ball[i].pos.x>284)  Ball[i].mov.x = -fabs(Ball[i].mov.x);
			if(Ball[i].pos.y>230)  Ball[i].mov.y = -fabs(Ball[i].mov.y);

			//�������u���b�N�Ƃ̓����蔻��
			for(j=0 ; j < 2 ; j++){
			if(HitCheck(Ball[i].pos,Iti[j],12,16)==TRUE){
			
				Ball[i].mov.x = (Ball[i].pos.x - Iti[j].x ) / 100.0f;
				Ball[i].mov.y = (Ball[i].pos.y - Iti[j].y ) / 100.0f;
				cflag[j] = 30;				//�Փ˂�����u���b�N�̐F���ς��A���ׂ̈̔���p�t���O
			}
		}
			//�L�����Ƃ̓����蔻��
			//�������u���b�N�P����o���������L����
			if(i < 5){
                if(HitCheck(Ball[i].pos,PlayP[Dot[0]],12,16)==TRUE){
				Ball[i].mov.x = (Ball[i].pos.x - PlayP[Dot[0]].x) / 100.0f;//�������C�x���g�𔭐��������L�����Ȃ�G���
				Ball[i].mov.y = (Ball[i].pos.y - PlayP[Dot[0]].y) / 100.0f;//Dot[0]=0�Ȃ�v���C���[�P�A1�Ȃ�v���C���[�Q
				}
			}
			//�������u���b�N�Q����o���������L����
			else{
				if(HitCheck(Ball[i].pos,PlayP[Dot[1]],12,16)==TRUE){
				Ball[i].mov.x = (Ball[i].pos.x - PlayP[Dot[1]].x) / 100.0f;
				Ball[i].mov.y = (Ball[i].pos.y - PlayP[Dot[1]].y) / 100.0f;
				}
			}


		
		//�j��u���b�N�Ƃ̐ڐG����
		for(Bloop2 = 0 ; Bloop2 < 4 ; Bloop2++){
			for(Bloop1 = 0 ; Bloop1 < 17 ; Bloop1++){
				if(Blife[Bloop1][Bloop2]>0){			//���C�t0�̃u���b�N�͑ΏۊO
					if(HitCheck(Ball[i].pos , Bpos[Bloop1][Bloop2] , 12 , 16)==TRUE){
						
						//���˕Ԃ�����v�Z
						Ball[i].mov.x = (Ball[i].pos.x - Bpos[Bloop1][Bloop2].x ) / 100.0f;
						Ball[i].mov.y = (Ball[i].pos.y - Bpos[Bloop1][Bloop2].y ) / 100.0f;

						Blife[Bloop1][Bloop2] -= 1;		//�ڐG������u���b�N�̃��C�t�|�P
						if (Blife[Bloop1][Bloop2] == 0){
							//�������u���b�N�P����o���������L����
							if(i < 5){
								poi[Dot[0]]++; //�u���b�N��j�󂵂���|�C���g�v���X
								if(poi[Dot[0]] == 20) fflag = 1;
								chflag[Dot[0]] = 1;
								chcunt[Dot[0]] = 200;
							}
							//�������u���b�N�Q����o���������L����
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