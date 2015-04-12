#include <iostream>
#include <fstream>
#include <sstream>

#include "MenuUtils.cpp"

using namespace std;

enum eMenu{
	mEnd = -1,
	mMain = 0,
	mIostream = 1,
	mFstream = 2,
	mSstring = 3,
	mIostream_Echo = 11,
	mFstream_new = 21,
	mFstream_Read = 22,
	mFstream_Append = 23,
	mSstring_Echo = 31,
	mSstring_Int = 32
};
static const string seperator = "=> \n";

class Dumper{
private:
	MenuUtils mUtils;
	string str_menu_main,str_menu_iostream,str_menu_fstream,str_menu_sstream;

	string menu_main(){
			mUtils.clear();
			mUtils.addPair("0","showMain").addPair("1","iostream")
				.addPair("2","fstream").addPair("3","stringstream")
				.addPair("-1","end");
		 	return mUtils.toString();

	}

	string menu_iostream(){
			mUtils.clear();
			mUtils.addPair("11","echo");

			return mUtils.toString();
	}

	string menu_fstream(){
			mUtils.clear();
			mUtils.addPair("21","newFile").addPair("22","readFile")
				.addPair("23","appendFile");

			return mUtils.toString();
	}

	string menu_sstream(){
			mUtils.clear();
			mUtils.addPair("31","echo").addPair("32","int <-> string");

			return   mUtils.toString();	
	}

	void mIostream_Echo_fun(){
		string str;
		
		do{
			cin>>str;
			cout<<"you say : "<<str<<endl;
		}while(str != "exit");

		cout<<"you say : exit \n";
	}

	void fileName(string &name){
		cout<<"input the filename"<<endl;
		cin>>name;
	}

	void fileName(string &name,const string msg){
		cout<<msg<<endl;
		cin>>name;
	}

	void mFstream_new_fun(){
		string name;
		fileName(name,"input the filename to create");

		ofstream os;
		os.open(name.c_str(),fstream::out);

		string value;

		do{
			cin>>value;
			os<<value<<"\n";
		}while(value!="exit");

		cout<<"you had finish!!!\n";
	}

	void mFstream_Read_fun(){
		string name;
		fileName(name,"input the filename to open");

		ifstream is;
		is.open(name.c_str(),fstream::in);
		string value;
		while(!is.eof()){
			getline(is,value);
			cout<<value<<"\n";
		}

		cout<<"you had finish!!!\n";

	}

	void mFstream_Append_fun(){
		string name;
		fileName(name,"input the filename to append");

		ofstream os;
		os.open(name.c_str(),fstream::app);
		string value;

		while(value!="exit"){
			cin>>value;
			os<<value<<"\n";
		}

		cout<<"you had finish!!!\n";
	}

	void mSstring_Echo_fun(){
		cout<<"error !!!\n";
	}

	void mSstring_Int_fun(){
		ostringstream os;
		int idx;
		string value;
		cout<<"input the integer and it's value\n";
		do{
			cin>>idx>>value;
			os<<idx<<value;
		}while(idx!=-1);

		cout<<"your input : "<<os.str()<<endl;
	}

public:
	Dumper(){
		str_menu_main = menu_main();
		str_menu_iostream = menu_iostream();
		str_menu_fstream = menu_fstream();
		str_menu_sstream = menu_sstream();
	}

	void menu(){
		int m;
		cout<<str_menu_main<<seperator<<ends;
		cin>>m;

		while(m != mEnd && !cin.fail()){
			switch(m){
				case mMain :
					cout<<str_menu_main<<seperator<<ends;
				break;

				case mIostream :
					cout<<str_menu_iostream<<seperator<<ends;
				break;

				case mFstream :
					cout<<str_menu_fstream<<seperator<<ends;
				break;

				case mSstring :
					cout<<str_menu_sstream<<seperator<<ends;
				break;

				case mIostream_Echo :
					mIostream_Echo_fun();
				break;

				case mFstream_new :
					mFstream_new_fun();
				break;

				case mFstream_Read :
					mFstream_Read_fun();
				break;

				case mFstream_Append :
					mFstream_Append_fun();
				break;

				case mSstring_Echo :
					mSstring_Echo_fun();
				break;

				case mSstring_Int :
					mSstring_Int_fun();
				break;

				default:
					cerr<<"wrong input"<<endl;
			}
			cin>>m;
		}

		if(!cin.fail())
			cout<<"You had aready exit~~~~"<<endl;
		else
			cout<<"Error input!!!!"<<endl;

	}
};

int main(){
	Dumper dumper;
	dumper.menu();
}