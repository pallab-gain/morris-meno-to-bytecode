/*		
 *      ID : pallab81
 *      PROG : A1.cpp
 *      LANG : C++
 *      2010-07-14
 *      
 *      "I have not failed, I have just found 10000 ways that won't work.
 */
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <functional>
#include <bitset>

#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>
 
using namespace std;

#define  CL( x ) scanf( "%d", &x )
#define CLL( x ) scanf( "%I64d", &x )
#define  CF( x ) scanf( "%f",&x)
#define CFF( x ) scanf( "%lf",&x)

#define BT bitset<4> 
#define VI vector<int>
#define VVI vector<VI >
#define VS vector<string>
#define VC vector<char>
#define VVC vector<VC >
#define VB vector<bool>
#define VVB vector<VB >
#define PAIR pair<int,int>
#define PAIR_ pair<string,string>
#define VP vector<PAIR>
#define fo(i,st,ed) for(int i = st; i < ed ; ++i)
#define foE(i,st,ed) for(int i = st; i <= ed ; ++i)
#define foRE(i,st,ed) for(int i = ed; i >= st; --i)
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define L_P list<PAIR >
#define bip char ch;\
      ch = getchar() ;

#define msg1 C("*******************************************************************","\n")
#define msg2 C("******* DO YOU LIKE TO WRITE YOUR ASSEMBLY LANGUAGE PROGRAM  ******","\n")
#define msg3 C("** PLEASE PRESS [ Y/y ] FOR YES OR ANY OTHER CHARACTER TO ESCAPE **","\n")
#define msg4 C("***********  WRITE YOUR ASSEMBLY LANGUAGE PROGRAM  ****************","\n")

#define debug1( x ) cout<<"\033[22;31mCODE LINE : "<<__LINE__<<" \n\nERROR IN FILE LINE : "<<x<<"\n\nPLEASE CHECK YOUR ORG ADDRESSING TYPE AGAIN !!!\033[22;32m\n";
#define debug2( x ) cout<<"\033[22;31mCODE LINE : "<<__LINE__<<" \n\nERROR IN FILE LINE : "<<x<<"\n\nPLEASE CHECK YOUR LEVEL FORMAT IS CORRECT !!!\033[22;31m\n";
#define debug3( x ) cout<<"\033[22;31mCODE LINE : "<<__LINE__<<" \n\nERROR IN FILE LINE : "<<x<<"\n\nUNRECOGNISED LINE OF CODES, PLEASE CHECK AGAIN !!!\033[22;31m\n";
#define debug4( x ) cout<<"\033[22;31mCODE LINE : "<<__LINE__<<" \n\nERROR IN FILE LINE : "<<x<<"\n\nPLEASE CHECK COMMENT CONVENSION!!!\033[22;31m\n";
#define debug5( x ) cout<<"\033[22;31mCODE LINE : "<<__LINE__<<" \n\nERROR IN FILE LINE : "<<x<<"\n\nDUBLICATE SYMBOLS...PLEASE USE UNIQUE SYMBOLS !!!\033[22;31m\n";
#define debug6( x ) cout<<"\033[22;31mCODE LINE : "<<__LINE__<<" \n\nERROR IN FILE LINE : "<<x<<"\n\nPLEASE CHOOSE PROPER MRI/NON-MRI INPUT CONVENTION !!!\033[22;31m\n";
#define debug7( x ) cout<<"\033[22;31mCODE LINE : "<<__LINE__<<" \n\nERROR IN FILE LINE : "<<x<<"\n\nNO SUCH ADDRESS SYMBOL EXIST, PLEASE CHECK YOUR CODE !!!\033[22;31m\n";
#define debug8( x ) cout<<"\033[22;31mCODE LINE : "<<__LINE__<<" \n\nERROR IN FILE LINE : "<<x<<"\n\nMEMORY BLOCK HAS ALREADY USED , PLEASE CHECK YOUR CODE !!!\033[22;31m\n";

#define IO1 ifstream fin1("MRI") ,fin2("NON_MRI"),fin3("IN_OUT"), /*this fin4 will take the input from file*/ fin4("CODE");
#define IO2 ofstream fout1("CODE")/*this fout1 will write the code to the file*/;//cout("OUTPUT6")/*when writng code commented it out*/ ;

