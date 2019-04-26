#include <graphics.h>
#include <Windows.h>
#include <conio.h>//�����¼�ͷ�ļ�

/*
#define	UP    0
#define	DOWN  1
#define	LEFT  2
#define	RIGHT 3
*/


//ö��
enum DIRECTION{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
  

//̹�˽ṹ��
struct tank_s {
	int x; //̹���ڵ�ͼ���������ڵ���
	int y; //̹���ڵ�ͼ���������ڵ���
	DIRECTION direction; //̹�˵ķ����ϡ��¡�����
	int live;	   //�Ƿ����� 1-����  0-����
};

//�����ͼ����
int map[26][26] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1},
	{ 2, 2, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 2, 2},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

//�˵�
void menu();
//��ͼ
void init_map();
//��ʼ��Ϸ
void play();
int tank_walk(tank_s *tank, DIRECTION direction, IMAGE *img);
void set_prop_map(int x, int y,int val);
void bullet_action(bullet_s *bullet);

int main(void) {
	//��ʼ������(���̨)
	initgraph(650, 650);

	//��ʼ��������ʾ�˵�
	menu();
	//��ʼ����ͼ
	init_map();
	play();


	system("pause");
	return 0;
}

void menu() {
	//��ʾlogo
	IMAGE logo_img;//����ͼ��ı���
	loadimage(&logo_img, _T("logo.bmp"), 433, 147);//����ͼƬ��ַ�ʹ�С
	putimage(110, 20, &logo_img);//����ͼƬ��x��y��ֵ����ȡ�����ĵ�ַ

	//ʵ�ֵ�����ť
	setlinecolor(WHITE);//����������ɫ
	setfillcolor(BLACK);//�����ɫ��

	settextstyle(25, 00, _T("����"));//���������С������
	fillrectangle(230, 200, 310, 240);//����λ��
	outtextxy(240, 210, _T("˵ ��"));//��������λ��

	fillrectangle(350, 200, 430, 240);
	outtextxy(360, 210, _T("�� ʼ"));

	MOUSEMSG mouse;//���������Ϣ�ı���
	IMAGE illustrate_img;
	loadimage(&illustrate_img, _T("illustrate.jpg"), 300, 300);//����ͼƬ

	//int finished = 0;//�����ж�whileѭ���Ƿ����

while (1 == 1) {
	//ѭ����ȡ���״̬
	mouse = GetMouseMsg();

	switch (mouse.uMsg) {
	case WM_MOUSEMOVE://����ƶ�
		//�ж��Ƿ��ƶ���ָ��xy����λ��
		if ((mouse.x > 230 && mouse.x < 310) && (mouse.y > 200 && mouse.y < 240)) {
			//����ƶ�������ʾ˵��ͼƬ
			putimage(150, 250, &illustrate_img);
		}
		else {
			//����뿪����ʾ�ޱ߿��ɫ�����ڵ�
			solidrectangle(150, 250, 450, 550);
		}
		break;
		//����������󴥷�
	case WM_LBUTTONDOWN:
		if (mouse.x > 350 && mouse.x < 430 && mouse.y > 200 && mouse.y < 240) {
			//�����Ļ����
			cleardevice();
			return;
			//finished = 1;//1һֱִ�У�Ϊ0����ִ��
			//break;
		}
	}
}

}
/*
��ʼ����ͼ���յ�Ϊ0��������ǽΪ1����������ǽΪ2����ӥ��3.4��
*/

void init_map() {

	int i, j;//��������

	//����ͼƬ
	IMAGE img_home, img_wall_1, img_wall_2;

	loadimage(&img_home, _T("home.jpg"), 50, 50);//��ӥ
	loadimage(&img_wall_1, _T("wall1.jpg"), 25, 25);//����������ǽ
	loadimage(&img_wall_2, _T("wall2.jpg"), 25, 25);//��������ǽ

	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {

			if (map[i][j] == 1) {
				putimage(25 * j, 25 * i, &img_wall_2);
			}
			else if (map[i][j] == 2) {
				putimage(25 * j, 25 * i, &img_wall_1);
			}
			else if (map[i][j] == 3) {
				putimage(25 * j, 25 * i, &img_home);
				map[i][j] =			4;
				map[i][j + 1] =		4;
				map[i + 1][j] =		4;
				map[i + 1][j + 1] = 4;
			}
		}
	}
}


void set_prop_map(int x, int y,int val) {
	map[y][x] =			val;
	map[y][x + 1] =		val;
	map[y + 1][x] =		val;
	map[y + 1][x + 1] = val;
}


/*
*����̹�˰���Ӧ�ķ���ǰ��һ��
*����ֵʧ��-0  �ɹ�-1
*/
int tank_walk(tank_s *tank, DIRECTION direction, IMAGE *img, int step) {
	int new_x = tank->x;
	int new_y = tank->y;

	if (step == 1) {//̹��ǰ��һ��
		if (direction == UP) {
			new_y -= 1;
		} else if (direction == DOWN) {
			new_y += 1;
		} else if (direction == LEFT) {
			new_x -= 1;
		} else if (direction == RIGHT) {
			new_x += 1;
		} else {
			return 0;//��Ч����
	}
	set_prop_map(tank->x, tank->y, 0);
	}

	setfillcolor(BLACK);
	solidrectangle(tank->x * 25, tank->y * 25, tank->x * 25 + 50, tank->y * 25 + 50);

	if (step) {
		set_prop_map(new_x, new_y, 200);

		tank->x = new_x;
		tank->y = new_y;
	}
		putimage(tank->x * 25, tank->y * 25, img);
		return 1;
	
}

