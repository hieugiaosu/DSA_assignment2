#include "ConcatStringTree.h"
void bkel1(){
    ConcatStringTree s1("acbbcab");
    cout << s1.length() << endl;
    cout << s1.get(1) << endl;
    try {
        cout << "char at index 10: " << s1.get(10) << endl;
    }
    catch (const out_of_range & ofr) {
        cout << "Exception out_of_range: " << ofr.what() << endl;
    }
    cout << s1.indexOf('b') << endl;
}
void bkel2(){
    ConcatStringTree s1("Hello");
    ConcatStringTree s2(",_t");
    ConcatStringTree s3 = s1.concat(s2);
    cout << s3.toStringPreOrder() << endl;
    cout << s3.toString() << endl;
    cout << s3.subString(5, 6).toString() << endl;
    cout << s3.reverse().toString() << endl;
}
void bkel3(){
    ConcatStringTree * s1 = new ConcatStringTree("a");
    ConcatStringTree * s2 = new ConcatStringTree("b");
    ConcatStringTree * s3 = new ConcatStringTree(s1->concat(*s2));

    cout << s3->getParTreeSize("l") << endl;
    cout << s3->getParTreeStringPreOrder("l") << endl;

    delete s1;
    delete s2;
    delete s3;
}
void bkel4(){
    HashConfig hashConfig(
        2,
        0.5,
        0.5,
        0.75,
        2,
        4
    );
    LitStringHash * litStringHash = new LitStringHash(hashConfig);
    ReducedConcatStringTree * s1 = new ReducedConcatStringTree("a", litStringHash);
    ReducedConcatStringTree * s2 = new ReducedConcatStringTree("bb", litStringHash);

    cout << s1->toString() << endl;
    cout << s2->toString() << endl;
    ReducedConcatStringTree * s3 = new ReducedConcatStringTree("bb", litStringHash);

    cout << litStringHash->getLastInsertedIndex() << endl;
    cout << litStringHash->toString() << endl;
    ReducedConcatStringTree *s4 = new ReducedConcatStringTree("vcl",litStringHash);
    ReducedConcatStringTree *s5 = new ReducedConcatStringTree("ac",litStringHash);
    cout << litStringHash->toString() << endl;
    delete litStringHash;
    delete s5;
    delete s4;
    delete s3;
    delete s1;
    delete s2;
}
void bkel5(){
     ConcatStringTree s1("Hello");
    cout << "Please focus to id: " << s1.getParTreeStringPreOrder("") << endl;
    ConcatStringTree s2("an-nyeong-ha-se-yo");
    cout << "Please focus to id: " << s2.getParTreeStringPreOrder("") << endl;
    ConcatStringTree s3("nee how");
    cout << "Please focus to id: " << s3.getParTreeStringPreOrder("") << endl;
}
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
    ConcatStringTree daivcl = abcdefghijkl.reverse();
    cout<<"begin basic testcase 2"<<endl;
    cout<<daivcl.toStringPreOrder()<<endl;
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
    cout<<s1->toStringPreOrder()<<endl;
    cout<<s2->toStringPreOrder()<<endl;
    cout<<s3->toStringPreOrder()<<endl;
    cout<<s4->toStringPreOrder()<<endl;
    cout<<s5->toStringPreOrder()<<endl;
    cout<<s6->toStringPreOrder()<<endl;
    cout<<s7->toStringPreOrder()<<endl;
    cout<<s8->toStringPreOrder()<<endl;
    cout<<s9->toStringPreOrder()<<endl;
    cout<<s10->toStringPreOrder()<<endl;
    cout<<s11->toStringPreOrder()<<endl;
    delete s1;
    cout<<s3->getParTreeStringPreOrder("l")<<endl;
    delete s5;
    cout<<s11->toString()<<endl;
    cout<<s11->toStringPreOrder()<<endl;
    delete s3;
    cout<<hash->toString()<<endl;
    cout<<"pass (1) \n";
    delete s9;
        cout<<"pass (2) \n";
    cout<<s10->toStringPreOrder()<<endl;
    // delete hash;