#define C(x,y) cout<<(x)<<(y);
#define mk make_pair
#define f first
#define s second
#define toBuff( x ) x.c_str()
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()

IO1
IO2

//template<class T> inline void C(T x, T y){ cout<<x<<" "<<y;}

struct node{
	string instruction_symbol;
	string to_brunch;
	string indirect;
	node(  string b="",string c="",string d="") : instruction_symbol(b),to_brunch(c),indirect(d){}
};
//________________________________________
//GLOBAL VARIABLE DECLARATION START
const int hx = 16;
bool allOk,willProcess;
string input;
int location_counter;
int last_address; // NEED FOR ADDRESS SYMBOL... 
map<string, pair<string,string> >mri_table;
map<string,string> non_mri_table, io_table;

map<int,node> MAPPER_BOX;
map<string,int> address_symbols;
//_______________________________________
//GLOBAL VARIABLE DECLARATION END

//_________________________________________________________
//MRI, NON-MRI, IO COLLECTION FROM INPUT FILE BEGIN
inline void MRI_COLLECT(){
	
	mri_table.clear();
	for( ; getline(fin1,input) ; ){
		stringstream str( input );string a,b,c;
		str>>a>>b>>c;
		mri_table[ a ] = mk( b,c );
	}
	
return ;
}
inline void NON_MRI_COLLECT(){
	
	non_mri_table.clear();
	for( ; getline(fin2,input) ; ){
		stringstream str( input ); string a,b;
		str>>a>>b;
		non_mri_table[ a ] = b;
	}
return ;	
}
inline void IO_COLLECT(){
	
	io_table.clear();
	for( ; getline(fin3,input) ; ){
		stringstream str(input);string a,b;
		str>>a>>b;
		io_table[ a ] = b;
	}
return ;
}
//__________________________________________________
//MRI, NON-MRI, IO COLLECTION FROM INPUT FILE END

//_________________________________
//CHECKING TYPE PATTERN START
inline bool isMRI(string ss){
	return ( mri_table.find(ss)!=mri_table.end() ? true : false ) ;
}
inline bool isNMRI(string ss){
	return ( non_mri_table.find(ss) !=non_mri_table.end() ? true : false );
}
inline bool isIO(string ss){
	return ( io_table.find(ss) != io_table.end() ? true : false );
}
inline bool isD_H(string ss){
	return (ss=="DEC" || ss=="HEX");
}
inline bool isPASS(string s1,string s2){

	if(s1=="DEC"){
		fo(i,0,LN(s2)){
			if(s2[0]=='-')continue;
			if( !(s2[i]>='0' && s2[i]<='9') )return false;
		}
		return true;
	}
	else{
		fo(i,0,LN(s2)){
			if(s2[0]=='-')return false;
			if(s2[i]>='0' && s2[i]<='9')continue;
			if(s2[i]>='A' && s2[i]<='F')continue;
			return false;
		}
	return true;
	}
return true;
}
inline bool isLEVEL(string ss){
	if(ss[0]==',')return false;
	if( LN( ss) > 4 || LN( ss ) < 2 )return false;
	return ( ss[ LN( ss ) -1 ]== ',' ? true : false ) ;
}
inline bool isORG(string ss){
	return (ss=="ORG");
}
inline bool isEND(string ss){
	return (ss=="END");
}
inline bool isHALT(string ss){
	return (ss=="HALT");
}
inline bool isINDIRECT(string ss){
	return (ss=="I");
}
inline bool isCOMMENT(string ss){
	return (ss[0]=='/');
}
inline string toS(char c[] ){
	return string(c);
}
inline bool isEmpty(string ss){
	return (ss=="");
}
inline bool isGood(string ss){
	fo( i,0,LN(ss) ){
		if( (ss[i]>='0' && ss[i]<='9') || (ss[i]>='A' && ss[i]<='F') ){
			continue;
		}
		return false;
	}
return true;
}
inline bool isAlready(string ss){
	return ( address_symbols.find( ss ) != address_symbols.end() ) ;
}
inline bool isPresent(string ss){
	ss+=',';
	return (isAlready(ss));
}
inline bool isAlreadyOccuppppied(int value){
	return ( MAPPER_BOX.find(value)!= MAPPER_BOX.end());
}
//__________________________
//CHECKING TYPE PATTERN END


