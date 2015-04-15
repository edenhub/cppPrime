#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>

using namespace std;

class TextQuery{
private:
	string fileName;
	vector<string> texts;
	map<string,set<int> > word2Lines;
	map<string,int> word2Nums;
	ifstream fis;

	bool isChar(char &ch){
		if(('a'<=ch && ch<='z') || ('A'<=ch && ch<='Z') )
			return true;
		else
			return false; 
	}

	void openFile(string &fileName){
		fis.open(fileName.c_str());
	}

	void parseLines(){
		if(!fis) return;
		string line;
		while(!fis.eof()){
			getline(fis,line);
			texts.push_back(line);
		}
	}

	void parseWords(){
		if(!fis) return;
		vector<string>::const_iterator lineIter = texts.begin();

		while(lineIter!=texts.end()){
			string test = *lineIter;
			int front=0,reer = 0,len = test.length();

			for(int i=0;i<len;i++){
				if(!isChar(test[i])){
					reer = i;
					if(isChar(test[front])){
						string word = test.substr(front,reer-front);
						word2Nums[word]++;
						word2Lines[word].insert(i);
					}

						// cout<<test.substr(front,reer-front)<<endl;
					front = reer+1;
				}
				string word = test.substr(front,reer-front);
				word2Nums[word]++;
				word2Lines[word].insert(i);
			}
			lineIter++;
		}
	}

	void closeFile(){
		fis.close();
	}

public:
	TextQuery(){}
	TextQuery(string &fileName){
		this->fileName = fileName;
	}

	bool buildData(){
		if(!fis) return false;
		parseLines();
		parseWords();
		map<string,int>::const_iterator mIter = word2Nums.begin();

		cout<<"finish buildData"<<endl;
	}

	bool init(){
		cout<<"input the filename you want to open : "<<endl;
		cin>>fileName;
		openFile(fileName);
		cout<<"you had open file : "<<fileName<<endl;
		buildData();
	}

	void work(string flag="exit"){
		init();

		string str;

		do{
			cout<<"input the word you want to search : "<<endl;
			cin>>str;

			int exitNums = word2Nums.count(str);

			if(exitNums == 1){
				cout<<"nums : "<<word2Nums[str]<<endl;
				set<int> nos = word2Lines[str];
				set<int>::iterator nosIter = nos.begin();
				while(nosIter!=nos.end()){
					cout<<*nosIter<<" : "<<texts[*nosIter]<<endl;

					nosIter++;
				}
			}

		}while(str != flag);

		close();
	}

	bool close(){
		closeFile();
		cout<<"end~~~"<<endl;
	}
};



int main(){

	TextQuery textQuery;
	textQuery.work();

	
	return 0;
}