cout<<"pass (3) \n";
    delete s2;
    cout<<"pass (4) \n";
    delete s4;
    cout<<"pass (5) \n";
    delete s6;
    cout<<"pass (6) \n";
    delete s7;
    cout<<"pass (7) \n";
    delete s8;
    cout<<"pass (8) \n";
    cout<<s11->toString()<<endl;
    delete s11;
    cout<<"pass (9) \n";
    delete s10;
    cout<<endl<<"end tc"<<endl;
    delete hash;
}
void tcParentsTree() {
    ConcatStringTree sA("ABC"), sB("DEF"), sC("GHI");
    ConcatStringTree s1 = sA.concat(sB);
    ConcatStringTree s2 = sB.concat(sC);
    ConcatStringTree s3 = s1.concat(s2);
    cout << sA.getParTreeStringPreOrder("") << '\n'; // ParentsTree[(id=1);(id=4)]
    cout << sB.getParTreeStringPreOrder("") << '\n'; // ParentsTree[(id=4);(id=2);(id=5)]
    cout << sC.getParTreeStringPreOrder("") << '\n'; // ParentsTree[(id=3);(id=5)]
    cout << s1.getParTreeStringPreOrder("") << '\n'; // ParentsTree[(id=4);(id=6)]
    cout << s2.getParTreeStringPreOrder("") << '\n'; // ParentsTree[(id=5);(id=6)]
    cout << s3.getParTreeStringPreOrder("") << endl; // ParentsTree[(id=6)]

    ConcatStringTree s4 = s1.concat(s3); // ABCDEFABCDEFDEFGHI
    ConcatStringTree s5 = s4.concat(s2); // ABCDEFABCDEFDEFGHIDEFGHI
    ConcatStringTree s6 = s3.concat(s5); // ABCDEFDEFGHIABCDEFABCDEFDEFGHIDEFGHI
    ConcatStringTree s7 = s1.concat(s2);
    cout << s6.toString() << " " << s6.length() << endl; // ConcatStringTree["ABCDEFDEFGHIABCDEFABCDEFDEFGHIDEFGHI"] 36
    cout << s1.getParTreeStringPreOrder("") << endl; // ParentsTree[(id=6);(id=4);(id=7);(id=10)]
    cout << s2.getParTreeStringPreOrder("") << endl; // ParentsTree[(id=6);(id=5);(id=8);(id=10)]
    cout << s3.getParTreeStringPreOrder("") << endl; // ParentsTree[(id=7);(id=6);(id=9)]
    cout << s4.getParTreeStringPreOrder("") << endl; // ParentsTree[(id=7);(id=8)]
    cout << s5.getParTreeStringPreOrder("") << endl; // ParentsTree[(id=8);(id=9)]
    cout << s6.getParTreeStringPreOrder("") << endl; // ParentsTree[(id=9)]
    cout << s7.getParTreeStringPreOrder("") << endl; // ParentsTree[(id=10)]

    ConcatStringTree s8 = s3.subString(1, s3.length()-1);
    ConcatStringTree s9 = s3.reverse();
    cout << s8.toString() << " " << s8.length() << endl; // ConcatStringTree["BCDEFDEFGH"] 10
    cout << s9.toString() << " " << s9.length() << endl; // ConcatStringTree["IHGFEDFEDCBA"] 12
}
void mytc3(){
    ConcatStringTree *s1 = new ConcatStringTree("hello_");
    ConcatStringTree *s2 = new ConcatStringTree("there");
    ConcatStringTree *s3 = new ConcatStringTree(s1->concat(*s2));
    ConcatStringTree *s4 = new ConcatStringTree(s3->subString(0,2));
    ConcatStringTree *s5 = new ConcatStringTree("t_");
    ConcatStringTree *s6 = new ConcatStringTree(s4->concat(*s5));
    ConcatStringTree *s7 = new ConcatStringTree(s6->concat(*s4));
    ConcatStringTree *s8 = new ConcatStringTree("_lai_sang_thu");
    ConcatStringTree *s9 = new ConcatStringTree(s1->reverse());
    ConcatStringTree *s10= new ConcatStringTree(s3->reverse());
    ConcatStringTree *s11 = new ConcatStringTree(s7->concat(*s8));cout<<s1->toStringPreOrder()<<endl;
    cout<<s2->toStringPreOrder()<<endl;
    cout<<s3->toStringPreOrder()<<endl;
    cout<<s4->toStringPreOrder()<<endl;
    cout<<s5->toStringPreOrder()<<endl;
    cout<<s6->toStringPreOrder()<<endl;
    cout<<s7->toStringPreOrder()<<endl;
    cout<<s8->toStringPreOrder()<<endl;
    cout<<s9->toStringPreOrder()<<endl;
    cout<<s10->toStringPreOrder()<<endl;
    cout<<s11->toStringPreOrder()<<endl;
    delete s1;
    cout<<s3->getParTreeStringPreOrder("l")<<endl;
    delete s5;
    cout<<s11->toString()<<endl;
    cout<<s11->toStringPreOrder()<<endl;
    delete s3;
    cout<<"pass (1) \n";
    delete s9;
        cout<<"pass (2) \n";
    cout<<s10->toStringPreOrder()<<endl;
    // delete hash;
    cout<<"pass (3) \n";
    delete s2;
    cout<<"pass (4) \n";
    delete s4;
    cout<<"pass (5) \n";
    delete s6;
    cout<<"pass (6) \n";
    delete s7;
    cout<<"pass (7) \n";
    delete s8;
    cout<<"pass (8) \n";
    cout<<s11->toString()<<endl;
    delete s11;
    cout<<"pass (9) \n";
    delete s10;
    cout<<endl<<"end tc"<<endl;
}
void Hieutc4() {
    HashConfig config(37, 3*1e6, 3.141592654, 0.6, 2.1, 11);

    LitStringHash * hash = new LitStringHash(config);
    ReducedConcatStringTree * s1 = new ReducedConcatStringTree("Hello_I_am_HCMUT_students._",hash);
    cout<<hash->toString()<<endl << endl;
    ReducedConcatStringTree * s2 = new ReducedConcatStringTree("I_Really_Love_my_Schools",hash);
    cout<<hash->toString()<<endl << endl;
    ReducedConcatStringTree * s3 = new ReducedConcatStringTree("I_Found_",hash);
    cout<<hash->toString()<<endl << endl;
    ReducedConcatStringTree * s4 = new ReducedConcatStringTree("DSA_is_easy",hash);
    cout<<hash->toString()<<endl << endl;
    ReducedConcatStringTree * s5 = new ReducedConcatStringTree("_",hash);
    cout<<hash->toString()<<endl << endl;
    ReducedConcatStringTree * s6 = new ReducedConcatStringTree("ALL_Thing",hash);
    cout<<hash->toString()<<endl << endl;
    cout<<"before rehash"<<endl;
    ReducedConcatStringTree * s7 = new ReducedConcatStringTree("I_said",hash);
    ReducedConcatStringTree * s8 = new ReducedConcatStringTree("is_a_joke",hash);
    
    ReducedConcatStringTree * s9 = new ReducedConcatStringTree(s1->concat(*s2));
    ReducedConcatStringTree * s10 = new ReducedConcatStringTree(s3->concat(*s4));
    ReducedConcatStringTree * s11 = new ReducedConcatStringTree(s9->concat(*s10));
    cout<<hash->toString()<<endl;
    delete s1;
    cout<<"pass (1)"<<endl;
    delete s2;
    cout<<"pass (2)"<<endl;
    delete s3;
    cout<<"pass (3)"<<endl;
    delete s4;
    cout<<"pass (4)"<<endl;
    delete s5;
    cout<<"pass (5)"<<endl;
    delete s6;
    cout<<"pass (6)"<<endl;
    delete s7;
    cout<<"pass (7)"<<endl;
    delete s8;
    cout<<"pass (8)"<<endl;
    delete s9;
    cout<<"pass (9)"<<endl;
    delete s10;
    cout<<"pass (10)"<<endl;
    delete s11;
    cout<<"pass (11)"<<endl;
    delete hash;
    cout<<"finish"<<endl;
}
int main() {
    try{
    Hieutc4();
    } catch(runtime_error &of) {
        cout<< of.what() <<endl;
    }
    cout<<"\n------------------------------------"<<endl;

    return 0;
}