//__________________________
//ALL TYPE OF CONVERTION FUNCTION START

inline void IOmyUniversal__CLS(){
	fprintf(stdout, "\033[2J");	fprintf(stdout, "\033[1;1H"); 
return ;	    
}

inline int toInt(string ss){
	return atoi( ss.c_str() );
}
inline string decimal_to_binary(int ss){
	string res="";
		bitset<16> bt = (unsigned long)ss;
		foRE(i,0,15)res+= bt[i]?'1':'0';
return res;		
}
inline int binary_to_decimal(string ss){
	fo(i,LN(ss),16)ss='0'+ss;
	
	int res=0,j=0;
	foRE(i,0,15){
		res+= (ss[i]=='0'? 0 : (1<<j));
		j++;
	}
	return res;
}
inline string hex_to_binary(string ss){
	fo(i,LN(ss),4)ss='0'+ss;
	BT b1 = isdigit(ss[0])?ss[0] : ss[0]-'A'+10; 
	BT b2 = isdigit(ss[1])?ss[1] : ss[1]-'A'+10; 
	BT b3 = isdigit(ss[2])?ss[2] : ss[2]-'A'+10; 
	BT b4 = isdigit(ss[3])?ss[3] : ss[3]-'A'+10; 
	string res="";
	foRE(i,0,3)res+= b1[i]?'1':'0';
	foRE(i,0,3)res+= b2[i]?'1':'0';
	foRE(i,0,3)res+= b3[i]?'1':'0';
	foRE(i,0,3)res+= b4[i]?'1':'0';
	
return res;	
}
inline int hex_to_decimal(string ss){
	string binary_value = hex_to_binary(ss);
return binary_to_decimal(binary_value);
}
inline string decimal_to_hex(int decimal_value){
	string indx="0123456789ABCDEF";
	string res="";
	for( ; ;){
		res = indx[decimal_value%16] + res;
		decimal_value/=16;
		if(decimal_value<=0)break;
	}
return res;
}

//_________________________
//ALL TYPE OF CONVERTION FUNCTION START END

//_______________________________________________
//COLOR BLOCKS START
inline void color(int col){
	switch(col){
		case 1 : printf("\033[22;31m"); return ; //red
		case 2 : printf("\033[22;30m"); return ; //black
		case 3 : printf("\033[22;32m"); return ; //green
		case 4 : printf("\033[22;33m"); return ; //brown
		case 5 : printf("\033[22;34m"); return ; //blue
		case 6 : printf("\033[22;35m"); return ; //magenta
		case 7 : printf("\033[22;36m"); return ; // cyan
		case 8 : printf("\033[22;37m"); return ; //gray
		case 9 : printf("\033[01;30m"); return ; //dark gray
		case 10: printf("\033[01;31m"); return ; //light red
		case 11: printf("\033[01;32m"); return ; //light green
		case 12: printf("\033[01;33m"); return ; // yellow
		case 13: printf("\033[01;34m"); return ; //light blue
		case 14: printf("\033[01;35m"); return ; //light magenta
		case 15: printf("\033[01;36m"); return ; //light cyan
		case 16: printf("\033[01;37m"); return ;// white
	}
	return ;
}
//COLOR BLOCKS END
//_______________________________________________


//___________________________________________________________
//GET THE SYMBOLIC ASSEMBLY PROGRAM FROM FILE START
//WITH FIRST PASS 

