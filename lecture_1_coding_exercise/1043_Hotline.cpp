#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
using namespace std;
int T,N;
bool ERR;
struct Event{
	bool is;
	string pre,obj;
	Event(bool is=false,string pre="",string obj=""):is(is),pre(pre),obj(obj){}
	bool operator < (const Event & O)const{
		if(is!=O.is)	return is<O.is;
		if(pre!=O.pre)	return pre<O.pre;
		return obj<O.obj;
	}
	bool operator == (const Event & Q)const{
		return is==Q.is && pre==Q.pre && obj==Q.obj; 
	}
};
map<string,vector<Event> > peo;
map<Event,vector<string> > eve;
vector<Event> mus;
map<Event,bool> muss;
map<Event,int> dfn;
char buf[110];
Event lis[110];
vector<string> Sen;
void Cuts(){
	Sen.clear();Sen.push_back("");
	int len=0;
	for(int i=0;buf[i] && buf[i]!='\r';i++){
		if(buf[i]==' '){
			if(Sen[len]!="")	Sen.push_back(""),++len;
		}
		else{
			if(buf[i]=='.' || buf[i]=='?' || buf[i]=='!'){
				if(Sen[len]!="")	Sen.push_back(""),++len;
			}
			Sen[len]+=buf[i];
		}
	}
}
bool cmp(Event & A,Event & B){
	return dfn[A]<dfn[B];
}
int main(){
	scanf("%d",&T);
	for(int L=1;L<=T;L++){
		if(L!=1)	printf("\n");
		printf("Dialogue #%d:\n",L);
		peo.clear();eve.clear();
		mus.clear();dfn.clear();muss.clear();
		ERR=false;N=0;
		while(scanf(" %[^\n]s",buf)!=EOF){
			Cuts();
			int Ln=Sen.size();
			if(Sen[Ln-1]=="!"){
				printf("%s",buf);
				break;
			}
			else if(Sen[Ln-1]=="."){
				bool is=true;
				int pre=1;
				if(Sen[1]=="don\'t" || Sen[1]=="doesn\'t")	++pre,is=false;
				if(Sen[0]!="I" && Sen[0]!="you" && is)	Sen[pre]=Sen[pre].substr(0,Sen[pre].size()-1);
				if(Sen[0]=="nobody")	Sen[0]="everybody",is^=1;
				string obj;
				for(int i=pre+1;i<Ln-1;i++)	obj=obj+Sen[i]+" "[i==Ln-2];
				Event meaning=Event(is,Sen[pre],obj);
				dfn[meaning]=++N;
				if(Sen[0]=="everybody")	mus.push_back(meaning),muss[meaning]=true;
				else{
					peo[Sen[0]].push_back(meaning);
					eve[meaning].push_back(Sen[0]);
				}
				if(Sen[0]!="everybody"){	
					vector<Event> che=peo[Sen[0]];
					for(int i=0,j=che.size();i<j;i++)
						if(che[i]==Event(!is,Sen[pre],obj))	ERR=true;
					for(int i=0,j=mus.size();i<j;i++)
						if(mus[i]==Event(!is,Sen[pre],obj))	ERR=true;
				}
				else{
					ERR|=(eve[Event(!is,Sen[pre],obj)].size()!=0);
					ERR|=muss[Event(!is,Sen[pre],obj)]; 
				}
			}
			else{
				printf("%s\n",buf);
				if(ERR)	printf("I am abroad.\n"); 
				else if(Sen[0]=="do" || Sen[0]=="does"){
					string sub,pre,obj="";
					int is=2;bool s=false;
					sub=Sen[1];
					if(sub=="I")	sub="you";
					else if(sub=="you")	sub="I";
					if(Sen[0]=="does")	s=true;
					vector<Event> che=peo[Sen[1]];
					pre=Sen[2];
					for(int i=3;i<Ln-1;i++)	obj=obj+Sen[i]+" "[i==Ln-2];
					for(int i=0,j=che.size();i<j;i++){
						if(che[i]==Event(true,pre,obj))	is=1;
						if(che[i]==Event(false,pre,obj))	is=0;
					}
					for(int i=0,j=mus.size();i<j;i++){
						if(mus[i]==Event(true,pre,obj))	is=1;
						if(mus[i]==Event(false,pre,obj))	is=0;
					}
					if(is==1){
						printf("yes, %s %s",sub.c_str(),pre.c_str());
						if(s)	printf("s");
						if(obj!="")	printf(" %s",obj.c_str());
						printf(".\n\n");
					}
					else if(is==0){
						printf("no, %s ",sub.c_str());
						if(s)	printf("doesn\'t ");
						else	printf("don\'t ");
						printf("%s",pre.c_str());
						if(obj!="")	printf(" %s",obj.c_str());
						printf(".\n\n");
					}
					else	printf("maybe.\n\n");
				}
				else if(Sen[0]=="who"){
					string pre=Sen[1].substr(0,Sen[1].size()-1),obj="";
					for(int i=2;i<Ln-1;i++)	obj=obj+Sen[i]+" "[i==Ln-2];
					vector<string> ask=eve[Event(1,pre,obj)];
					bool nob=muss[Event(0,pre,obj)],ery=muss[Event(1,pre,obj)];
					if(ask.size()==0 && !nob && !ery)	printf("I don\'t know.\n\n");
					else if(nob){
						printf("nobody %ss",pre.c_str());
						if(obj!="")	printf(" %s",obj.c_str());
						printf(".\n\n");
					}
					else if(ery){
						printf("everybody %ss",pre.c_str());
						if(obj!="")	printf(" %s",obj.c_str());
						printf(".\n\n");
					}
					else if(ask.size()==1){
						if(ask[0]=="I"){
							printf("you %s",pre.c_str());
							if(obj!="")	printf(" %s",obj.c_str());
							printf(".\n\n");
						}
						else if(ask[0]=="you"){
							printf("I %s",pre.c_str());
							if(obj!="")	printf(" %s",obj.c_str());
							printf(".\n\n");
						}
						else{
							printf("%s %ss",ask[0].c_str(),pre.c_str());
							if(obj!="")	printf(" %s",obj.c_str());
							printf(".\n\n");
						}
					}
					else{
						for(int i=0,j=ask.size();i<j;i++){
							if(ask[i]=="I")	printf("you");
							else if(ask[i]=="you")	printf("I");
							else printf("%s",ask[i].c_str());
							if(i==j-1)	break;
							if(i==j-2)	printf(" and ");
							else	printf(", ");
						}
						printf(" %s",pre.c_str());
						if(obj!="")	printf(" %s",obj.c_str());
						printf(".\n\n");
					}
				}
				else{
					vector<Event> ret=peo[Sen[2]];
					bool s=(Sen[2]!="I" && Sen[2]!="you");
					for(int i=0,j=mus.size();i<j;i++)
						ret.push_back(mus[i]);
					int LL=ret.size();
					for(int i=0;i<LL;i++)	lis[i]=ret[i];
					sort(lis,lis+LL,cmp);
					if(LL==0)	printf("I don\'n know.\n\n");
					else{
						if(Sen[2]=="I")	printf("you ");
						else if(Sen[2]=="you")	printf("I ");
						else	printf("%s ",Sen[2].c_str());
						for(int i=0;i<LL;i++){
							if(!lis[i].is){
								if(s)	printf("doesn\'t ");
								else	printf("don\'t ");
							}
							printf("%s",lis[i].pre.c_str());
							if(lis[i].is && s)	printf("s");
							if(lis[i].obj!="")	printf(" %s",lis[i].obj.c_str());
							if(i==LL-1)	break;
							if(i==LL-2)	printf(", and ");
							else	printf(", ");
						}
						printf(".\n\n");
					}
				}
			}
			memset(buf,0,sizeof(buf));
		}
	}
	return 0;
}