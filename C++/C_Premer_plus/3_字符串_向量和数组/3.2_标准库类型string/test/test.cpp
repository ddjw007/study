#include <iostream>

using namespace std;

int main()
{
    /*
    //读写string对象
    string s;       //默认初始化，空字符串
    cin >> s;       //读取string对象
    cout << s << endl;  //输出s
    return 0;
    */

//    //读取未知数量的string对象 不按ctrl+c就不会停
//    string word;
//    while (cin >> word)      //反复读取，直至到达文件末尾
//    {
//         cout << word << endl;   //逐个输出单词，每个单词后面紧跟一个换行
//    }
//    return 0;

    /*getline的用法*/
    // string line;
    // //每次读入一整行，直至到达文件末尾
    // while (getline(cin,line))
    // {
    //     //因为line中不包含换行符，所以手动加上换行符。
    //     cout << line << endl;
    //     return 0;
    // }

    /*string的empty和size操作*/
    //每次读入一整行，遇到空行直接跳过
    // string line;
    // while (getline(cin,line))
    // {
    //     if (line.size() > 80)
    //     {
    //         cout << line << endl;
    //         cout << line.size() << endl;
    //     }

    //     return 0;
        
    // }
////////////////////////////////////////////////////
    /*
    *使用范围for语句和ispunct函数来统计string对象中标点符号的个数
    *
    */
//    string s("Hello World!!!");
//    //decltype()返回操作数的数据类型
//    decltype(s.size()) punct_cnt = 0;
//    //统计s中的标点符号的数量
//    for (auto c : s)     //对于s中的每个字符
//    {
//     if (ispunct(c))     //如果该字符是标点符号
//         ++punct_cnt;    //将标点符号的计数值加1
//    }

//    cout << punct_cnt << " "<< "punctuation characters in" << " " << s << endl;

//    return 0;
////////////////////////////////////////////////////    
    /*
    *使用范围for语句改变字符串中的字符
    *
    */
//    string s("Hello World!!!");
//    //统计s中的标点符号的数量
//    //分析一下，这里为什么要&引用，因为这个c是每次跌打后的s的字符值，每次迭代后就会发生变化。所以，如果不把c和s绑定在一起的话，每次大写的C下一次就换成下一个c了。如果引用c的话，就可以实现&c与s每次迭代字符的绑定，c变，s的字符也变的效果了。
//    for (auto &c : s)     //对于s中的每个字符
//    {
//         c = toupper(c);
//    }

//    cout << s << endl;

//    return 0;  
////////////////////////////////////////////////////
    


    
    
   
    

}