inline void SYMBOL_CODE_COLLECT(){
	address_symbols.clear();
	location_counter=0;
	string instruction_symbol,to_brunch,indirect;
	char a[30],b[30],c[30],d[30];
	
	for(int i = 1; getline(fin4, input); i++){
		memset(a,'\0',sizeof(a));
		memset(b,'\0',sizeof(b));
		memset(c,'\0',sizeof(c));
		memset(d,'\0',sizeof(d));
		instruction_symbol=to_brunch=indirect="";
		string p,q,r,s;	
		sscanf( input.c_str(), "%s %s %s %s", a,b,c,d);
		p=toS(a);q=toS(b);r=toS(c);s=toS(d);
		
		if( (isEmpty(p) && isEmpty(q) && isEmpty(r) && isEmpty(s)) || (isCOMMENT(p)) ) {
			//IF EMPTY LINE OF CODE THEN JUST IGNORE AND CONTINUE
			// NO NEED TO INCREMENT THE LOCATION COUNTER. [:D:]
			continue; 
		}
		
		if(isAlreadyOccuppppied(location_counter)){
			debug8(i);
			allOk=false;
			return ;
		}
		else if( isORG(p) ){
			if( isGood(q) ){
				if( !isEmpty(r) && !isCOMMENT(r) ){
						debug4(i)
						allOk=false;
						return ;
				}
				location_counter = hex_to_decimal( q );
				MAPPER_BOX[ location_counter-1 ] = node( p, "", "" );
			}
			else{
				debug1(i)
				allOk=false;
				return ;
			}
		}
		else if(isD_H(p)){
			if( isPASS(p,q) && ( isCOMMENT(r) || isEmpty(r) ) ){
					// SUCCESSFUL PASS
					// THIS IS A VARIABLE
					address_symbols[ p ] = location_counter;
					MAPPER_BOX[ location_counter ] = node(p,q,"");
					
				}
				else{
					debug2(i)
					allOk=false;
					return ;
				}
			location_counter++;
		}
		else if( isLEVEL(p) ){
			if( isAlready(p) ){
				debug5(i)
				allOk=false;
				return ;
			}
			if( isMRI(q) || isNMRI(q) || isIO(q) ){
				//cout<<i<<": "<<p<<"__"<<q<<"__"<<r<<"__"<<s;bip
				if( isMRI(q) && ( (LN(r) >=1 && LN(r)<=3 ) && (isINDIRECT(s) || isEmpty(s) || isCOMMENT(s) ))){
					// SUCCESSFUL PASS
					// THIS IS A BUN LOOP
					address_symbols[ p ] = location_counter ;
					MAPPER_BOX[ location_counter ] = node( q, r, s);
					//location_counter++;
				}
				else if( (isNMRI(q) ||isIO(q) ) && (isINDIRECT(r) || isEmpty(r) || isCOMMENT(r))){
					address_symbols[ p ] = location_counter;
					MAPPER_BOX[ location_counter ] = node( q, r, s);
					//location_counter++;					
				}
				else{
					debug2(i)
					allOk=false;
					return ;
				}
			}
			else if( isD_H(q) ){
				if( isPASS(q,r) && ( isCOMMENT(s) || isEmpty(s) ) ){
					// SUCCESSFUL PASS
					// THIS IS A VARIABLE
					address_symbols[ p ] = location_counter;
					MAPPER_BOX[ location_counter ] = node(q,r,"");
					//location_counter++;
				}
				else{
					debug2(i)
					allOk=false;
					return ;
				}
			}
			else{
				debug2(i)
				allOk=false;
				return ;
			}
			location_counter++;
		}
		else if( isEND(p) ){
				if( !isEmpty(q) && !isCOMMENT(q) ){
						debug2(i)
						allOk=false;
						return ;
				}
			MAPPER_BOX[ location_counter ] = node(p,"","");
			location_counter++;
			last_address=location_counter;
			return ;
		}
		else if( isHALT(p) ){
			//JUST INCREASE THE LOCATION COUNTER
			//IF PASS IS OK
				if( !isEmpty(q) && !isCOMMENT(q) ){
						debug2(i)
						allOk=false;
						return ;
				}
				MAPPER_BOX[ location_counter ] = node(p,"","");
			location_counter++;
		}
		else if( isNMRI(p) || isMRI(p) ){
			if( isMRI(p) ){
				if( (LN(q)>=1 && LN(q)<=3 ) && (isINDIRECT(r)) && ( isEmpty(s) || isCOMMENT(s)) ) {
					MAPPER_BOX[ location_counter] = node( p, q, r);
				}
				else if( (LN(q)>=1 && LN(q)<=3 ) && ( isEmpty(r) || isCOMMENT(r)) ) {
					MAPPER_BOX[ location_counter] = node( p, q, "");
				}
				else{
					debug6(i)
					allOk=false;
					return ;
				}
			}
			
			else if( isNMRI(p) ){
				if( isEmpty(q) || isCOMMENT(q) ){
					MAPPER_BOX[ location_counter] = node(p,"","");
				}
				else{
					debug6(i)
					allOk=false;
					return ;
				}
			}
			location_counter++;
		}
		else if( isIO(p) ){
			//cout<<i<<" "<<p<<" location counter : "<<location_counter<<"\n";
			if( isCOMMENT(q) || isEmpty(q) ){
				MAPPER_BOX[ location_counter ] = node( p, "", "" );
			}
			else{
				debug6(i)
				allOk=false;
				return ;
			}
			location_counter++;
			//cout<<i<<" "<<p<<" location counter : "<<location_counter;bip
			
		}
		else{			
				debug3(i);
				allOk=false;
				return ;
			
		}
	
	}
return ;
}
//__________________________________________________
//GET THE SYMBOLIC ASSEMBLY PROGRAM FROM FILE END
//________________________________________
//ADDRESS SYMBOL TABLE PRINT START
inline string mk_form(string ss){
	string tmp=ss.substr(0,LN(ss)-1);
	fo(i,LN(tmp),3)tmp+=' ';
	tmp+=',';
return tmp;	
}
inline void P(char ch){
	string ss="";ss+=ch;
	BT b1 = isdigit(ss[0])?ss[0] : ss[0]-'A'+10; 
	C(b1," ");
return ;
}
inline void PRINT(string ss, int value){
	//cout<<"__"<<value<<"__\n";
	//C("h\t\t","(LC)")
	C("" "\t\t","(LC)")
	///char ch[20];
	//sprintf(ch,"%d",value);
	//string hex=toS(ch);
	string hex = ss;
	fo(i,LN(hex),4)hex='0'+hex;
	C("\t     ",hex[0])C(hex[1],' ')C(hex[2],hex[3])
	cout<<"\t     ";P(hex[0]);P(hex[1]);P(hex[2]);P(hex[3]);
	cout<<"|\n";
	
return ;
}

