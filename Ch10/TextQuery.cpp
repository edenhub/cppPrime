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
		if(!fis.good()) return;
		string line;
		while(!fis.eof()){
			getline(fis,line);
			texts.push_back(line);
		}
	}

	void parseWords(){
		if(!fis.good()) return;

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
			// cout<<test.substr(front,reer);
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
		if(!fis.good()) return false;
		parseLines();
		parseWords();
		
		vector<string>::iterator vIter = texts.begin();
		while(vIter!=texts.end()){
			cout<<*vIter<<endl;
			vIter++;
		}
		map<string,int>::const_iterator mIter = word2Nums.begin();


		while(mIter!=word2Nums.end()){
			cout<<mIter->first<<" : "<<mIter->second<<endl;
			mIter++;
		}
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

			map<string,int>::const_iterator numIter= word2Nums.find(str);

			if(numIter != word2Nums.end()){
				map<string,set<int> >::iterator linesIter = word2Lines.find(str);
				cout<<"nums : "<<numIter->second<<endl;
				// set<int> nums = *(linesIter->second);
				// set<int>::const_iterator lineIter = nums.begin();
				// while(lineIter != linesIter->end()){
				// 	cout<<lineIter<<end;
				// 	lineIter++;
				// }

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