import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class SubstringWithConcatenationOfAllWords {
    public List<Integer> findSubstring(String s, String[] words) {

        HashMap<String,Integer> wordAndPosition=new HashMap<>();
        //先把words中所有单词建立k_v映射
        for(int i=0;i<words.length;i++) {
            if(wordAndPosition.get(words[i])==null)
                wordAndPosition.put(words[i], 1);
            else
                wordAndPosition.put(words[i],wordAndPosition.get(words[i])+1);
        }
        List<Integer> res=new ArrayList<>();
        if(words.length==0)
            return res;
        int len=words[0].length();
        //外层只需要遍历len次
        for(int i=0;i<len;i++){
            for(int j=i,sLen=s.length();j<sLen;j+=len){
                //首次出现的下标
                int index=Integer.MAX_VALUE;
                //越界了，退出
                if(j+len>s.length())
                    break;
                String  currentStr = s.substring(j, j + len);
                //找不到当前单词,往右滑动
                if(wordAndPosition.get(currentStr)==null)
                    continue;
                //可以找得到当前单词，判断当前一连串单词是否存在
                int count=0;
                //克隆一份HashMap
                HashMap<String,Integer> cloneMap=new HashMap<>();
                cloneMap.putAll(wordAndPosition);
                for(int k=j;k<sLen;k+=len){

                    //越界了，退出
                    if(k+len>s.length())
                        break;
                    currentStr = s.substring(k, k + len);
                    if(j<index)
                        index=j;
                    //找不到，退出
                    if(cloneMap.get(currentStr)==null)
                        break;
                    //即使是重复元素，数量小于1即退出
                    if(cloneMap.get(currentStr)<1)
                        break;
                    //修正Map中的数量
                    cloneMap.put(currentStr,cloneMap.get(currentStr)-1);
                    count++;
                    //找到了，退出循环
                    if(count==words.length){
                        res.add(index);
                        break;
                    }

                }
            }
        }
        return res;
    }

    public static void main(String[]args){
        SubstringWithConcatenationOfAllWords test=new SubstringWithConcatenationOfAllWords();
        //String[]words={"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};
        //String s="pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
        /*

       String s="wordgoodgoodgoodbestword";
        String[]words={"word","good","best","good"};
        */
        /*实现HashMap的克隆
        HashMap<String,Integer> map1=new HashMap<>();
        map1.put("one",1);
        HashMap<String,Integer> mapclone=new HashMap<>();
        mapclone.putAll(map1);
        mapclone.put("one",2);
        System.out.print(map1);
        System.out.print(mapclone);
        */
        String s="abcbac";
        String[]words={"a","b","c","b"};
        System.out.print(test.findSubstring(s,words));
    }
}