inline void DO_PRINT_FIRST_PASS(){
	if(!allOk)return ;
	C("==========================+FIRST PASS+===========================","\n")
	C("============================+START+==============================","\n\n")
	vector<pair<int,string> > vp;
	int d1,d2,d3,d4;
	string x1,x2,x3,x4;
	foit(it,address_symbols){
		//cout<<(*it).s<<" "<<(*it).f<<"\n";
		vp.pb( mk( (*it).s,(*it).f ) );
	}
	sort(vp.begin(),vp.end() );
	//fo(i,0,SZ(vp)){cout<<vp[i].f<<" "<<vp[i].s<<"\n";}
	cout<<"MEMORY_WORD"<<"\t"<<"SYMBOL"<<"\t"<<"  HEXADECIMAL_CODE"<<'\t'<<"BIN._REPRESENTATION\n";
	C("__________________________________________________________________","\n")
	C("|                                                                |","\n")
	fo(i,0,SZ(vp)){
		if(isD_H(vp[i].s))continue;
		string symbol = mk_form(vp[i].s);
		d1 = (int)symbol[0];d2=(int)symbol[1];
		d3 = (int)symbol[2];d4=(int)symbol[3];
		x1 = decimal_to_hex(d1);x2 = decimal_to_hex(d2);
		x3 = decimal_to_hex(d3);x4 = decimal_to_hex(d4);
		C("|","")
		C(" ",decimal_to_hex(last_address))last_address++;
		//C("h\t\t ",symbol[0])C(' ',symbol[1])C("\t     ",x1)C(' ',x2)
		C("" "\t\t ",symbol[0])C(' ',symbol[1])C("\t     ",x1)C(' ',x2)
		cout<<"\t     ";P(x1[0]);P(x1[1]);P(x2[0]);P(x2[1]);cout<<"|\n";
		
		C("|","")
		C(" ",decimal_to_hex(last_address))last_address++;
		//C("h\t\t ",symbol[2])C(' ',symbol[3])C("\t     ",x3)C(' ',x4)
		C("" "\t\t ",symbol[2])C(' ',symbol[3])C("\t     ",x3)C(' ',x4)
		cout<<"\t     ";P(x3[0]);P(x3[1]);P(x4[0]);P(x4[1]);cout<<"|\n";
	
		//LOCATION COUNTER (LC) WILL PLACE HERE
		C("|","")
		C(" ",decimal_to_hex(last_address))last_address++;
		string ss = decimal_to_hex(vp[i].f);
		//cout<<"\n"<<ss<<"\n";
		PRINT( ss,vp[i].f );
		
	}

	C("|                                                                |","\n")
	C("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~","")
	C("\n","\n")
	C("===========================+FIRST PASS+============================","\n")
	C("==============================+END+================================","\n\n")
return ;
}
//________________________________________
//ADDRESS SYMBOL TABLE PRINT END

