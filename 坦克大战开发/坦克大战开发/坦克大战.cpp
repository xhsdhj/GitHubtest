#include <graphics.h>
#include <Windows.h>
#include <conio.h>//键盘事件头文件

/*
#define	UP    0
#define	DOWN  1
#define	LEFT  2
#define	RIGHT 3
*/


//枚举
enum DIRECTION{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
  

//坦克结构体
struct tank_s {
	int x; //坦克在地图数组中所在的列
	int y; //坦克在地图数组中所在的行
	DIRECTION direction; //坦克的方向，上、下、左、右
	int live;	   //是否生存 1-活着  0-挂了
};

//定义地图数组
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

//菜单
void menu();
//地图
void init_map();
//开始游戏
void play();
int tank_walk(tank_s *tank, DIRECTION direction, IMAGE *img);
void set_prop_map(int x, int y,int val);
void bullet_action(bullet_s *bullet);

int main(void) {
	//初始化界面(搭建舞台)
	initgraph(650, 650);

	//开始场景，显示菜单
	menu();
	//初始化地图
	init_map();
	play();


	system("pause");
	return 0;
}

void menu() {
	//显示logo
	IMAGE logo_img;//定义图标的变量
	loadimage(&logo_img, _T("logo.bmp"), 433, 147);//设置图片地址和大小
	putimage(110, 20, &logo_img);//设置图片的x，y的值，再取变量的地址

	//实现导航按钮
	setlinecolor(WHITE);//设置文字颜色
	setfillcolor(BLACK);//填充颜色。

	settextstyle(25, 00, _T("宋体"));//设置字体大小和字体
	fillrectangle(230, 200, 310, 240);//矩形位置
	outtextxy(240, 210, _T("说 明"));//设置文字位置

	fillrectangle(350, 200, 430, 240);
	outtextxy(360, 210, _T("开 始"));

	MOUSEMSG mouse;//定义鼠标消息的变量
	IMAGE illustrate_img;
	loadimage(&illustrate_img, _T("illustrate.jpg"), 300, 300);//加载图片

	//int finished = 0;//用于判断while循环是否结束

while (1 == 1) {
	//循环获取鼠标状态
	mouse = GetMouseMsg();

	switch (mouse.uMsg) {
	case WM_MOUSEMOVE://鼠标移动
		//判断是否移动到指定xy坐标位置
		if ((mouse.x > 230 && mouse.x < 310) && (mouse.y > 200 && mouse.y < 240)) {
			//鼠标移动到后显示说明图片
			putimage(150, 250, &illustrate_img);
		}
		else {
			//鼠标离开后显示无边框黑色矩形遮挡
			solidrectangle(150, 250, 450, 550);
		}
		break;
		//鼠标左键点击后触发
	case WM_LBUTTONDOWN:
		if (mouse.x > 350 && mouse.x < 430 && mouse.y > 200 && mouse.y < 240) {
			//清除屏幕内容
			cleardevice();
			return;
			//finished = 1;//1一直执行，为0结束执行
			//break;
		}
	}
}

}
/*
初始化地图，空地为0，可消除墙为1，不可消除墙为2，老鹰（3.4）
*/

void init_map() {

	int i, j;//遍历变量

	//加载图片
	IMAGE img_home, img_wall_1, img_wall_2;

	loadimage(&img_home, _T("home.jpg"), 50, 50);//老鹰
	loadimage(&img_wall_1, _T("wall1.jpg"), 25, 25);//不可消除的墙
	loadimage(&img_wall_2, _T("wall2.jpg"), 25, 25);//可消除的墙

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
*控制坦克按相应的方向前进一步
*返回值失败-0  成功-1
*/
int tank_walk(tank_s *tank, DIRECTION direction, IMAGE *img, int step) {
	int new_x = tank->x;
	int new_y = tank->y;

	if (step == 1) {//坦克前进一步
		if (direction == UP) {
			new_y -= 1;
		} else if (direction == DOWN) {
			new_y += 1;
		} else if (direction == LEFT) {
			new_x -= 1;
		} else if (direction == RIGHT) {
			new_x += 1;
		} else {
			return 0;//无效方向
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

	//1.擦除上一次绘制的子弹
	setfillcolor(BLACK);
	solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);

	//2.根据方向计算子弹在“戏台”上的坐标
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
	//超出
	if (bullet->pos_x < 0 || bullet->pos_x>650 || bullet->pos_y < 0 || bullet->pos_y>650) {
		bullet->status = 0;
		return;
	}
	//3.从新绘制子弹
	setfillcolor(WHITE);
	solidrectangle(bullet->pos_x, bullet->pos_y, bullet->pos_x + 3, bullet->pos_y + 3);
}



/*
*实现游戏场景
*/
void play() {
	//定义玩家坦克
	tank_s my_tank;
	IMAGE my_tank_img[4];
	int key;

	//加载玩家坦克图片
	loadimage(&my_tank_img[UP], _T("tank_up.jpg"), 50, 50);
	loadimage(&my_tank_img[DOWN], _T("tank_down.jpg"), 50, 50);
	loadimage(&my_tank_img[LEFT], _T("tank_left.jpg"), 50, 50);
	loadimage(&my_tank_img[RIGHT], _T("tank_right.jpg"), 50, 50);
	//玩家坦克初始位置
	my_tank.x = 8;
	my_tank.y = 24;

	my_tank.live = 1;//代表玩家活着
	my_tank.direction = UP;//玩家出场显示向上

	set_prop_map(my_tank.x, my_tank.y, 200);

	putimage(my_tank.x * 25, my_tank.y * 25, &my_tank_img[my_tank.direction]);

	while (1) {
		//获取键盘输入
		if (_kbhit()) {
			key = _getch();

			switch (key) {
			case 'a':	//左
				//左边是空地，就可以移动
				if (my_tank.direction == LEFT && my_tank.x - 1 >= 0 && map[my_tank.y][my_tank.x - 1] == 0 && map[my_tank.y + 1][my_tank.x - 1] == 0){
					tank_walk(&my_tank,LEFT,&my_tank_img[my_tank.direction], 1);
				} else if(my_tank.direction != LEFT){
					my_tank.direction = LEFT;
					tank_walk(&my_tank, LEFT, &my_tank_img[my_tank.direction], 0);
				}
				break;
			case 'w':	//上
				if (my_tank.direction == UP && my_tank.y - 1 >= 0 && map[my_tank.y-1][my_tank.x] == 0 && map[my_tank.y - 1][my_tank.x + 1] == 0) {
					tank_walk(&my_tank, UP, &my_tank_img[my_tank.direction], 1);
				} else if(my_tank.direction != UP){
					my_tank.direction = UP;
					tank_walk(&my_tank, UP, &my_tank_img[my_tank.direction], 0);
				}
				break;	
			case 's':	//下
				if (my_tank.direction == DOWN && my_tank.y + 2 <= 25 && map[my_tank.y + 2][my_tank.x] == 0 && map[my_tank.y +  2][my_tank.x + 1] == 0) {
					tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.direction], 1);
				}else if (my_tank.direction != DOWN) {
					my_tank.direction = DOWN;
					tank_walk(&my_tank, DOWN, &my_tank_img[my_tank.direction], 0);
				}
				break;
			case 'd':	//右
				if (my_tank.direction == RIGHT && my_tank.x + 2 <= 25 && map[my_tank.y][my_tank.x+2] == 0 && map[my_tank.y + 1][my_tank.x + 2] == 0) {
					tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.direction], 1);
				} else if (my_tank.direction != RIGHT) {
					my_tank.direction = RIGHT;
					tank_walk(&my_tank, RIGHT, &my_tank_img[my_tank.direction], 0);
				}
				break;
			case 'j':	//开火
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
			case 'p':	//暂停
				system("pause");
				break;
			default:	//其他键盘输入无需处理
				break;
			}
			if (my_bullet.status == 1) bullet_action(&my_bullet);
			Sleep(10);//休眠10毫秒

		}


	}
}