void bullet_action(bullet_s *bullet) {

	//1.������һ�λ��Ƶ��ӵ�
	setfillcolor(BLACK);
	solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);

	//2.���ݷ�������ӵ��ڡ�Ϸ̨���ϵ�����
	if (bullet->direction == UP) {
		bullet->pos_y -= 2;
	} else if (bullet->direction == DOWN) {
		bullet->pos_y += 2;
	} else if (bullet->direction == LEFT) {
		bullet->pos_x -= 2;
	} else if (bullet->direction == RIGHT) {
		bullet->pos_x += 2;
	} else {
		return;
	}
	//����
	if (bullet->pos_x < 0 || bullet->pos_x>650 || bullet->pos_y < 0 || bullet->pos_y>650) {
		bullet->status = 0;
		return;
	}
	//3.���»����ӵ�
	setfillcolor(WHITE);
	solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);
}



/*
*ʵ����Ϸ����
*/
void play() {
	//�������̹��
	tank_s my_tank;
	IMAGE my_tank_img[4];
	int key;

	//�������̹��ͼƬ
	loadimage(&my_tank_img[UP], _T("tank_up.jpg"), 50, 50);
	loadimage(&my_tank_img[DOWN], _T("tank_down.jpg"), 50, 50);
	loadimage(&my_tank_img[LEFT], _T("tank_left.jpg"), 50, 50);
	loadimage(&my_tank_img[RIGHT], _T("tank_right.jpg"), 50, 50);
	//���̹�˳�ʼλ��
	my_tank.x = 8;
	my_tank.y = 24;

	my_tank.live = 1;//������һ���
	my_tank.direction = UP;//��ҳ�����ʾ����

	set_prop_map(my_tank.x, my_tank.y, 200);

	putimage(my_tank.x * 25, my_tank.y * 25, &my_tank_img[my_tank.direction]);

	while (1) {
		//��ȡ��������
		if (_kbhit()) {
			key = _getch();

			switch (key) {
			case 'a':	//��
				//����ǿյأ��Ϳ����ƶ�
				if (my_tank.direction == LEFT && my_tank.x - 1 >= 0 && map[my_tank.y][my_tank.x - 1] == 0 && map[my_tank.y + 1][my_tank.x - 1] == 0){
					tank_walk(&my_tank,LEFT,&my_tank_img[my_tank.direction], 1);
				} else if(my_tank.direction != LEFT){
					my_tank.direction = LEFT;
					tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.direction], 0);
				}
				break;
			case 'w':	//��
				if (my_tank.direction == UP && my_tank.y - 1 >= 0 && map[my_tank.y-1][my_tank.x] == 0 && map[my_tank.y - 1][my_tank.x + 1] == 0) {
					tank_walk(&my_tank, UP, &my_tank_img[my_tank.direction], 1);
				} else if(my_tank.direction != UP){
					my_tank.direction = UP;
					tank_walk(&my_tank, UP, &my_tank_img[my_tank.direction], 0);
				}
				break;	
			case 's':	//��
				if (my_tank.direction == DOWN && my_tank.y + 2 <= 25 && map[my_tank.y + 2][my_tank.x] == 0 && map[my_tank.y +  2][my_tank.x + 1] == 0) {
					tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.direction], 1);
				}else if (my_tank.direction != DOWN) {
					my_tank.direction = DOWN;
					tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.direction], 0);
				}
				break;
			case 'd':	//��
				if (my_tank.direction == RIGHT && my_tank.x + 2 <= 25 && map[my_tank.y][my_tank.x+2] == 0 && map[my_tank.y + 1][my_tank.x + 2] == 0) {
					tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.direction], 1);
				} else if (my_tank.direction != RIGHT) {
					my_tank.direction = RIGHT;
					tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.direction], 0);
				}
				break;
			case 'j':	//����
				if (my_tank.direction == UP) {
					my_bullet.pos_x = my_tank.x * 25 + 23;
					my_bullet.pos_y = my_tank.y * 25 - 3;
				} else if (my_tank.direction == LEFT) {
					my_bullet.pos_x = my_tank.x * 25 - 3;
					my_bullet.pos_y = my_tank.y * 25 + 23;
				} else if (my_tank.direction == DOWN) {
					my_bullet.pos_x = my_tank.x * 25 + 23;
					my_bullet.pos_y = my_tank.y * 25 + 50;
				} else if (my_tank.direction == RIGHT) {
					my_bullet.pos_x = my_tank.x * 25 + 50;
					my_bullet.pos_y = my_tank.y * 25 + 23;

					my_bullet.direction = my_tank.direction;
					my_bullet.status = 1;
				}
				break;
			case 'p':	//��ͣ
				system("pause");
				break;
			default:	//���������������账��
				break;
			}
			if (my_bullet.status == 1) bullet_action(&my_bullet);
			Sleep(10);//����10����

		}


	}
}