//_________________________________________
//SECOND PASS STARTED

inline string print_address(int value){
	return decimal_to_hex(value);
}
inline void do_non_mri_io(string ss){
	C(ss,"\t\t")
	string rs = hex_to_binary(ss);
	C(rs.substr(0,4)," ")	C(rs.substr(4,4)," ")
	C(rs.substr(8,4),' ')	C(rs.substr(12,4),' ')
	return ;
}
inline void show_binary_for_decimal_IO(string value){
	string b = decimal_to_binary(toInt(value));
	int tmp	= binary_to_decimal( b );
	string hex_value = decimal_to_hex(tmp);
	fo(i,LN(hex_value),4)cout<<'0';
	C(hex_value," ")C("\t\t","")	
	C(b.substr(0,4),' ');C(b.substr(4,4),' ')C(b.substr(8,4),' ');C(b.substr(12,4),' ');
return ;	
}
inline void show_binary_for_hex_IO(string value){

	fo(i,LN(value),4)cout<<'0';
	C("",value)	C("","\t\t")
	string b = hex_to_binary(value);
	C(b.substr(0,4),' ');C(b.substr(4,4),' ')C(b.substr(8,4),' ');C(b.substr(12,4),' ');
return ;	
}
inline void showMRI_WITH_NO_I(string instruction_symbol, string toBun){
	string value = mri_table[ instruction_symbol ].f;
	
	BT b1 = value[0];toBun+=',';
	int value_ = address_symbols[toBun];
	string to_hex = decimal_to_hex(value_);
	fo(i,LN(to_hex),3)to_hex='0'+to_hex;
	C(to_hex,"\t\t\t")
	C(value,to_hex)
	
	BT b2=to_hex[0],b3=to_hex[1],b4=to_hex[2];
	cout<<"\t\t"<<b1<<' '<<b2<<' '<<b3<<' '<<b4<<' ';
	return ;
}
inline void showMRI_WITH_I(string instruction_symbol,string toBun){
	string value = mri_table[instruction_symbol].s;
	BT b1 = isdigit(value[0])?value[0] : value[0]-'A'+10; toBun+=',';
	int value_ = address_symbols[toBun];
	string to_hex = decimal_to_hex(value_);
	fo(i,LN(to_hex),3)to_hex='0'+to_hex;
	C(to_hex," I")
	C("\t\t",value)C(to_hex,"\t\t")
	BT b2=to_hex[0],b3=to_hex[1],b4=to_hex[2];
	cout<<b1<<' '<<b2<<' '<<b3<<' '<<b4<<' ';
return ;
}

