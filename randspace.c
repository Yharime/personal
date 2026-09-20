#include<stdio.h>
 #include<stdlib.h>


 void go_UW();//上
 void go_DW();//下
 void go_RW();//右
 void go_LW();//左
 void beg();//初始化
 void output();//打印
 void deal();//处理棋盘


char chess[10][10]={'.'};//棋盘
int px,py;//记录位置
char step;//记录当前字母
int flag[4] = {0};//有无移动的标记


 int main(){
    beg();
    deal();
    output();
    return 0;
}


 void beg(){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            chess[i][j]='.';
        }
    }
    px = 0;
    py = 0;
    step = 'A';
 }
 void output(){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%c",chess[i][j]);
        }
        printf("\n");
    }
    return;
 }


 void deal(){
    int i,mark;
    int ward = -1;//方向变量
    while(step!=('Z'+1)){
        ward = rand()%4;
        if(chess[px][py]=='Z')
            break;
        //当到头时跳出循环
        //printf("%d %d %d %c\n",ward,px,py,step);
        switch(ward){
            case 3:
                if(flag[ward]==1)
                break;
                //如果已经尝试过直接跳出
                if(px<9&&chess[px+1][py]=='.'){//确保未出界并未被标记
                    go_RW();//走动
                    break;
                }
                flag[ward]=1;//标记已尝试
                break;
            case 2: 
                if(flag[ward]==1)
                break;
                if(px>0&&chess[px-1][py]=='.'){
                    go_LW();
                    break;
                }
                flag[ward]=1;
                break;
            case 0:
                if(flag[ward]==1)
                break;
                if(py>0&&chess[px][py-1]=='.'){
                    go_UW();    
                    break;
                }
                flag[ward]=1;
                break;
            case 1:
                if(flag[ward]==1)
                break;
                if(py<9&&chess[px][py+1]=='.'){
                    go_DW();
                    break;
                }
                flag[ward]=1;
                break;
        }
        //移动
        //不太想优化了，一直随机吧，早晚能随机完
        for(i=0;i<4;i++){
            if(flag[i]==0){
                mark = 1;
                break;
            }
        }
        if(mark == 1){
            mark = 0;
            continue;
        }
        else{
            return;
        }
    }
    return;
}


void go_RW(){
    chess[px][py] = step;//赋值
    for(int i=0;i<4;i++)
    flag[i] = 0;//重置移动可行性状态
    px++;//移动 
    step++;//切换下一字母
}
void go_LW(){
    chess[px][py] = step;
    for(int i=0;i<4;i++)
    flag[i] = 0;
    px--;
    step++;
}
void go_UW(){
    chess[px][py] = step;
    for(int i=0;i<4;i++)
    flag[i] = 0;
    py--;
    step++;
}
void go_DW(){
    chess[px][py]= step;
    for(int i=0;i<4;i++)
    flag[i] = 0;
    py++;
    step++;
}

/*
## 说明
先初始化棋盘，用初始化的字符检验可否前进  
为每一步要留下的字母进行计数，方向的随机处理    
用~flag[ward]~来减少重复运算  
用if检验是否出界    
px,py记录位置，有打注释，这个只是大致描述
*/  