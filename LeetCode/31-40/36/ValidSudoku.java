import java.util.HashMap;
/*
* 官方解法用Hash散列表感觉太繁重了。只要构建三个二维矩阵即可。这样不用每次循环都刷新。
* 判断二维矩阵的每个位置是否出现过数值，如果出现，就返回false，否则返回true
* 由于值是0-9，所以值和数组位置映射。
* */
public class ValidSudoku {
    public boolean isValidSudoku_thinkByMyself(char[][] board) {
        int[]rows=new int[10];
        int[]cols=new int[10];
        //检测完所有的行和列
        for(int i=0;i<9;i++) {
            //初始化
            for(int t=0;t<10;t++)
                rows[t]=cols[t]=0;
            for (int j = 0; j < 9; j++) {
                if(board[i][j]!='.'){
                    int rowPosi = board[i][j]-48;
                    if (rows[rowPosi]!=0)
                        return false;
                    rows[rowPosi]=rowPosi;
                }
                if(board[j][i]!='.'){
                    int colPosi = board[j][i]-48;
                    if(cols[colPosi]!=0)
                        return false;
                    cols[colPosi]=colPosi;
                }
            }
        }
        //再初始化一次，检测小九宫格

        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                //初始化
                for(int index=0;index<10;index++)
                    rows[index]=0;

                for(int t=0;t<3;t++)
                    for(int q=0;q<3;q++){

                        if(board[i+t][j+q]!='.'){
                            int tmp=board[i+t][j+q]-48;
                            if(rows[tmp]!=0)
                                return false;
                            rows[tmp]=tmp;
                        }
                    }
            }
        }
        return true;

    }
    //官方提供的解法
    public boolean isValidSudoku(char[][]board){
        HashMap<Integer,Integer>rows[]=new HashMap[9];
        HashMap<Integer,Integer>cols[]=new HashMap[9];
        HashMap<Integer,Integer>boxes[]=new HashMap[9];
        for(int i=0;i<9;i++){
            rows[i]=new HashMap<>();
            cols[i]=new HashMap<>();
            boxes[i]=new HashMap<>();
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-48;
                    int boxPosition=(i/3)*3+j/3;
                    //如果不存在就放入1，否则就大于1
                    rows[i].put(num,rows[i].getOrDefault(num,0)+1);
                    cols[j].put(num,cols[j].getOrDefault(num,0)+1);
                    boxes[boxPosition].put(num,boxes[boxPosition].getOrDefault(num,0)+1);
                    if(rows[i].get(num)>1||cols[j].get(num)>1||boxes[boxPosition].get(num)>1)
                        return false;
                }
            }
        }
        return true;
    }
    public static void main(String[]args){
        ValidSudoku test=new ValidSudoku();
        char [][]nums={
                {'8','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
        };
        System.out.println(test.isValidSudoku(nums));
        /*
        HashMap<String,String> map=new HashMap<>();
        map.put("北京","beijing");
        String po=map.getOrDefault("北京","test");
        String another=map.getOrDefault("不存在","notExist");
        System.out.println(another);
        */
    }
}
