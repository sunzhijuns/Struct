//
// Created by sunzhijun on 18-2-19.
//

#ifndef STRUCT_STRING_H
#define STRUCT_STRING_H
#include<iostream>
#include <cstring>

namespace structures{
//    using namespace std;
    using std::ostream;
    using std::istream;
    using std::iostream;
    using std::cout;
    using std::endl;
    class String
    {
    public:
        String(const char* str=NULL);   //普通构造函数
        String(const String &other);     //拷贝构造函数
        String & operator=(const String &other);  //赋值函数
        ~String(void);                  //析构函数
    public:
        int length() { return strlen(m_string); }
        String & operator+(const String &str);  //改变本身的相加
        friend ostream& operator<<(ostream&out,String& s);
        friend istream& operator>>(iostream&in,String& s);
    private:
        char *m_string ;              //保存字符串
    };
    String::~String(void)
    {
        cout<<"destrcut"<<endl;
        if(m_string!=NULL)                   //不为空，就释放内存
        {
            delete [] m_string;
            m_string = NULL;
        }
    }

    String::String(const char* str)    //普通构造函数
    {
        cout<<"construct"<<endl;
        if(str==NULL)        //如果str 为NULL，就存一个空字符串“”
        {
            m_string=new char[1];
            *m_string ='\0';
        }
        else
        {
            m_string = new char[strlen(str)+1] ;   //分配空间
            strcpy(m_string,str);
        }
    }

    String::String(const String& other)   //拷贝构造函数
    {
        cout<<"copy construct"<<endl;
        m_string=new char[strlen(other.m_string)+1] ; //分配空间并拷贝
        strcpy(m_string,other.m_string);
    }

    String & String::operator=(const String & other)
    {
        cout<<"operator = funtion"<<endl ;
        if(this==&other) //如果对象和other是用一个对象，直接返回本身
        {
            return *this;
        }
        delete []m_string; //先释放原来的内存
        m_string = new char[strlen(other.m_string)+1];
        strcpy(m_string,other.m_string);
        return * this;
    }

    String & String::operator+ (const String & str)
    {
        char * temp=m_string;
        m_string=new char[strlen(m_string)+strlen(str.m_string)+1];
        strcpy(m_string,temp);
        delete[]temp;
        strcat(m_string,str.m_string);
        return *this;
    }

    ostream& operator<<(ostream& out,String& s)
    {
        for(int i=0;i<strlen(s.m_string);i++)
            out<<s.m_string[i]<<"";
        return out;
    }
//
//    istream& operator>>(istream& in,String& s)
//    {
//        char p[50];
//        in.getline(p,50);
//        s=p;
//        return in;
//    }


}
#endif //STRUCT_STRING_H
