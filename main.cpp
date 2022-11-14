#include "ConcatStringTree.h"

void mytc(){
    ConcatStringTree s1("this_is_");
    ConcatStringTree s2("my_basic_test");
    ConcatStringTree s3 = s1.concat(s2);
    cout<<"begin basic testcase 1"<<endl;
    cout<<"s1: "<<s1.toString()<<endl;
    cout<<"s2: "<<s2.toString()<<endl;
    cout<<"s3: "<<s3.toString()<<endl;
    cout<<"s1 length: "<<s1.length()<<endl;
    cout<<"s2 length: "<<s2.length()<<endl;
    cout<<"s3 length: "<<s3.length()<<endl;
    cout<<"in s1 'i' at index: "<< s1.indexOf('i')<<endl;
    cout<<"in s2 'a' at index: "<< s2.indexOf('a')<<endl;
    cout<<"in s3 'a' at index: "<< s3.indexOf('a')<<endl;
    cout<<"in s1 at index 4 is '"<<s1.get(4)<<"'"<<endl;
    cout<<"in s2 at index 6 is '"<<s2.get(6)<<"'"<<endl;
    cout<<"in s3 at index 10 is '"<<s3.get(10)<<"'"<<endl;
    cout<<" s1 preorder: "<<s1.toStringPreOrder()<<endl;
    cout<<" s2 preorder: "<<s2.toStringPreOrder()<<endl;
    cout<<" s3 preorder: "<<s3.toStringPreOrder()<<endl;
    cout<<"-----------"<<endl;
    ConcatStringTree abc("abc");
    ConcatStringTree def("def");
    ConcatStringTree ghi("ghi");
    ConcatStringTree jkl("jkl");
    ConcatStringTree abcdef = abc.concat(def);
    ConcatStringTree ghijkl = ghi.concat(jkl);
    ConcatStringTree abcdefghijkl = abcdef.concat(ghijkl);
    ConcatStringTree ab = abcdefghijkl.subString(0,2);
    ConcatStringTree kl = abcdefghijkl.subString(10,12);
    ConcatStringTree bcdefghi = abcdefghijkl.subString(1,9);
    cout<<"begin basic testcase 2"<<endl;
    cout<<abcdefghijkl.toString()<<endl;
    cout<<ab.toString()<<endl;
    cout<<kl.toString()<<endl;
    cout<<bcdefghi.toString()<<endl;
    cout<<"----"<<endl;
    cout<<abcdefghijkl.toStringPreOrder()<<endl;
    cout<<ab.toStringPreOrder()<<endl;
    cout<<kl.toStringPreOrder()<<endl;
    cout<<bcdefghi.toStringPreOrder()<<endl;
}
void mytc2(){
    HashConfig config(13,2.4,3.3,0.75,1.75,4);
    LitStringHash *hash = new LitStringHash(config);
    ReducedConcatStringTree *s1 = new ReducedConcatStringTree("hello_",hash);
    ReducedConcatStringTree *s2 = new ReducedConcatStringTree("there",hash);
    ReducedConcatStringTree *s3 = new ReducedConcatStringTree(s1->concat(*s2));
    ReducedConcatStringTree *s4 = new ReducedConcatStringTree(s3->subString(0,2));
    ReducedConcatStringTree *s5 = new ReducedConcatStringTree("t_",hash);
    ReducedConcatStringTree *s6 = new ReducedConcatStringTree(s4->concat(*s5));
    ReducedConcatStringTree *s7 = new ReducedConcatStringTree(s6->concat(*s4));
    ReducedConcatStringTree *s8 = new ReducedConcatStringTree("_lai_sang_thu",hash);
    ReducedConcatStringTree *s9 = new ReducedConcatStringTree(s1->reverse());
    ReducedConcatStringTree *s10= new ReducedConcatStringTree(s3->reverse());
    ReducedConcatStringTree *s11 = new ReducedConcatStringTree(s7->concat(*s8));
    cout<<hash->toString()<<endl;
    delete s1;
    cout<<s3->getParTreeStringPreOrder("L")<<endl;
    delete s5;
    cout<<s11->toString()<<endl;
    delete s3;
    cout<<hash->toString()<<endl;
    delete s9;
    cout<<s10->toStringPreOrder();
    delete hash;
    delete s2;
    delete s4;
    delete s6;
    delete s7;
    delete s8;
    delete s11;
    cout<<endl<<"end tc"<<endl;
}
int main() {
    mytc();
    cout<<"\n------------------------------------";

    return 0;
}