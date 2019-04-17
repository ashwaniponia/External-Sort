#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;


void reader(){
ifstream obj;
obj.open("numbers.txt");

int totalsize=500;
int size=100;
int ar[size];
int n=totalsize/size;

ofstream o[n];
for(int i=0;i<n;i++){
string s="f";
stringstream ss;
ss<<i;
s=s+ss.str()+".txt";

o[i].open(s);

for(int j=0;j<size;j++){
obj>>ar[j];
}

sort(ar,ar+size);

for(int j=0;j<size;j++){
o[i]<<ar[j]<<endl;
}

o[i].close();
}

obj.close();


priority_queue< pii, vector<pii>,greater<pii> >pq;

ifstream oo[n];
for(int i=0;i<n;i++){
string s="f";
stringstream ss;
ss<<i;
s=s+ss.str()+".txt";
oo[i].open(s);
int data;
oo[i]>>data;
pq.push(make_pair(data,i));
}

ofstream op;
op.open("sorted.txt");

while(!pq.empty()){
pii p=pq.top();
pq.pop();

if(!oo[p.second].eof())
{
  pii q;
  op<<p.first<<endl;
  oo[p.second]>>q.first;
  q.second=p.second;
  cout<<p.first<<endl;
  pq.push(q);
  }
}
for(int i=0;i<n;i++){
oo[i].close();
}
op.close();

}

int main(){

reader();

return 0;
}
