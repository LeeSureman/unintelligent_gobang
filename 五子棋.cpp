#include <iostream>
#include<stdlib.h>
using namespace std;
int tag;
int cengshu = 3;
int *qixingpingfen;
int data[100];
int board[16][16] = {0};
char help[17][17];
int aaaaX,aaaaY;
int pos[16][16] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
        {0,0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
        {0,0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
        {0,0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
        {0,0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
        {0,0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
        {0,0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
        {0,0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
        {0,0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
        {0,0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
        {0,0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int getLine(int x,int y,int mode){
    if(mode == 1){
        if(y<5){
            for(int i=1;i<y+5;i++){
                data[i] = board[x][i];
            }
            tag = y;
            return (y+4);
        }else if(y>11){
            for(int i=15;i>y-5;i--){
                data[15-i+1] = board[x][i];
            }
            tag = 5;
            return (20-y);
        }else{
            for(int i=y-4;i<y+5;i++){
                data[i-y+4+1] = board[x][i];
            }
            tag = 5;
            return 9;
        }
    }else if(mode == 2){
        if(x<5){
            for(int i=1;i<x+5;i++){
                data[i] = board[i][y];
            }
            tag = x;
            return (x+4);
        }else if(x>11){
            for(int i=15;i>x-5;i--){
                data[15-i+1] = board[i][y];
            }
            tag = 5;
            return (20-x);
        }else{
            for(int i=x-4;i<x+5;i++){
                data[i-x+4+1] = board[i][y];
            }
            tag = 5;
            return 9;
        }
    }else if(mode == 3){
        int i,j;
        for(i=0;x+i<=15&&y-i>0&&i<=4;i++);
        for(j=0;x-j>0&&y+j<=15&&j<=4;j++);
        int l = i+j-1,x1 = x+i,y1 = y-i;
        for(int k=1;k<=l;k++){
            data[k] = board[x1-k][y1+k];
        }
        tag = i;
//        printf("*%d %d*\n",i,j);
        return l;
    }else if(mode == 4){
        int i,j;
        for(i=0;x+i<=15&&y+i<=15&&i<=4;i++);
        for(j=0;x-j>0&&y-j>0&&j<=4;j++);
        int l = i+j-1,x1 = x-j,y1 = y-j;
        for(int k=1;k<=l;k++){
            data[k] = board[x1+k][y1+k];
        }
        tag = j;
//        printf("*%d %d*\n",i,j);
        return l;
    }
}
void printBoard() {
	cout<<"   ";
	for(int i = 1;i<=15;i++){
		printf("%-4d",i);
	}
	cout<<"\n";
    for (int i = 1; i <= 15; i++) {
    	printf("%-3d",i);
        for (int j = 1; j <= 15; j++) { 
            if(board[i][j] == 1){
                printf(" ●|");
            }else if(board[i][j] == -1){
                printf(" ○|");
            }else{
            	printf("   |",board[i][j]);
			}
			
        }
        cout << "\n";
        printf("   ------------------------------------------------------------\n");
    }
}

void init() {
    qixingpingfen[12] = 50;
    qixingpingfen[10] = 100;
    qixingpingfen[210] = 50;
    qixingpingfen[110] = 650;
    qixingpingfen[2110] = 150;
    qixingpingfen[112] = 150;
    qixingpingfen[1010] = 250;
    qixingpingfen[21010] = 50;
    qixingpingfen[1012] = 50;
    qixingpingfen[1110] = 3000;
    qixingpingfen[21110] = 500;
    qixingpingfen[1112] = 500;
    qixingpingfen[10110] = 800;
    qixingpingfen[210110] = 700;
    qixingpingfen[10112] = 200;//to be ensured
    qixingpingfen[11010] = 800;
    qixingpingfen[211010] = 200;
    qixingpingfen[11012] = 700;
    qixingpingfen[101010] = 550;
    qixingpingfen[2101010] = 350;
    qixingpingfen[101012] = 350;
    qixingpingfen[110110] = 2800;
    qixingpingfen[2110110] = 2650;
    qixingpingfen[110112] = 2650;
    qixingpingfen[111010] = 3000;
    qixingpingfen[101110] = 3000;
    qixingpingfen[2111010] = 2525;
    qixingpingfen[101112] = 2525;
    qixingpingfen[111012] = 3000;
    qixingpingfen[2101110] = 3000;
    qixingpingfen[211110] = 2500;
    qixingpingfen[11112] = 2500;
    qixingpingfen[11110] = 50000;
    qixingpingfen[111112] = 150000;
    qixingpingfen[2111110] = 150000;
    qixingpingfen[111110] = 150000;
    qixingpingfen[2111112] = 150000;
}

int evaluateLine(int n) {
//	cout<<"|";
//	for(int i=1;i<=n;i++){
//		printf("%d",data[i]);
//	}
	int sssss = 0;
	int number = 0;
//	for(int i=1;i<=n;i++){
//		if(data[i] !=0 ){
//			if(data[i] == sssss){
//				number++;
//			}else{
//			sssss = data[i];
//			number = 1;
//		}
//	}else{
//		sssss = 0;
//		number = 0;
//	}
//	}
	if(number > 4){
		cout<<"|";
		for(int i=1;i<=n;i++){
			printf("%d ",data[i]);
		}
	}
	int zero = 0;
//    printf("*****\n");
//    for(int i=1;i<=n;i++){
//        printf("%d ",data[i]);
//    }
//    cout<<"\n";
    int symbol = 2;
    int evaluation = 0;
    int colorNow = 1;
    for (int i = 1; i <= n; i++) {
        if (data[i] == 0) {
            if (symbol == 2 || symbol == 0) {
                symbol = 0;
            } else if (zero == 1) {
            	if(symbol%10 == 0){
            		if(symbol>10000000){
                        return colorNow*4000;				//小简化
                    }
                evaluation += colorNow * qixingpingfen[symbol];
//                printf("%d %d\n",colorNow,symbol);
//                cout << colorNow << " ";
//                cout << symbol << "\n";
                symbol = 0;
                zero = 0;
            	}else{
					if(symbol>1000000){
						return colorNow*4000;				//小简化 
					}
            		evaluation += colorNow * qixingpingfen[10*symbol];
//            		printf("%d %d\n",colorNow,symbol*10);
            		symbol = 0;
            		zero = 0;
				}
            } else {
                symbol *= 10;
                zero++;
            }
        } else if (data[i] == colorNow || symbol == 0) {
        		if(symbol>1000000){
					return colorNow*4000;				//小简化 
				}
            symbol = 10 * symbol + 1;
            colorNow = data[i];
//            cout<<"*"<<colorNow<<"*";
        } else if (data[i] != colorNow) {
            if (symbol % 10 != 0) {
//            	                if(symbol == 21010110){
//                    for(int i=1;i<=n;i++){
//                        printf("%d ",data[i]);
//                    }
//                    cout<<"\n";
//                    printBoard();
//                }
					if(symbol>1000000){
						return colorNow*4000;				//小简化 
					}
                evaluation += colorNow * qixingpingfen[symbol * 10 + 2];
//                printf("%d %d\n",colorNow,symbol*10+2);
//                cout << colorNow << " ";
//                cout << symbol * 10 + 2 << "\n";
                colorNow *= -1;
                symbol = 21;
            } else {
            	if(symbol>10000000){
						return colorNow*4000;				//小简化 
					}
                evaluation += colorNow * qixingpingfen[symbol];
//                printf("%d %d\n",colorNow,symbol);
//                cout << colorNow << " ";
//                cout << symbol << "\n";
                colorNow *= -1;
                symbol = 01;
            }

        }
    }
//    cout<<symbol;
    if (symbol != 0) {
        if (symbol % 10 != 0) {
//        	printf("%d %d\n",colorNow,symbol*10+2);
			if(symbol>1000000){
				return colorNow*4000;				//小简化 
			}
            evaluation += colorNow * qixingpingfen[symbol * 10 + 2];
//            cout << colorNow << " ";
//            cout << symbol * 10 + 2 << "\n";
            colorNow *= -1;
            symbol = 21;
        } else {
        	if(symbol>10000000){
                return colorNow*4000;				//小简化
            }
//        	printf("%d %d\n",colorNow,symbol);
            evaluation += colorNow * qixingpingfen[symbol];
//            cout << colorNow << " ";
//            cout << symbol << "\n";
            colorNow *= -1;
            symbol = 01;
        }
    }
//    cout<<"******\n";
    return evaluation;
}
int evaluatePoint(int x,int y,int qizi){
    int eva = 0,tmp,l;
    l = getLine(x,y,1);
    tmp = evaluateLine(l);
    data[tag] = qizi;
    eva+=(evaluateLine(l)-tmp);
    l = getLine(x,y,2);
    tmp = evaluateLine(l);
    data[tag] = qizi;
    eva+=(evaluateLine(l)-tmp);
    l = getLine(x,y,3);
    tmp = evaluateLine(l);
    data[tag] = qizi;
    eva+=(evaluateLine(l)-tmp);
    l = getLine(x,y,4);
    tmp = evaluateLine(l);
    data[tag] = qizi;
    eva+=(evaluateLine(l)-tmp);
    return eva;
}
int nextStep(int accumulatedPoint,int n,int AorB){
//	cout<<n;
	int tmp,aaa;
	if(n>0){
		if(n%2 == 1){
			int max = -999999;
			for(int i=1;i<16;i++){
				for(int j=1;j<16;j++){
					if(!board[i][j]&&help[i][j]){
						tmp = evaluatePoint(i,j,1);
						if(tmp>60000){
							if(n == cengshu){
								aaaaX = i;
								aaaaY = j;
							}
							return tmp+accumulatedPoint;
						}
						board[i][j] = 1;
						help[i][j+1]++;
						help[i][j-1]++;
						help[i+1][j]++;
						help[i-1][j]++;
						help[i+1][j+1]++;
						help[i-1][j-1]++;
						help[i-1][j+1]++;
						help[i+1][j-1]++;
						aaa = nextStep(accumulatedPoint+tmp,n-1,max);
//						if(n == cengshu ){
//							printf("%d ",aaa);
//							printf("\n");
//						}
						if(aaa>AorB){
						board[i][j] = 0;
						help[i][j+1]--;
						help[i][j-1]--;
						help[i+1][j]--;
						help[i-1][j]--;
						help[i+1][j+1]--;
						help[i-1][j-1]--;
						help[i-1][j+1]--;
						help[i+1][j-1]--;
						return aaa;
						}
						if(aaa>max){
							max = aaa;
							if(n == cengshu){
								aaaaX = i;
								aaaaY = j;
							}
						}
						board[i][j] = 0;
						help[i][j+1]--;
						help[i][j-1]--;
						help[i+1][j]--;
						help[i-1][j]--;
						help[i+1][j+1]--;
						help[i-1][j-1]--;
						help[i-1][j+1]--;
						help[i+1][j-1]--;
					}
				}
			}
			return max;
		}else if(n%2 == 0){
			int min = 999999;
			for(int i=1;i<16;i++){
				for(int j=1;j<16;j++){
					if(!board[i][j]&&help[i][j]){
						tmp = evaluatePoint(i,j,-1);
						if(tmp<-60000){
							return tmp+accumulatedPoint;
						}
						board[i][j] = -1;
						help[i][j+1]++;
						help[i][j-1]++;
						help[i+1][j]++;
						help[i-1][j]++;
						help[i+1][j+1]++;
						help[i-1][j-1]++;
						help[i-1][j+1]++;
						help[i+1][j-1]++;
						aaa = nextStep(accumulatedPoint+tmp,n-1,min);
						if(aaa<AorB){
						board[i][j] = 0;
						help[i][j+1]--;
						help[i][j-1]--;
						help[i+1][j]--;
						help[i-1][j]--;
						help[i+1][j+1]--;
						help[i-1][j-1]--;
						help[i-1][j+1]--;
						help[i+1][j-1]--;
						return aaa;
						}
						if(aaa<min){
							min = aaa;
						}
						board[i][j] = 0;
						help[i][j+1]--;
						help[i][j-1]--;
						help[i+1][j]--;
						help[i-1][j]--;
						help[i+1][j+1]--;
						help[i-1][j-1]--;
						help[i-1][j+1]--;
						help[i+1][j-1]--;
					}
				}
			}
			return min;
		}
	}else{
		int min = 999999;
		for(int i=1;i<16;i++){
			for(int j=1;j<16;j++){
				if(!board[i][j]&&help[i][j]){
					aaa = evaluatePoint(i,j,-1);
					if(aaa+accumulatedPoint<AorB){
						return (aaa+accumulatedPoint);
					}
					if(aaa<min){
						min = aaa;
					}
				}
			}
		}
		return (min+accumulatedPoint);
	}
} 

void justice(int i,int j){
	int b[9][4] = {0};
	int n = 1,m = 1,o = 1;
	int Now_vaule,count = 1;
	Now_vaule = board[i][j];
	//printf("%d",Now_vaule);
		while(n <= 9){
			if(i-5+n > 0&&j-5+n > 0&&i-5+n < 15&&j-5+n < 15)
			//printf("enter just\n");
			b[n][1] = board[i-5+n][j-5+n];		//左对角线 
			//printf("%d",b[n+1][1]);
			if(i-5+n > 0&&i-5+n < 15)
			b[n][2] = board[i-5+n][j];			//垂直方向 
			//printf("enter b[][2]\n");
			if(j-5+n > 0&&j-5+n < 15)
			b[n][3] = board[i][j-5+n];			//水平方向 
			//printf("enter b[][3]\n");
			if(i+5-n > 0&&j-5+n > 0&&i+5-n < 15&&j-5+n < 15)
			b[n][4] = board[i+5-n][j-5+n];		//右对角线 
			//printf("enter b[][4]\n");
			//printf("当前坐标(%d,%d)\n",i,j);
			//printf("%d",board[i][j-5+n]);
			//printf("当前水平数组第%d个：%d\n",n,b[n][3]);
			n++; 
		}
    while(o <= 4){
		for(n = 1;n <= 5;n++){
			if(b[n][o]+b[n+1][o]+b[n+2][o]+b[n+3][o]+b[n+4][o] == 5){ 
			printf("白棋获胜\n"); exit;
			}
			else if(b[n][o]+b[n+1][o]+b[n+2][o]+b[n+3][o]+b[n+4][o] == -5){
			printf("黑棋获胜\n"); exit;
			}
		}
		o++;
			/*printf("水平临时值%d\n",b[n][3]);
			if(b[n][o] == Now_vaule){
			n++;
			count++;
			if(count == 5 && Now_vaule == 1) {	printf("白棋获胜"); break;}
			else if(count == 5 && Now_vaule == -1) {	printf("黑棋获胜"); break;}
			}
			else{
			m = 1;
			n++;
			count = 1;
			//if(count < 5) break;
			}
		}
		printf("count值%d\n",count);
			//if(count == 5 && Now_vaule == 1) {	printf("白棋获胜"); break;}
			//else if(count == 5 && Now_vaule == -1) {	printf("黑棋获胜"); break;}
			o++;
		}*/
	}
	}
	
	
int main() {
    qixingpingfen = (int *) malloc(3000000 * sizeof(int));
    init();
    help[8][8] = 1;
    int lxn = 0,lxn1;
    int x, y;
    int rX,rY;
    int isInitial;
    cin >> isInitial;
    if (isInitial) {
        cin >> x >> y;
        board[x][y] = -1;
    }
    help[x+1][y] = 1;
    help[x][y+1] = 1;
    help[x+1][y+1] = 1;
    help[x-1][y] = 1;
    help[x][y-1] = 1;
    help[x-1][y-1] = 1;
    help[x-1][y+1] = 1;
    help[x+1][y-1] = 1;
    printBoard();
    cout<<"\n";
    while(1){
    	nextStep(0,cengshu,999999);
    	printf("%d %d\n",aaaaX,aaaaY);
    	board[aaaaX][aaaaY] = 1;
    	justice(aaaaX,aaaaY);
    	help[aaaaX][aaaaY+1]++;
		help[aaaaX][aaaaY-1]++;
		help[aaaaX+1][aaaaY]++;
		help[aaaaX-1][aaaaY]++;
		help[aaaaX+1][aaaaY+1]++;
		help[aaaaX-1][aaaaY-1]++;
		help[aaaaX-1][aaaaY+1]++;
		help[aaaaX+1][aaaaY-1]++;
		justice(x,y);
		printBoard();
		cin >> x >> y;
//		if(board[x][y] != 0){
//		printf("这里有子了你别乱下");
//		return 0;
//		}
		cout<<"\n";
        board[x][y] = -1;
        help[x+1][y] = 1;
        help[x][y+1] = 1;
        help[x+1][y+1] = 1;
        help[x-1][y] = 1;
        help[x][y-1] = 1;
        help[x-1][y-1] = 1;
        help[x-1][y+1] = 1;
        help[x+1][y-1] = 1;
        
	}
//    while (1) {
//        for (int i = 1; i <= 15; i++) {
//            for (int j = 1; j <= 15; j++) {
//                if (!board[i][j]&&help[i][j]) {
//                    lxn1 = evaluatePoint(i,j);
////                    printf("pppppppp\n%d %d %d\npppppp\n",i,j,lxn1);
//                    if(lxn1>lxn){
//                        rX = i;
//                        rY = j;
//                        lxn = lxn1;
//                    }
//                }
//            }
//        }
//        lxn = 0;
//        cout<<rX<<" "<<rY<<"\n";
//        board[rX][rY] = 1;
//        help[rX+1][rY] = 1;
//        help[rX][rY+1] = 1;
//        help[rX+1][rY+1] = 1;
//        help[rX-1][rY] = 1;
//        help[rX][rY-1] = 1;
//        help[rX-1][rY-1] = 1;
//        help[rX-1][rY+1] = 1;
//        help[rX+1][rY-1] = 1;
//        printBoard();
//
//        cin >> x >> y;
//        board[x][y] = -1;
//
//        help[x+1][y] = 1;
//        help[x][y+1] = 1;
//        help[x+1][y+1] = 1;
//        help[x-1][y] = 1;
//        help[x][y-1] = 1;
//        help[x-1][y-1] = 1;
//        help[x-1][y+1] = 1;
//        help[x+1][y-1] = 1;
//    }
    return 0;
}
//int main(){
//    board[5][6] = -1;
//    printBoard();
//    getLine(4,5,4);
//    for(int i=1;i<=8;i++)
//        printf("%d ",data[i]);
//}