inline void DO_PRINT_SECOND_PASS(){
	if(!allOk)return ;
	C("\n","\n")
	C("================================+SECOND PASS+================================","\n")
	C("==================================+START+====================================","\n\n\n")
	
	string instruction_symbol,to_brunch,indirect;
	int k=1;
	cout<<"LOCATION"<<"     SYM."<<"INSTRUTION"<<"\t  "<<"CONTENT_IN_HEXA."<<"\t"<<"BIN._REPRESENTATION\n";
	C("____________________________________________________________________________","\n")
	C("|                                                                           |","\n")
	foit(it,MAPPER_BOX){
		int address_ = (*it).f;
		instruction_symbol = (*it).s.instruction_symbol;
		to_brunch			 = (*it).s.to_brunch;
		indirect				 = (*it).s.indirect;
		if(isORG(instruction_symbol))continue;
		
		if(isEND(instruction_symbol)){
			break;
		}
		C("| ","")
		//IF U LIKE IT OR NOW !
		//C(print_address(address_),"h\t\t");
		C(print_address(address_),"" "\t\t");
		//THIS 'h' WILL CHANGE THE OUTPUT LOOK FORMAT
		if( isNMRI(instruction_symbol) || isIO(instruction_symbol) ){
			C(instruction_symbol,"\t\t\t")
			//do_non_mri_io(non_mri_table[instruction_symbol]);
			do_non_mri_io ( isIO(instruction_symbol) ==true ? io_table[ instruction_symbol ] : non_mri_table[ instruction_symbol ]);
		}
		else if( isD_H(instruction_symbol) ){
			if(instruction_symbol=="DEC"){
				C(to_brunch,"d\t\t\t")
				show_binary_for_decimal_IO(to_brunch);
			}
			else{
				fo(i,LN(to_brunch),4)C('0',"")
				C(to_brunch,"h\t\t\t")
				show_binary_for_hex_IO(to_brunch);
			}
		}
		else{
			C(instruction_symbol," ")
			if(isEmpty(indirect)){
				if(isPresent(to_brunch)){ // IS ADDRESS SYMBOL IS PRESENT
					showMRI_WITH_NO_I(instruction_symbol,to_brunch);
				}
				else{
					C("\n\n\n","");
					debug7( k );
					allOk=false;
					return ;
				}
			}
			else{
				if(isPresent(to_brunch)){
					showMRI_WITH_I(instruction_symbol,to_brunch);
				}
				else{
					C("\n\n\n","");
					debug7( k );
					allOk=false;
					return ;
				}
			}
		}
		
		k++;
		cout<<"|\n";
	}
	C("|                                                                           |","\n")
	C("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~","\n\n")
	C("================================+SECOND PASS+================================","\n")
	C("===================================+END+=====================================","\n\n")
	return ;
}
//_________________________________________
//SECOND PASS END

inline void IOgreet(){
	C("\n\n\n","");	msg1 msg1 C("******************************THANK YOU****************************","\n") msg1 msg1
	return ;
}

inline void run_process(){
	allOk=true;
	//willProcess=true;
	if(!willProcess){
		IOmyUniversal__CLS();
		color(1);
		C("\nYOU DID NOT WRITE ANY CODE... PLEASE TRY AGAIN LATER...\n","");
		color(7);
		IOgreet();
		color(16);
		return ;
	}
	color(3);
	MRI_COLLECT();NON_MRI_COLLECT();IO_COLLECT();	
	SYMBOL_CODE_COLLECT();
	DO_PRINT_FIRST_PASS();
	DO_PRINT_SECOND_PASS();	
	color(16);
return ;	
}

//**********************************************************************
//IO PART START FROM HERE

inline bool IOchecker(){
	char ch; C("\n\n\nPLEASE TYPE YOUR CHOICE "," : ") cin>>ch;
	return ( tolower(ch)=='y' ? true : false );
}

inline bool IOisDone(string ss){
	stringstream st(ss);string tmp;st>>tmp;
	return (tmp=="END" ? true : false ) ;
}

inline void IOinput(){
	string ss;getline(cin,ss);
	C("\t","\t");
	fout1<<"\t\t";
	while(getline(cin,ss)){
		C("\t","");
		fout1<<ss<<"\n";
		if(IOisDone(ss))break;
	}
	fout1.close();
	IOmyUniversal__CLS();
	color(2);
	return ;
}

inline void io_main(){
	color(5); //5 7 13 
	msg1; msg2 msg3 msg1 msg1 
	willProcess=false;	//IF THIS WILL REMAIN FALSE THAT  MEAN THE CODER DONT GIVE ANY INPUT
	if(!IOchecker()){
		IOmyUniversal__CLS();
		IOgreet();
	}
	else{
		willProcess=true;color(9);
		IOmyUniversal__CLS();C("YOUR SCREEN \n\n\n","");
		color(13);IOinput();
	}
return ;
}

//**********************************************************************
//IO PART ENDS FHERE


int main(){
	io_main();
	run_process();
return 0;	
}
